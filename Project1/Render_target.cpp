// レンダーターゲット制御クラス

#include "Render_target.h"
#include <cassert>

// デストラクタ
Render_target::~Render_target() 
{
    // レンダーターゲットリソースの解放
    for (auto& rt : renderTargets_) 
    {
        if (rt) 
        {
            rt->Release();
            rt = nullptr;
        }
    }
    renderTargets_.clear();
}

// バックバッファを生成する
// デバイスクラスのインスタンス
// スワップチェインのポインタ
// ディスクリプターヒープのインスタンス
// 生成の成否

[[nodiscard]] bool Render_target::createBackBuffer(const Device& device, const Swap_chain& swapChain, const DescriptorHeap& heap) noexcept {
    // スワップチェインの設定を取得
    const auto& desc = swapChain.getDesc();

    // レンダーターゲットリソースのサイズを設定
    renderTargets_.resize(desc.BufferCount);

    // ディスクリプターヒープのハンドルを取得
    auto handle = heap.get()->GetCPUDescriptorHandleForHeapStart();

    // ディスクリプターヒープのタイプを取得
    auto heapType = heap.getType();
    assert(heapType == D3D12_DESCRIPTOR_HEAP_TYPE_RTV && "ディスクリプタヒープのタイプが RTV ではありません");

    // バックバッファの生成
    for (uint8_t i = 0; i < desc.BufferCount; ++i) 
    {
        const auto hr = swapChain.get()->GetBuffer(i, IID_PPV_ARGS(&renderTargets_[i]));
        if (FAILED(hr)) 
        {
            assert(false && "バックバッファの取得に失敗しました");
            return false;
        }

        // レンダーターゲットビューを作成してディスクリプタヒープのハンドルと関連付ける
        device.get()->CreateRenderTargetView(renderTargets_[i], nullptr, handle);

        // 次のハンドルへ移動
        handle.ptr += device.get()->GetDescriptorHandleIncrementSize(heapType);
    }

    return true;
}

// ビュー（ディスクリプタハンドル）を取得する
// ディスクリプタヒープのインスタンス
// インデックス
// ディスクリプタハンドル

[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE Render_target::getDescriptorHandle(const Device& device, const DescriptorHeap& heap, UINT index) const noexcept {

    if (index >= renderTargets_.size() || !renderTargets_[index]) 
    {
        assert(false && "不正なレンダーターゲットです");
    }

    // ディスクリプタヒープのハンドルを取得
    auto handle = heap.get()->GetCPUDescriptorHandleForHeapStart();

    // ディスクリプタヒープのタイプを取得
    auto heapType = heap.getType();
    assert(heapType == D3D12_DESCRIPTOR_HEAP_TYPE_RTV && "ディスクリプタヒープのタイプが RTV ではありません");

    // インデックスに応じてハンドルを移動
    handle.ptr += index * device.get()->GetDescriptorHandleIncrementSize(heapType);
    return handle;
}

// レンダーターゲットを取得する
// インデックス

[[nodiscard]] ID3D12Resource* Render_target::get(uint32_t index) const noexcept 
{
    if (index >= renderTargets_.size() || !renderTargets_[index]) 
    {
        assert(false && "不正なレンダーターゲットです");
        return nullptr;
    }
    return renderTargets_[index];
}

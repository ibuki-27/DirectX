// コマンドアロケータ制御クラス

#include "Command_allocator.h"
#include <cassert>

// デストラクタ

Command_allocator::~Command_allocator()
{
    // コマンドアロケータの解放
    if (commandAllocator_) 
    {
        commandAllocator_->Release();
        commandAllocator_ = nullptr;
    }
}

// コマンドキューの生成
// デバイスクラスのインスタンス
// 成功すれば true

[[nodiscard]] bool Command_allocator::create(const Device& device, const D3D12_COMMAND_LIST_TYPE type) noexcept 
{
    // コマンドリストのタイプを設定
    type_ = type;

    // コマンドアロケータの生成
    const auto hr = device.get()->CreateCommandAllocator(type_, IID_PPV_ARGS(&commandAllocator_));
    if (FAILED(hr)) 
    {
        assert(false && "コマンドアロケータの作成に失敗しました");
        return false;
    }

    return true;
}

// コマンドアロケータをリセットする
void Command_allocator::reset() noexcept {

    if (!commandAllocator_) 
    {
        assert(false && "コマンドアロケータが未作成です");
    }

    commandAllocator_->Reset();
}

// コマンドアロケータを取得する
// コマンドアロケータのポインタ

[[nodiscard]] ID3D12CommandAllocator* Command_allocator::get() const noexcept 
{
    if (!commandAllocator_) 
    {
        assert(false && "コマンドアロケータが未作成です");
        return nullptr;
    }
    return commandAllocator_;
}

// コマンドリストのタイプを取得する
// コマンドリストのタイプ

[[nodiscard]] D3D12_COMMAND_LIST_TYPE Command_allocator::getType() const noexcept 
{
    if (!commandAllocator_) 
    {
        assert(false && "コマンドリストのタイプが未設定です");
    }
    return type_;
}

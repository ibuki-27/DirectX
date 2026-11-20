// コマンドリスト制御クラス

#include "Command_list.h"
#include <cassert>

// デストラクタ

Command_list::~Command_list()
{
    // コマンドリストの解放
    if (commandList_) 
    {
        commandList_->Release();
        commandList_ = nullptr;
    }
}

// コマンドリスト作成
// デバイスクラスのインスタンス
// コマンドアロケータクラスのインスタンス
// 生成の成否

[[nodiscard]] bool Command_list::create(const Device& device, const Command_allocator& commandAllocator) noexcept 
{
    // コマンドリストの作成
    const auto hr = device.get()->CreateCommandList(0, commandAllocator.getType(), commandAllocator.get(), nullptr, IID_PPV_ARGS(&commandList_));
    if (FAILED(hr)) 
    {
        assert(false && "コマンドリストの作成に失敗しました");
        return false;
    }

    // コマンドリストを初期化状態に設定
    commandList_->Close();
    return true;
}

// コマンドリストのリセット
// コマンドアロケータクラスのインスタンス

void Command_list::reset(const Command_allocator& commandAllocator) noexcept 
{
    if (!commandList_) 
    {
        assert(false && "コマンドリストが未作成です");
    }

    // コマンドリストをリセット
    commandList_->Reset(commandAllocator.get(), nullptr);
}

// コマンドリストを取得する
// コマンドリストのポインタ

[[nodiscard]] ID3D12GraphicsCommandList* Command_list::get() const noexcept 
{
    if (!commandList_) 
    {
        assert(false && "コマンドリストが未作成です");
        return nullptr;
    }
    return commandList_;
}

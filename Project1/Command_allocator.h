// コマンドアロケータ制御クラス

#pragma once

#include "Device.h"

// コマンドアロケータ制御クラス

class Command_allocator final
{
public:
	// コンストラクタ
	Command_allocator() = default;

	// デストラクタ
	~Command_allocator();

	// コマンドアロケータ作成
	// デバイスクラスのインスタンス
	// コマンドリストのタイプ

	[[nodiscard]] bool create(const Device& device, const D3D12_COMMAND_LIST_TYPE type) noexcept;

	// コマンドアロケータをリセットする

	void reset() noexcept;

	// コマンドアロケータを取得する
	// コマンドアロケータのポインタ

	[[nodiscard]] ID3D12CommandAllocator* get() const noexcept;

	// コマンドリストのタイプを取得する
	// コマンドリストのタイプ

	[[nodiscard]] D3D12_COMMAND_LIST_TYPE getType() const noexcept;

private:
	ID3D12CommandAllocator* commandAllocator_{};  /// コマンドアロケータ
	D3D12_COMMAND_LIST_TYPE type_{};              /// コマンドリストのタイプ

};


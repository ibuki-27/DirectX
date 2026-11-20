// コマンドリスト制御クラス

#pragma once

#include "Device.h"
#include "Command_allocator.h"

// コマンドリスト制御クラス

class Command_list final
{
public:
	// コンストラクタ
	Command_list() = default;

	// デストラクタ
	~Command_list();

	// コマンドリスト作成
	// デバイスクラスのインスタンス
	// コマンドアロケータクラスのインスタンス
	// 生成の成否

	[[nodiscard]] bool create(const Device& device, const Command_allocator& commandAllocator) noexcept;

	// コマンドリストのリセット
	// コマンドアロケータクラスのインスタンス

	void reset(const Command_allocator& commandAllocator) noexcept;

	// コマンドリストを取得する
	// コマンドリストのポインタ

	[[nodiscard]] ID3D12GraphicsCommandList* get() const noexcept;

private:
	ID3D12GraphicsCommandList* commandList_{};       /// コマンドリスト

};


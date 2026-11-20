// コマンドキュー制御クラス

#pragma once

#include "Device.h"

// コマンドキュー制御クラス

class Command_queue final
{
public:
	// コンストラクタ
	Command_queue() = default;

	// デストラクタ
	~Command_queue();

	// コマンドキューの生成
	// デバイスクラスのインスタンス
	// 生成の成否

	[[nodiscard]] bool create(const Device& device) noexcept;

	// コマンドキューを取得する
	// コマンドキューのポインタ

	[[nodiscard]] ID3D12CommandQueue* get() const noexcept;

private:
	ID3D12CommandQueue* commandQueue_{};  /// コマンドキュー

};


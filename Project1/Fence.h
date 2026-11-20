// フェンス（CPUとGPUの動機）制御クラス

#pragma once

#include "Device.h"

// フェンス（CPUとGPUの動機）制御クラス

class Fence final
{
public:

	// コンストラクタ
	Fence() = default;

	// デストラクタ
	~Fence();

	// フェンスを作成する

	[[nodiscard]] bool create(const Device& device) noexcept;

	// 同期待ちを行う
	// フェンス値

	void wait(UINT64 fenceValue) const noexcept;

	// フェンスを取得する

	[[nodiscard]] ID3D12Fence* get() const noexcept;

private:
	ID3D12Fence* fence_{};         /// フェンス
	HANDLE       waitGpuEvent_{};  /// GPU と CPU 同期用のイベントハンドル

};


// デバイスクラス

#pragma once

#include "DXGI.h"
#include <d3d12.h>

// デバイスクラス

class Device final
{
public:
	// コンストラクタ
	Device() = default;

	// デストラクタ
	~Device();

	// デバイスを作成する
	// DXGI クラスのインスタンス
	// 作成できた場合は true

	[[nodiscard]] bool create(const DXGI& dxgi) noexcept;

	// デバイスを取得する
	// dx12 デバイスのポインタ

	[[nodiscard]] ID3D12Device* get() const noexcept;

private:
	ID3D12Device* device_; /// デバイス
};


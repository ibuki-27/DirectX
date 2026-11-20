// DXGI 制御クラス

#pragma once

#include <d3d12.h>
#include <dxgi1_4.h>

class DXGI final
{
public:
	// コンストラクタ
	DXGI() = default;

	// デストラクタ
	~DXGI();

	// ディスプレイアダプタの設定
	// ディスプレイの情報が正しく取得できた場合は true

	[[nodiscard]] bool setDisplayAdapter() noexcept;

	// dxgi ファクトリーを取得する
	// dxgi ファクトリーのポインタ

	[[nodiscard]] IDXGIFactory4* factory() const noexcept;

	// ディスプレイアダプターを取得する
	// ディスプレイアダプターのポインタ

	[[nodiscard]] IDXGIAdapter1* displayAdapter() const noexcept;

private:
	IDXGIFactory4* dxgiFactory_{};  /// DXGIを作成するファクトリー
	IDXGIAdapter1* dxgiAdapter_{};  /// ディスプレイモード取得用アダプタ

};


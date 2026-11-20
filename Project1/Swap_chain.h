// スワップチェイン制御クラス

#pragma once

#include "DXGI.h"
#include "Command_queue.h"
#include "Window.h"

// スワップチェイン制御クラス

class Swap_chain final
{
public:
	// コンストラクタ
	Swap_chain() = default;

	// デストラクタ
	~Swap_chain();

	// スワップチェインの生成
	// dxgi クラスのインスタンス
	// ウィンドウクラスのインスタンス
	// コマンドキュークラスのインスタンス
	// 生成の成否

	[[nodiscard]] bool create(const DXGI& dxgi, const Window& window, const Command_queue& commandQueue) noexcept;

	// スワップチェインを取得する
	// スワップチェインのポインタ

	[[nodiscard]] IDXGISwapChain3* get() const noexcept;

	// スワップチェインの設定を取得する
	// スワップチェインの設定

	[[nodiscard]] const DXGI_SWAP_CHAIN_DESC1& getDesc() const noexcept;

private:
	IDXGISwapChain3* swapChain_{};      /// スワップチェイン
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc_{};  /// スワップチェインの設定

};


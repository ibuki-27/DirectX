// レンダーターゲット制御クラス

#pragma once

#include "Device.h"
#include "Swap_chain.h"
#include "Descriptorheap.h"
#include <vector>

// レンダーターゲット制御クラス

class Render_target final
{
public:

	// コンストラクタ
	Render_target() = default;

	// デストラクタ
	~Render_target();

	// バックバッファを生成する
	// デバイスクラスのインスタンス
	// スワップチェインのポインタ
	// ディスクリプターヒープのインスタンス
	// 生成の成否

	[[nodiscard]] bool createBackBuffer(const Device& device, const Swap_chain& swapChain, const DescriptorHeap& heap) noexcept;

	// ビュー（ディスクリプタハンドル）を取得する
	// デバイスクラスのインスタンス
	// ディスクリプタヒープのインスタンス
	// インデックス
	// ディスクリプタハンドル

	[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE getDescriptorHandle(const Device& device, const DescriptorHeap& heap, UINT index) const noexcept;

	// レンダーターゲットを取得する
	// インデックス

	[[nodiscard]] ID3D12Resource* get(uint32_t index) const noexcept;

private:
	std::vector<ID3D12Resource*> renderTargets_;  /// レンダーターゲットリソースの配列

};


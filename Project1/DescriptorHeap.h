// ディスクリプタヒープ制御クラス

#pragma once

#include "device.h"

// ディスクリプタヒープ制御クラス

class DescriptorHeap final
{
public:
	// コンストラクタ
	DescriptorHeap() = default;

	// デストラクタ
	~DescriptorHeap();

	 /**
     * @brief	ディスクリプタヒープを生成する
	 * @param	device	デバイスクラスのインスタンス
	 * @param	type	ディスクリプタヒープのタイプ
	 * @param	numDescriptors	ディスクリプタの数
	 * @param	shaderVisible	シェーダーからアクセス可能かどうか
	 * @return	生成の成否
     */

	[[nodiscard]] bool create(const Device& device, D3D12_DESCRIPTOR_HEAP_TYPE type, UINT numDescriptors, bool shaderVisible = false) noexcept;

	// ディスクリプタヒープを取得する
	// ディスクリプタヒープのポインタ

	[[nodiscard]] ID3D12DescriptorHeap* get() const noexcept;

	// ディスクリプタヒープのタイプを取得する
	// ディスクリプタヒープのタイプ

	[[nodiscard]] D3D12_DESCRIPTOR_HEAP_TYPE getType() const noexcept;

private:
	ID3D12DescriptorHeap* heap_{};  /// ディスクリプタヒープ
	D3D12_DESCRIPTOR_HEAP_TYPE type_{};  /// ヒープのタイプ

};


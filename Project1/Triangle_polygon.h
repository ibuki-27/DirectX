// 三角形ポリゴンクラス

#pragma once

#include "Device.h"
#include "Command_list.h"

// ポリゴンクラス

class Triangle_polygon final
{
public:
	// コンストラクタ
	Triangle_polygon() = default;

	// デストラクタ
	~Triangle_polygon();

	// ポリゴンの生成
	// デバイスクラスのインスタンス
	// 成功すれば true

	[[nodiscard]] bool create(const Device& device) noexcept;

	// ポリゴンの描画
	// コマンドリスト

	[[nodiscard]] void draw(const Command_list& commandList) noexcept;

private:
	// 頂点バッファの生成
	// デバイスクラスのインスタンス
	// 成功すればtrue
	
	[[nodiscard]] bool createVertexBuffer(const Device& device) noexcept;

	// インデックスバッファの生成
	// デバイスクラスのインスタンス
	// 成功すれば true

	[[nodiscard]] bool createIndexBuffer(const Device& device) noexcept;

private:
	ID3D12Resource* vertexBuffer_{};  /// 頂点バッファ
	ID3D12Resource* indexBuffer_{};   /// インデックスバッファ

	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_ = {};  ///< 頂点バッファビュー
	D3D12_INDEX_BUFFER_VIEW  indexBufferView_ = {};  ///< インデックスバッファビュー

};


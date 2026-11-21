// シェーダクラス

#pragma once

#include "Device.h"

// シェーダクラス

class Shader final
{
public:
	// コンストラクタ
	Shader() = default;

	// デストラクタ
	~Shader();

	// シェーダを作成する
	// デバイスクラスのインスタンス
	// 成功すれば true

	[[nodiscard]] bool create(const Device& device) noexcept;

	// 頂点シェーダを取得する
	// 頂点シェーダのデータ

	[[nodiscard]] ID3DBlob* vertexShader() const noexcept;

	// ピクセルシェーダを取得する
	// ピクセルシェーダのデータ

	[[nodiscard]] ID3DBlob* pixelShader() const noexcept;

private:
	ID3DBlob* vertexShader_{};  /// 頂点シェーダ
	ID3DBlob* pixelShader_{};   /// ピクセルシェーダ

};


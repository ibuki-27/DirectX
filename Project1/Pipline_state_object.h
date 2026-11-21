// パイプラインステートオブジェクトクラス

#pragma once

#include "Device.h"
#include "Shader.h"
#include "Root_signature.h"

// パイプラインステートオブジェクトクラス

class Pipline_state_object final
{
public:
	// コンストラクタ
	Pipline_state_object() = default;

	// デストラクタ
	~Pipline_state_object();

	// パイプラインステートオブジェクトを作成する
	// デバイスクラスのインスタンス
	// シェーダクラスのインスタンス
	// ルートシグネチャクラスのインスタンス
	// 成功すれば true

	[[nodiscard]] bool create(const Device& device, const Shader& shader, const Root_signature& rootSignature) noexcept;

	// パイプラインステートを取得する
	// パイプラインステートのポインタ

	[[nodiscard]] ID3D12PipelineState* get() const noexcept;

private:
	ID3D12PipelineState* pipelineState_ = {};  ///< パイプラインステート

};


// ルートシグネチャクラス

#pragma once

#include "Device.h"

// ルートシグネチャクラス

class Root_signature final
{
public:
	// コンストラクタ
	Root_signature() = default;

	// デストラクタ
	~Root_signature();

	// ルートシグネチャを作成する
	// デバイスクラスのインスタンス
	// 成功すれば true

	[[nodiscard]] bool create(const Device& device) noexcept;

	// ルートシグネチャを取得する
	// ルートシグネチャ

	[[nodiscard]] ID3D12RootSignature* get() const noexcept;

private:
	ID3D12RootSignature* rootSignature_{};  /// ルートシグネチャ

};


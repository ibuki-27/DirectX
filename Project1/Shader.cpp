// シェーダクラス

#include "Shader.h"
#include <cassert>
#include <string>

#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

// デストラクタ

Shader::~Shader()
{
    // 頂点シェーダの解放
    if (vertexShader_) 
    {
        vertexShader_->Release();
        vertexShader_ = nullptr;
    }
    // ピクセルシェーダの解放
    if (pixelShader_) 
    {
        pixelShader_->Release();
        pixelShader_ = nullptr;
    }
}

// シェーダを作成する
// デバイスクラスのインスタンス
// 成功すれば true

[[nodiscard]] bool Shader::create(const Device& device) noexcept 
{
    // シェーダを読込、コンパイルして生成する

    // シェーダファイルのパス
    const std::wstring vertexShaderPath = L"VertexShader.hlsl";
    const std::wstring pixelShaderPath = L"PixelShader.hlsl";    
    ID3DBlob* error{};

    auto res = D3DCompileFromFile(vertexShaderPath.c_str(), nullptr, nullptr, "vs", "vs_5_0", D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0, &vertexShader_, &error);

    if (FAILED(res))
    {
        if (error)
        {
            OutputDebugStringA(static_cast<const char*>(error->GetBufferPointer()));

            error->Release();
            error = nullptr;
        }

        OutputDebugStringA("頂点シェーダのコンパイルに失敗しました\n");
        return false;
    }

    if (error)
    {
        error->Release();
        error = nullptr;
    }

    // ピクセルシェーダのコンパイル
    res = D3DCompileFromFile(pixelShaderPath.c_str(), nullptr, nullptr, "ps", "ps_5_0", D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0, &pixelShader_, &error);

    if (FAILED(res))
    {
        if (error)
        {
            OutputDebugStringA(static_cast<const char*>(error->GetBufferPointer()));

            error->Release();
            error = nullptr;
        }

        OutputDebugStringA("ピクセルシェーダのコンパイルに失敗しました\n");
        return false;
    }

    if (error)
    {
        error->Release();
        error = nullptr;
    }

    return true;
}

// 頂点シェーダを取得する
// 頂点シェーダのデータ

[[nodiscard]] ID3DBlob* Shader::vertexShader() const noexcept 
{
    if (!vertexShader_) 
    {
        assert(false && "頂点シェーダが未作成です");
    }

    return vertexShader_;
}

// ピクセルシェーダを取得する
// ピクセルシェーダのデータ

[[nodiscard]] ID3DBlob* Shader::pixelShader() const noexcept 
{
    if (!pixelShader_) 
    {
        assert(false && "ピクセルシェーダが未作成です");
    }

    return pixelShader_;
}

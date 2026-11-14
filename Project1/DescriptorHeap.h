#pragma once

#include "device.h"

class DescriptorHeap final
{
public:
	// コンストラクタ
	DescriptorHeap() = default;

	// デストラクタ
	~DescriptorHeap();

	bool create(const Device& device, D3D12_DESCRIPTOR_HEAP_TYPE)
};


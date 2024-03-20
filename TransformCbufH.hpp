#pragma once
#include "ConstantBuffersH.hpp"
#include "DrawableH.hpp"
#include <DirectXMath.h>

class TransformCbuf : public Bindable
{
public:
	TransformCbuf(Graphics& gfx, const Drawable& parent);
	void Bind(Graphics& gfx) noexcept override;
private:
	VertexConstantBuffer<DirectX::XMMATRIX> vcbuf;
	const Drawable& parent;
};
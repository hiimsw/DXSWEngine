#pragma once

#include <memory>
#include <string>

#include "MeshResource.h"
#include "../RenederKey.h"
#include "../../../Common/DirectXMath.h"

class Mesh final
{
public:
	Mesh(const Mesh&) = delete;

	Mesh& operator=(const Mesh&) = delete;

	~Mesh();

	static inline Mesh* Create(const char* fileName, const size_t materialID)
	{
		return new Mesh(fileName, materialID);
	}

	inline const char* GetFileName() const
	{
		return mMeshResource->GetResourceName(mVertexBufferID).c_str();
	}

	inline const size_t GetMaterialID() const
	{
		return mMaterialID;
	}

	inline const DirectX::XMFLOAT3& GetPosition() const
	{
		return mPosition;
	}

	inline const DirectX::XMFLOAT3& GetScale() const
	{
		return mScale;
	}

	inline void SetMaterialID(const size_t materialID)
	{
		mMaterialID = materialID;
	}

	inline void SetPosition(const DirectX::XMFLOAT3& position)
	{
		mPosition = position;
	}

	inline void SetScale(const DirectX::XMFLOAT3& scale)
	{
		mScale = scale;
	}

public:
	// 이 함수는 엔진 내부에서만 사용되는 함수입니다.
	static void Initialize(RenederKey, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

	// 이 함수는 엔진 내부에서만 사용되는 함수입니다.
	void Draw(RenederKey);

private:
	explicit Mesh(const char* fileName, const size_t materialID);

private:
	static ID3D11Device* mDevice;

	static ID3D11DeviceContext* mDeviceContext;

	static std::unique_ptr<MeshResource> mMeshResource;

	int mVertexBufferID = 0;

	size_t mMaterialID = 0;

	DirectX::XMFLOAT3 mPosition = {};

	DirectX::XMFLOAT3 mScale = { 1.0f, 1.0f, 1.0f };
};
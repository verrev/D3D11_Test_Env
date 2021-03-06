#pragma once

#include <Windows.h>
#include <d3d11.h>
#pragma comment (lib,"d3d11.lib")

template<typename T>
void safeRelease(T obj)
{
	if (obj) obj->Release();
	obj = 0;
}

class D3D11
{
public:
	static D3D11& getInstance()
	{
		static D3D11 instance;
		return instance;
	}
	bool initialize(const UINT &width, const UINT &height, const HWND &window, const bool &windowed);
	void clearRenderTargetViews(const float &r = 0.0f, const float &g = 0.0f, const float &b = 0.0f, const float &a = 1.0f);
	void endScene();
	void destroy();
public:
	ID3D11Device *mDevice;
	ID3D11DeviceContext *mDeviceContext;
	IDXGISwapChain *mSwapChain;
	ID3D11Texture2D *mSwapChainBuffer;
	ID3D11RenderTargetView *mRenderTargetView;
public:
	UINT mWindowWidth;
	UINT mWindowHeight;
	HWND mWindow;
	bool mWindowed;
private:
	D3D11() {}
	D3D11(D3D11 const&) = delete;
	void operator=(D3D11 const&) = delete;
};
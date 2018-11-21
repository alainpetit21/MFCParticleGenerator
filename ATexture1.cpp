#include "stdafx.h"
#include "ATexture1.h"

#include <stdio.h>

CATexture::CATexture(const short& p_nWidth, const short& p_nHeight):
m_nWidth(p_nWidth), 
m_nHeight(p_nHeight)
{
	Surface= NULL;
}

CATexture::~CATexture()
{
	Surface->Release();
}

void CATexture::LoadTextureDDS(char * filename, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw)
{

}
void CATexture::LoadTexture(char * filename, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw)
{
	DDSURFACEDESC2 Desc;  
	D3DDEVICEDESC7 ddDesc;
	HBITMAP hBM;  
	BITMAP BM;  
	HDC hDCImage, hDC;
	
	ZeroMemory( &Desc, sizeof( DDSURFACEDESC2 ));  
	Desc.dwSize = sizeof( Desc );  
	Desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;  
	Desc.dwWidth = m_nWidth;  
	Desc.dwHeight = m_nHeight;  
	Desc.ddsCaps.dwCaps = DDSCAPS_TEXTURE;  

	p_D3DDevice->GetCaps(&ddDesc);

	if (ddDesc.deviceGUID==IID_IDirect3DHALDevice || ddDesc.deviceGUID==IID_IDirect3DTnLHalDevice)
		Desc.ddsCaps.dwCaps2=DDSCAPS2_TEXTUREMANAGE;
	else
		Desc.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;

	if (ddDesc.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_POW2 )
	{
		for (Desc.dwWidth=1; m_nWidth > Desc.dwWidth; Desc.dwWidth<<= 1);
		for (Desc.dwHeight=1; m_nHeight > Desc.dwHeight; Desc.dwHeight<<= 1);
	}

	if (ddDesc.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_SQUAREONLY)
	{
		if (Desc.dwWidth > Desc.dwHeight)
			Desc.dwHeight= Desc.dwWidth;
		else
			Desc.dwWidth=  Desc.dwHeight;
	}

	p_DirectDraw->CreateSurface(&Desc, &Surface, NULL);
	Surface->Restore();

	if(!(hBM = (HBITMAP) LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION)))
		exit(10);
	
	GetObject(hBM, sizeof(BM), &BM);  
	
	hDCImage = CreateCompatibleDC(NULL);  
	SelectObject(hDCImage, hBM);  
	
	if(!SUCCEEDED(Surface->GetDC(&hDC)))  
		exit(10);

	BitBlt(hDC, 0, 0, m_nWidth, m_nHeight, hDCImage, 0, 0, SRCCOPY);  
	Surface->ReleaseDC(hDC);  
	
	DeleteDC(hDCImage);  
	DeleteObject(hBM);
}
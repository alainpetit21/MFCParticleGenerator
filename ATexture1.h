#ifndef _A_TEXTURE_H_
#define _A_TEXTURE_H_

#include <ddraw.h>
#include <d3d.h>

class CATexture  
{
public:
	CATexture(const short& p_nWidth, const short& p_nHeight);
	virtual ~CATexture();
	void LoadTexture(char * filename, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw);
	void LoadTextureDDS(char * filename, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw);

	LPDIRECTDRAWSURFACE7 Surface;	// DirectDraw Texture
	short m_nWidth; 
	short m_nHeight;
};

#endif // _A_TEXTURE_H_

#ifndef _A_3D_OBJ_H_
#define _A_3D_OBJ_H_

#define D3D_OVERLOADS
#include <windows.h>
#include <windowsx.h>
#include <ddraw.h>
#include <d3d.h>
#include <d3dtypes.h>
#include "ATexture1.h"

class CA3DObj  
{
public:
	CA3DObj();
	virtual ~CA3DObj();

	virtual void OnDraw(LPDIRECT3DDEVICE7& p_D3DDevice)=0;
	virtual void OnInit(char* p_filename, short p_w, short p_h, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw, float p_x, float p_y, float p_z)=0;
	virtual void OnCleanUp();
	virtual void Update(float p_fLastTimeKey, float p_fTimeDif, float factor);

	D3DMATRIX m_mxThis;
	D3DVERTEX m_temp;
	D3DMATERIAL7 m_pmtrlObjectMtrl1;
	D3DMATERIAL7 m_pmtrlObjectMtrl2;

	CATexture* m_texture1;
	CATexture* m_texture2;
};

#endif // _A_3D_OBJ_H_

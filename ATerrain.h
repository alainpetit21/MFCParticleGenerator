#ifndef _A_TERRAIN_H_
#define _A_TERRAIN_H_

#include "A3DObj.h"

class CATerrain : public CA3DObj  
{
public:
	CATerrain();
	virtual ~CATerrain();
	virtual void OnDraw(LPDIRECT3DDEVICE7& p_D3DDevice);
	virtual void OnInit(char* p_filename, short p_w, short p_h, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw, float p_x, float p_y, float p_z);
	void Update(float p_fLastTimeKey, float p_fTimeDif, float factor);

	D3DVERTEX m_pvTriangleVertices[2][32][32][2][3];

};

#endif // _A_TERRAIN_H_

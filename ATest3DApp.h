#ifndef _A_3D_APP_H_
#define _A_3D_APP_H_

#include "AD3DApp.h"
#include "ATerrain.h"

class CTestSystem;
class CATest3DPlugin : public CAD3DPlugin
{
public:
	CATest3DPlugin(HWND WinHandle, int nx, int ny, int nw, int nh, int nbpp, int nWindowed);
	virtual ~CATest3DPlugin();

	virtual void GameInit();
	virtual void GameMain();
	virtual void GameDone();

	void Render();
	void Update(float p_fTimeKey);
	void OutputText(LPDIRECT3DDEVICE7 pd3dDevice, short x, short y, char* str);

	CATerrain	m_monde;
	CTestSystem* m_testSystem;

	D3DMATRIX m_mxWorld;
	D3DMATRIX m_mxView;
	D3DMATRIX m_mxProjection;

	float m_fSpeed;
	float m_fAngleX;
	float m_fAngleY;
	float m_fAngleZ;
};

#endif // _A_3D_APP_H_

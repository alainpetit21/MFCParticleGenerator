#include "stdafx.h"
#include "ATest3DApp.h"
#include "stdio.h"
#include <time.h>
#include <mmsystem.h>
#include <d3dMath.h>
#include "TestSystem.h"
#include "Particle.h"

CATest3DPlugin::CATest3DPlugin(HWND WinHandle, int nx, int ny, int nw, int nh, int nbpp, int nWindowed):
CAD3DPlugin(),
m_testSystem(NULL)
{
	Init(WinHandle,nx,ny,nw,nh,nbpp,nWindowed);
	m_fSpeed= 1;
	m_fAngleX=0;
	m_fAngleY=0;
	m_fAngleZ=0;
}

CATest3DPlugin::~CATest3DPlugin()
{

}

void CATest3DPlugin :: GameInit() 
{
	InitDirectX();

//	D3DDevice->SetLightState(D3DLIGHTSTATE_MATERIAL,NULL);
//	D3DDevice->SetRenderState(D3DRENDERSTATE_FILLMODE,D3DFILL_WIREFRAME);

	m_monde.OnInit("grass3.bmp", 256, 256, D3DDevice, DirectDraw, 0, 0, 0);

	D3DDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	D3DDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
	D3DDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
	D3DDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTFN_LINEAR );
	D3DDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTFG_LINEAR );

	D3DDevice->SetRenderState(D3DRENDERSTATE_AMBIENT,  0xffffffff);

	m_mxWorld._11= m_mxWorld._22= m_mxWorld._33= m_mxWorld._44= 1.0f;
	m_mxWorld._12= m_mxWorld._13= m_mxWorld._14= m_mxWorld._41= 0.0f;
	m_mxWorld._21= m_mxWorld._23= m_mxWorld._24= m_mxWorld._42= 0.0f;
	m_mxWorld._31= m_mxWorld._32= m_mxWorld._34= m_mxWorld._43= 0.0f;

//	m_mxView= m_mxWorld;
//	m_mxView._43= 5.0f;

//	m_mxView= m_mxWorld;
//	m_mxView._43= 5.0f;
	m_mxView._11=	0.998349f;
	m_mxView._12=	-0.00617387f;
	m_mxView._13=	-0.0571546f;
	m_mxView._14=	0.000000f;
	m_mxView._21=	-0.0203099f;
	m_mxView._22=	0.892225f;
	m_mxView._23=	-0.451131f;
	m_mxView._24=	0.000000f;
	m_mxView._31=	0.0537802f;
	m_mxView._32=	0.451545f;
	m_mxView._33=	0.890622f;
	m_mxView._34=	0.000000f;
	m_mxView._41=	0.000000f;
	m_mxView._42=	0.000000f;
	m_mxView._43=	2.05998f;
	m_mxView._44=	1.00000f;

	m_mxProjection=  m_mxWorld;
	m_mxProjection._11 =  2.0f;
	m_mxProjection._22 =  2.0f;
	m_mxProjection._34 =  1.0f;
	m_mxProjection._43 = -1.0f;
	m_mxProjection._44 =  0.0f;

	D3DDevice->SetTransform(D3DTRANSFORMSTATE_WORLD, &m_mxWorld);
	//[ 1.0, 0.0, 0.0, 0.0]
	//[ 0.0, 1.0, 0.0, 0.0]
	//[ 0.0, 0.0, 1.0, 0.0]
	//[ 0.0, 0.0, 0.0, 1.0]
	D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	//[ 1.0, 0.0, 0.0, 0.0]
	//[ 0.0, 1.0, 0.0, 0.0]
	//[ 0.0, 0.0, 1.0, 0.0]
	//[ 0.0, 0.0,25.0, 1.0]
	D3DDevice->SetTransform(D3DTRANSFORMSTATE_PROJECTION, &m_mxProjection);
	//[ 2.0, 0.0, 0.0, 0.0]
	//[ 0.0, 2.0, 0.0, 0.0]
	//[ 0.0, 0.0, 1.0, 0.0]
	//[ 0.0, 0.0,-1.0, 1.0]

};

void CATest3DPlugin::GameMain() 
{
	char buffer[128];
	RECT rec= {0, 0, ScreenWidth, ScreenHeight};
	FillSurface(BBuffer,0,&rec);
	Render();
	Update(timeGetTime() * 0.001f);
	Flip();
};

void CATest3DPlugin::GameDone() 
{

};

void CATest3DPlugin::Render() 
{
	D3DDevice->BeginScene();
	m_monde.OnDraw(D3DDevice);
	if(m_testSystem)	m_testSystem->OnDraw(D3DDevice);
	D3DDevice->EndScene();
};

void CATest3DPlugin::Update(float p_fTimeKey)
{
	static D3DMATRIX mat;
	static float lastTime= 0;
    static float fLastTimeFPS = 0.0f;
	static float lastDifTime=0;
    static char	 buffer[80];
    static float fFPS= 0.0f;
	static short nFrames= 0L;

	lastDifTime= p_fTimeKey - lastTime;
	lastTime= p_fTimeKey;
	++nFrames;

	m_monde.Update(lastTime, lastDifTime, 0.0f);
	if(m_testSystem)	
	{
		m_testSystem->OnUpdate(p_fTimeKey, m_testSystem->m_ageStart);
		if(!m_testSystem->IsAlive())
		{
			delete m_testSystem;
			m_testSystem= NULL;

		}
	}
	if(keyPad & KEY_PAD_LEFT)
	{
		m_mxView._41+= (m_fSpeed)*lastDifTime;
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}
	if(keyPad & KEY_PAD_RIGHT)
	{
		m_mxView._41-= (m_fSpeed)*lastDifTime;
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}
	if(keyPad & KEY_PAD_UP)
	{
		m_mxView._42-= (m_fSpeed/2)*lastDifTime;
		m_mxView._43-= (m_fSpeed)*lastDifTime;
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}
	if(keyPad & KEY_PAD_DOWN)
	{
		m_mxView._42+= (m_fSpeed/2)*lastDifTime;
		m_mxView._43+= (m_fSpeed)*lastDifTime;
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & (KEY_PAD_ROTATE))
	{
		mat._11= mat._22= mat._33= mat._44= 1.0f;
		mat._12= mat._13= mat._14= mat._41= 0.0f;
		mat._21= mat._23= mat._24= mat._42= 0.0f;
		mat._31= mat._32= mat._34= mat._43= 0.0f;
	}

	if(keyPad & KEY_PAD_ROTATE_X_PLUS)
	{
	//Rotate Axe X
		mat._22= (float)(cos(m_fSpeed*lastDifTime));
		mat._33= (float)(cos(m_fSpeed*lastDifTime));
		mat._23= (float)(sin(m_fSpeed*lastDifTime));
		mat._32= (float)(-sin(m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & KEY_PAD_ROTATE_X_MINUS)
	{
	//Rotate Axe X
		mat._22= (float)(cos(-m_fSpeed*lastDifTime));
		mat._33= (float)(cos(-m_fSpeed*lastDifTime));
		mat._23= (float)(sin(-m_fSpeed*lastDifTime));
		mat._32= (float)(-sin(-m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & KEY_PAD_ROTATE_Y_PLUS)
	{
	//Rotate Axe Y
		mat._11= (float)(cos(m_fSpeed*lastDifTime));
		mat._33= (float)(cos(m_fSpeed*lastDifTime));
		mat._13= (float)(sin(m_fSpeed*lastDifTime));
		mat._31= (float)(-sin(m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & KEY_PAD_ROTATE_Y_MINUS)
	{
	//Rotate Axe Y
		mat._11= (float)(cos(-m_fSpeed*lastDifTime));
		mat._33= (float)(cos(-m_fSpeed*lastDifTime));
		mat._13= (float)(sin(-m_fSpeed*lastDifTime));
		mat._31= (float)(-sin(-m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & KEY_PAD_ROTATE_Z_PLUS)
	{
	//Rotate Axe Z
		mat._11= (float)(cos(m_fSpeed*lastDifTime));
		mat._22= (float)(cos(m_fSpeed*lastDifTime));
		mat._12= (float)(sin(m_fSpeed*lastDifTime));
		mat._21= (float)(-sin(m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

	if(keyPad & KEY_PAD_ROTATE_Z_MINUS)
	{
	//Rotate Axe Z

		mat._11= (float)(cos(-m_fSpeed*lastDifTime));
		mat._22= (float)(cos(-m_fSpeed*lastDifTime));
		mat._12= (float)(sin(-m_fSpeed*lastDifTime));
		mat._21= (float)(-sin(-m_fSpeed*lastDifTime));
        D3DMath_MatrixMultiply(m_mxView, mat, m_mxView);
		D3DDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_mxView);
	}

//FPS
	if( p_fTimeKey - fLastTimeFPS > 1.0f )
	{
		fFPS= nFrames / (lastTime - fLastTimeFPS);
		fLastTimeFPS = lastTime;
		nFrames  = 0L;
	}

    sprintf( buffer, "%7.02f fps", fFPS);
	OutputText(D3DDevice, 0, 0, buffer);
}

void CATest3DPlugin::OutputText(LPDIRECT3DDEVICE7 pd3dDevice, short x, short y, char* str)
{
    LPDIRECTDRAWSURFACE7 pddsRenderSurface;
    if( FAILED( pd3dDevice->GetRenderTarget( &pddsRenderSurface ) ) )
        return;

    HDC hDC;
    if( SUCCEEDED( pddsRenderSurface->GetDC(&hDC) ) )
    {
        SetTextColor( hDC, RGB(255,255,0) );
        SetBkMode( hDC, TRANSPARENT );
        ExtTextOut( hDC, x, y, 0, NULL, str, strlen(str), NULL );
    
        pddsRenderSurface->ReleaseDC(hDC);
    }
    pddsRenderSurface->Release();
}

#include "stdafx.h"
#include "ATerrain.h"

CATerrain::CATerrain()
{

}

CATerrain::~CATerrain()
{
	OnCleanUp();
}

void CATerrain::OnInit(char* p_filename, short p_w, short p_h, LPDIRECT3DDEVICE7& p_D3DDevice, LPDIRECTDRAW7& p_DirectDraw, float p_x, float p_y, float p_z)
{
	short i;
	short j;
	short baseX= -64;
	short baseY= -64;
	D3DVECTOR vNormal( 0.0f, 0.0f, 1.0f );
  
	for(i= 0,baseX= -64; i < 32; ++i, baseX+= 4) for(j= 0,baseY= -64; j < 32; ++j, baseY+= 4)
	{
//		D3DVECTOR p1(-2.0f+baseX+p_x,-2.0f+baseY+p_y, 0.0f+p_z);
//		D3DVECTOR p2( 2.0f+baseX+p_x,-2.0f+baseY+p_y, 0.0f+p_z);
//		D3DVECTOR p3(-2.0f+baseX+p_x, 2.0f+baseY+p_y, 0.0f+p_z);
//		D3DVECTOR p4( 2.0f+baseX+p_x, 2.0f+baseY+p_y, 0.0f+p_z);
		D3DVECTOR p1(-2.0f+baseX+p_x, 0.0f+p_z, -2.0f+baseY+p_y);
		D3DVECTOR p2( 2.0f+baseX+p_x, 0.0f+p_z, -2.0f+baseY+p_y);
		D3DVECTOR p3(-2.0f+baseX+p_x, 0.0f+p_z,  2.0f+baseY+p_y);
		D3DVECTOR p4( 2.0f+baseX+p_x, 0.0f+p_z,  2.0f+baseY+p_y);
		m_pvTriangleVertices[0][i][j][0][0] = D3DVERTEX(p4, vNormal,	1.0f, 1.0f);
		m_pvTriangleVertices[0][i][j][0][1] = D3DVERTEX(p2, vNormal,	1.0f, 0.0f);
		m_pvTriangleVertices[0][i][j][0][2] = D3DVERTEX(p1, vNormal,	0.0f, 0.0f);
		m_pvTriangleVertices[0][i][j][1][0] = D3DVERTEX(p1, vNormal,	0.0f, 0.0f);
		m_pvTriangleVertices[0][i][j][1][1] = D3DVERTEX(p3, vNormal,	0.0f, 1.0f);
		m_pvTriangleVertices[0][i][j][1][2] = D3DVERTEX(p4, vNormal,	1.0f, 1.0f);

		m_pvTriangleVertices[1][i][j][0][0] = D3DVERTEX(p4, -vNormal,	1.0f, 1.0f);
		m_pvTriangleVertices[1][i][j][0][1] = D3DVERTEX(p2, -vNormal,	1.0f, 0.0f);
		m_pvTriangleVertices[1][i][j][0][2] = D3DVERTEX(p1, -vNormal,	0.0f, 0.0f);
		m_pvTriangleVertices[1][i][j][1][0] = D3DVERTEX(p1, -vNormal,	0.0f, 0.0f);
		m_pvTriangleVertices[1][i][j][1][1] = D3DVERTEX(p3, -vNormal,	0.0f, 1.0f);
		m_pvTriangleVertices[1][i][j][1][2] = D3DVERTEX(p4, -vNormal,	1.0f, 1.0f);
	}

	m_pmtrlObjectMtrl1.ambient.r = 1.0f;
	m_pmtrlObjectMtrl1.ambient.g = 1.0f;
	m_pmtrlObjectMtrl1.ambient.b = 1.0f;
 
	m_pmtrlObjectMtrl1.diffuse.r = 1.0f;
	m_pmtrlObjectMtrl1.diffuse.g = 1.0f;
	m_pmtrlObjectMtrl1.diffuse.b = 1.0f;

	m_pmtrlObjectMtrl2.ambient.r = 1.0f;
	m_pmtrlObjectMtrl2.ambient.g = 1.0f;
	m_pmtrlObjectMtrl2.ambient.b = 1.0f;

	m_pmtrlObjectMtrl2.diffuse.r = 1.0f;
	m_pmtrlObjectMtrl2.diffuse.g = 1.0f;
	m_pmtrlObjectMtrl2.diffuse.b = 1.0f;

	m_mxThis._11= m_mxThis._22= m_mxThis._33= m_mxThis._44= 1.0f;
	m_mxThis._12= m_mxThis._13= m_mxThis._14= m_mxThis._41= 0.0f;
	m_mxThis._21= m_mxThis._23= m_mxThis._24= m_mxThis._42= 0.0f;
	m_mxThis._31= m_mxThis._32= m_mxThis._34= m_mxThis._43= 0.0f;


	m_texture1= new CATexture(p_w, p_h);
	m_texture2= new CATexture(p_w, p_h);
	m_texture1->LoadTexture(p_filename, p_D3DDevice, p_DirectDraw);
	m_texture2->LoadTexture(p_filename, p_D3DDevice, p_DirectDraw);
}

void CATerrain::OnDraw(LPDIRECT3DDEVICE7& p_D3DDevice)
{
	short i;
	short j;
	p_D3DDevice->SetMaterial(&m_pmtrlObjectMtrl1);
	p_D3DDevice->SetTexture( 0, m_texture1->Surface);
	p_D3DDevice->SetTransform(D3DTRANSFORMSTATE_WORLD, &m_mxThis);
	p_D3DDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, FALSE);
	p_D3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, D3DFVF_VERTEX, m_pvTriangleVertices[0], 6144, NULL);
}

void CATerrain::Update(float p_fLastTimeKey, float p_fTimeDif, float factor)
{

}

#include "stdafx.h"
#include "PaticleSystem.h"
#include "Particle.h"
#include "ParticlePhysique.h"
#include "ATexture1.h"
#include "d3dmath.h"
#include "mmsystem.h"
#include "SystemConfig.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CPaticleSystem::CPaticleSystem():
m_texture(0),
m_nSizeArray(0),
m_age(0),
m_nSizeP(0.1f),
m_initialPosition(D3DVECTOR(0, 0, 0))
{
	D3DMATRIX& m= m_identityMatrix;
    m._12 = m._13 = m._14 = m._21 = m._23 = m._24 = 0.0f;
    m._31 = m._32 = m._34 = m._41 = m._42 = m._43 = 0.0f;
    m._11 = m._22 = m._33 = m._44 = 1.0f;

	m_arrays.m_pParticleChildArr= NULL;
	m_arrays.m_pSystemChildArr= NULL;
}

CPaticleSystem::~CPaticleSystem()
{
	if(m_texture){	delete m_texture; m_texture= NULL;}

	switch(m_brancheType)
	{
		case tagArrayType::PT_PARTICLE:
			delete [] m_arrays.m_pParticleChildArr;
			m_arrays.m_pParticleChildArr= NULL;
			break;
		case tagArrayType::PT_SUB_SYSTEM:
			delete [] m_arrays.m_pSystemChildArr;
			m_arrays.m_pSystemChildArr= NULL;
			break;
	}
}

void CPaticleSystem::Init(const CSystemConfig& p_config, LPDIRECT3DDEVICE7 &p_D3DDevice, LPDIRECTDRAW7 &p_DirectDraw)
{
	m_nSizeArray= p_config.m_nSize;
	m_brancheType= p_config.m_ucType;

	switch(m_brancheType)
	{
		case tagArrayType::PT_PARTICLE:
			m_arrays.m_pParticleChildArr= new CParticle[m_nSizeArray];
			m_texture					= new CATexture(16, 16);
			m_texture->LoadTexture("snow.bmp", p_D3DDevice, p_DirectDraw);
			break;
		case tagArrayType::PT_SUB_SYSTEM:
			m_arrays.m_pSystemChildArr	= new CPaticleSystem[m_nSizeArray];
		default:
			throw 1;
	}
}

void CPaticleSystem::Start(D3DVECTOR p_initialPosition)
{
	m_initialPosition= p_initialPosition;
	m_age= 0;
	m_lastTime= m_ageStart= (timeGetTime()*0.001f);
	InitOnReset();
	m_bAlive= true;
}

void CPaticleSystem::OnUpdate(float p_timeKey, float p_startAt)
{
	static D3DMATRIX mat;
	static float lastDifTime=0;

	lastDifTime= p_timeKey - m_lastTime;
	m_lastTime= p_timeKey;

	short i;
	switch(m_brancheType)
	{
	case tagArrayType::PT_PARTICLE:
		if(!m_bAlive)	return;
		for (i=0; i < m_nSizeArray; i++)
		{
			m_arrays.m_pParticleChildArr[i].m_pos.x+= m_arrays.m_pParticleChildArr[i].m_vel.x* lastDifTime;
			m_arrays.m_pParticleChildArr[i].m_pos.y+= m_arrays.m_pParticleChildArr[i].m_vel.y* lastDifTime;
			m_arrays.m_pParticleChildArr[i].m_pos.z+= m_arrays.m_pParticleChildArr[i].m_vel.z* lastDifTime;
			m_arrays.m_pParticleChildArr[i].m_vel+= m_arrays.m_pParticleChildArr[i].m_accel;
		}
		break;
	case tagArrayType::PT_SUB_SYSTEM:
		for (int i=0; i < m_nSizeArray; i++)
			m_arrays.m_pSystemChildArr[i].OnUpdate(p_timeKey, p_startAt);
	}
	if (((p_timeKey - m_ageStart))> m_ageMax) 
		Dies();
}

void CPaticleSystem::OnDraw(LPDIRECT3DDEVICE7 p_d3dDevice)
{
 	if(m_brancheType == tagArrayType::PT_SUB_SYSTEM)	
		for (int i=0; i < m_nSizeArray; i++)
			m_arrays.m_pSystemChildArr[i].OnDraw(p_d3dDevice);

	if(!m_bAlive)	return;

	D3DVECTOR TransPos;
    D3DMATRIX matViewBak;

	p_d3dDevice->GetTransform(D3DTRANSFORMSTATE_VIEW, &matViewBak);
	p_d3dDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &m_identityMatrix);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, true);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, m_methodSrcBlend);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, m_methodDstBlend);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_LIGHTING, false);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, false);
	p_d3dDevice->SetTexture( 0, m_texture->Surface);

	for (int i=0; i < m_nSizeArray; i++)
	{
		if(m_arrays.m_pParticleChildArr[i].m_pos.dvY < 0.0f)	
//			m_arrays.m_pParticleChildArr[i].m_vel.dvY*= -1;
			continue;
		D3DMath_VectorMatrixMultiply(TransPos, m_arrays.m_pParticleChildArr[i].m_pos, matViewBak);
		m_polygoneLit[0] = D3DLVERTEX(TransPos + D3DVECTOR(-1.0f*m_nSizeP, 1.0f*m_nSizeP, 0.0f), m_color, 0xffffffff, 0.0f, 0.0f);
		m_polygoneLit[1] = D3DLVERTEX(TransPos + D3DVECTOR( 1.0f*m_nSizeP, 1.0f*m_nSizeP, 0.0f), m_color, 0xffffffff, 1.0f, 0.0f);
		m_polygoneLit[2] = D3DLVERTEX(TransPos + D3DVECTOR(-1.0f*m_nSizeP,-1.0f*m_nSizeP, 0.0f), m_color, 0xffffffff, 0.0f, 1.0f);
		m_polygoneLit[3] = D3DLVERTEX(TransPos + D3DVECTOR( 1.0f*m_nSizeP,-1.0f*m_nSizeP, 0.0f), m_color, 0xffffffff, 1.0f, 1.0f);
		HRESULT hr= p_d3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, D3DFVF_LVERTEX, m_polygoneLit, 4, NULL);
	}

	p_d3dDevice->SetTexture( 0, NULL );
	p_d3dDevice->SetTransform(D3DTRANSFORMSTATE_VIEW, &matViewBak);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, false);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_LIGHTING, true);
	p_d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, true);
	p_d3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
}

bool CPaticleSystem::IsAlive()
{
	if(m_bAlive)									return true;
	if(m_brancheType == tagArrayType::PT_PARTICLE)	return false;

	//tchek sous-syste,
	for (short i=0; i < m_nSizeArray; ++i)
		if(m_arrays.m_pSystemChildArr[i].IsAlive())	return true;
	
	return false;
}

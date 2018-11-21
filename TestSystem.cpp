#include "stdafx.h"
#include "TestSystem.h"
#include "Particle.h"
#include "SystemConfig.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define RandFloat ((float)(rand()%1000)/1000.0f)

CTestSystem::CTestSystem()
{

}

CTestSystem::~CTestSystem()
{

}

void CTestSystem::InitOnReset()
{
	for (short i=0; i < m_nSizeArray; i++)
		m_arrays.m_pParticleChildArr[i].m_pos=		m_initialPosition;

	m_ageMax= 5;
}


void CTestSystem::Init(const CSystemConfig& p_config, LPDIRECT3DDEVICE7 &p_D3DDevice, LPDIRECTDRAW7 &p_DirectDraw)
{
	CPaticleSystem::Init(p_config, p_D3DDevice, p_DirectDraw);

	m_initialPosition= D3DVECTOR(p_config.m_posX+((RandFloat*p_config.m_posRX) - (p_config.m_posRX/2)), 
								 p_config.m_posY+((RandFloat*p_config.m_posRY) - (p_config.m_posRY/2)), 
								 p_config.m_posZ+((RandFloat*p_config.m_posRZ) - (p_config.m_posRZ/2)));
	m_color= RGBA_MAKE(((p_config.m_colorParticule & 0x000000FF)),
					   ((p_config.m_colorParticule & 0x0000FF00)) >> 8,
					   ((p_config.m_colorParticule & 0x00FF0000)) >> 16, 0xFF);
	m_methodSrcBlend= p_config.m_fctBlendSrc;
	m_methodDstBlend= p_config.m_fctBlendDst;
	m_nSizeP= p_config.m_fSize;

	for (short i=0; i < p_config.m_nSize; i++)
	{
		m_arrays.m_pParticleChildArr[i].m_pos=		m_initialPosition;
		m_arrays.m_pParticleChildArr[i].m_vel=		D3DVECTOR(p_config.m_velX+((RandFloat*p_config.m_velRX) - (p_config.m_velRX/2)),
															  p_config.m_velY+((RandFloat*p_config.m_velRY) - (p_config.m_velRY/2)),
															  p_config.m_velZ+((RandFloat*p_config.m_velRZ) - (p_config.m_velRZ/2)));
		m_arrays.m_pParticleChildArr[i].m_accel=	D3DVECTOR(p_config.m_accelX+((RandFloat*p_config.m_accelRX) - (p_config.m_accelRX/2)),
															  p_config.m_accelY+((RandFloat*p_config.m_accelRY) - (p_config.m_accelRY/2)),
															  p_config.m_accelZ+((RandFloat*p_config.m_accelRZ) - (p_config.m_accelRZ/2)));
	}
	m_ageMax= p_config.m_fLive;
	Start(m_initialPosition);
}

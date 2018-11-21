#include "stdafx.h"
#include "SystemConfig.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSystemConfig::CSystemConfig(
		const unsigned char&	p_ucType,
		const short&			p_nSize,
		const COLORREF&			p_colorParticule,
		const short&			p_fctBlendSrc,
		const short&			p_fctBlendDst,
		const float&			p_fSize,
		const float&			p_accelX,
		const float&			p_accelY,
		const float&			p_accelZ,
		const float&			p_accelRX,
		const float&			p_accelRY,
		const float&			p_accelRZ,
		const float&			p_posRX,
		const float&			p_posRY,
		const float&			p_posRZ,
		const float&			p_posX,
		const float&			p_posY,
		const float&			p_posZ,
		const float&			p_velRX,
		const float&			p_velRY,
		const float&			p_velRZ,
		const float&			p_velX,
		const float&			p_velY,
		const float&			p_velZ,
		const float&			p_fLive):
m_ucType		(p_ucType),
m_nSize			(p_nSize),
m_colorParticule(p_colorParticule),
m_fctBlendSrc	(p_fctBlendSrc),
m_fctBlendDst	(p_fctBlendDst),
m_fSize			(p_fSize),
m_accelX		(p_accelX),
m_accelY		(p_accelY),
m_accelZ		(p_accelZ),
m_accelRX		(p_accelRX),
m_accelRY		(p_accelRY),
m_accelRZ		(p_accelRZ),
m_posRX			(p_posRX),
m_posRY			(p_posRY),
m_posRZ			(p_posRZ),
m_posX			(p_posX),
m_posY			(p_posY),
m_posZ			(p_posZ),
m_velRX			(p_velRX),
m_velRY			(p_velRY),
m_velRZ			(p_velRZ),
m_velX			(p_velX),
m_velY			(p_velY),
m_velZ			(p_velZ),
m_fLive			(p_fLive)
{
}

CSystemConfig::CSystemConfig(CSystemConfig& rCopy):
m_ucType		(rCopy.m_ucType),
m_nSize			(rCopy.m_nSize),
m_colorParticule(rCopy.m_colorParticule),
m_fctBlendSrc	(rCopy.m_fctBlendSrc),
m_fctBlendDst	(rCopy.m_fctBlendDst),
m_fSize			(rCopy.m_fSize),
m_accelX		(rCopy.m_accelX),
m_accelY		(rCopy.m_accelY),
m_accelZ		(rCopy.m_accelZ),
m_accelRX		(rCopy.m_accelRX),
m_accelRY		(rCopy.m_accelRY),
m_accelRZ		(rCopy.m_accelRZ),
m_posRX			(rCopy.m_posRX),
m_posRY			(rCopy.m_posRY),
m_posRZ			(rCopy.m_posRZ),
m_posX			(rCopy.m_posX),
m_posY			(rCopy.m_posY),
m_posZ			(rCopy.m_posZ),
m_velRX			(rCopy.m_velRX),
m_velRY			(rCopy.m_velRY),
m_velRZ			(rCopy.m_velRZ),
m_velX			(rCopy.m_velX),
m_velY			(rCopy.m_velY),
m_velZ			(rCopy.m_velZ),
m_fLive			(rCopy.m_fLive)
{
}

CSystemConfig::~CSystemConfig()
{

}

void CSystemConfig::Update(
		unsigned char&	p_ucType,
		short&			p_nSize,
		COLORREF&		p_colorParticule,
		short&			p_fctBlendSrc,
		short&			p_fctBlendDst,
		float&			p_fSize,
		float&			p_accelX,
		float&			p_accelY,
		float&			p_accelZ,
		float&			p_accelRX,
		float&			p_accelRY,
		float&			p_accelRZ,
		float&			p_posRX,
		float&			p_posRY,
		float&			p_posRZ,
		float&			p_posX,
		float&			p_posY,
		float&			p_posZ,
		float&			p_velRX,
		float&			p_velRY,
		float&			p_velRZ,
		float&			p_velX,
		float&			p_velY,
		float&			p_velZ,
		float&			p_fLive)
{
	p_ucType			= m_ucType;
	p_nSize				= m_nSize;
	p_colorParticule	= m_colorParticule;
	p_fctBlendSrc		= m_fctBlendSrc;
	p_fctBlendDst		= m_fctBlendDst;
	p_fSize				= m_fSize;
	p_accelX			= m_accelX;
	p_accelY			= m_accelY;
	p_accelZ			= m_accelZ;
	p_accelRX			= m_accelRX;
	p_accelRY			= m_accelRY;
	p_accelRZ			= m_accelRZ;
	p_posRX				= m_posRX;
	p_posRY				= m_posRY;
	p_posRZ				= m_posRZ;
	p_posX				= m_posX;
	p_posY				= m_posY;
	p_posZ				= m_posZ;
	p_velRX				= m_velRX;
	p_velRY				= m_velRY;
	p_velRZ				= m_velRZ;
	p_velX				= m_velX;
	p_velY				= m_velY;
	p_velZ				= m_velZ;
	p_fLive				= m_fLive;
}
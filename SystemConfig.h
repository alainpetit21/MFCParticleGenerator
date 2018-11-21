#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_

class CSystemConfig  
{
public:
	CSystemConfig(
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
		const float&			p_fLive);
	CSystemConfig::CSystemConfig(CSystemConfig& rCopy);
	void Update(
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
		float&			p_fLive);

	virtual ~CSystemConfig();

	unsigned char	m_ucType;
	short			m_nSize;
	COLORREF		m_colorParticule;
	short			m_fctBlendSrc;
	short			m_fctBlendDst;
	float			m_fSize;
	float			m_accelX;
	float			m_accelY;
	float			m_accelZ;
	float			m_accelRX;
	float			m_accelRY;
	float			m_accelRZ;
	float			m_posRX;
	float			m_posRY;
	float			m_posRZ;
	float			m_posX;
	float			m_posY;
	float			m_posZ;
	float			m_velRX;
	float			m_velRY;
	float			m_velRZ;
	float			m_velX;
	float			m_velY;
	float			m_velZ;
	float			m_fLive;
};

#endif // _SYSTEM_CONFIG_H_

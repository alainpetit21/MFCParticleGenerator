#ifndef _C_PARTICULDE_INDEPENDANT_H_
#define _C_PARTICULDE_INDEPENDANT_H_

#include <d3d.h>

class CParticleIndependant  
{
public:
	D3DVECTOR	m_pos;
    D3DVECTOR	m_vel;
    D3DVECTOR	m_accel;
	float		m_age;
};

#endif // _C_PARTICULDE_INDEPENDANT_H_

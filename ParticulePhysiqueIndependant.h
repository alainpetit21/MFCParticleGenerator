#ifndef _C_PARTICULES_PHYSIQUE_INDEPENDANT_H_
#define _C_PARTICULES_PHYSIQUE_INDEPENDANT_H_

#include <d3d.h>

class CParticulePhysiqueIndependant  
{
public:
	D3DMATRIX	m_mx;
    D3DVECTOR	m_vel;
    D3DVECTOR	m_accel;
	float		m_age;
};

#endif // _C_PARTICULES_PHYSIQUE_INDEPENDANT_H_

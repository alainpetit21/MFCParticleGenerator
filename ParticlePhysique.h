#ifndef _C_PARTICLE_PHYSIQUE_H_
#define _C_PARTICLE_PHYSIQUE_H_

#include <d3d.h>

class CParticlePhysique  
{
public:
	D3DMATRIX m_mx;
    D3DVECTOR m_vel;
    D3DVECTOR m_accel;
};

#endif // _C_PARTICLE_PHYSIQUE_H_

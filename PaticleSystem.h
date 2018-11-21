#ifndef _CPARTICLE_SYSTE_H_
#define _CPARTICLE_SYSTE_H_

#define D3D_OVERLOADS
#include <d3d.h>
#include "Particle.h"

class CSystemConfig;
class CATexture;
class CPaticleSystem  
{
public:
	bool IsAlive();
	enum tagArrayType
	{
		PT_UNITIALISED= -1,
		PT_SUB_SYSTEM= 0,
		PT_PARTICLE,
	};

	CPaticleSystem();
	virtual ~CPaticleSystem();
	virtual void Init(const CSystemConfig& p_config, LPDIRECT3DDEVICE7 &p_D3DDevice, LPDIRECTDRAW7 &p_DirectDraw);
	virtual void InitOnReset(){};
	
	inline void ReLoop(){Reset();Start(m_initialPosition);};
	inline void Dies(){Reset();m_bAlive=false;};
	inline void Reset(){InitOnReset();};

	inline void SetPosition(const D3DVECTOR& p_initialPosition);
	inline void SetNbParticules(const short& p_nb);
	inline void SetType(const unsigned char& p_brancheType);

  
	virtual void Start(D3DVECTOR p_initialPosition);
	virtual void OnUpdate(float p_timeKey, float p_startAge);
    virtual void OnDraw(LPDIRECT3DDEVICE7 p_d3dDevice);

	unsigned char m_brancheType;
	union tagSystem
	{
		CPaticleSystem*		m_pSystemChildArr;
		CParticle*			m_pParticleChildArr;
	} m_arrays;


    short			m_nSizeArray;
    D3DMATRIX		m_identityMatrix;
    D3DVECTOR		m_initialPosition;
    D3DLVERTEX		m_polygoneLit[4];
	CATexture*		m_texture;
    unsigned long	m_ageStart;
    unsigned long	m_age;
    unsigned long	m_ageMax;
    bool			m_bAlive;
	float			m_lastTime;
	short			m_methodSrcBlend;
	short			m_methodDstBlend;
	float			m_nSizeP;
    D3DCOLOR		m_color;
	
};

//Inlined Fonctions 
void CPaticleSystem::SetNbParticules(const short& p_nb)
{
	m_nSizeArray= p_nb;
	switch(m_brancheType)
	{
		case tagArrayType::PT_PARTICLE:
			delete [] m_arrays.m_pParticleChildArr;
			m_arrays.m_pParticleChildArr= new CParticle[m_nSizeArray];
			break;
		case tagArrayType::PT_SUB_SYSTEM:
			delete [] m_arrays.m_pSystemChildArr;
			m_arrays.m_pSystemChildArr= new CPaticleSystem[m_nSizeArray];
			break;
	}
}

void CPaticleSystem::SetPosition(const D3DVECTOR&p_initialPosition)
{
	m_initialPosition= p_initialPosition;
}
void CPaticleSystem::SetType(const unsigned char& p_brancheType)
{
	m_brancheType= p_brancheType;
}

#endif // _CPARTICLE_SYSTE_H_

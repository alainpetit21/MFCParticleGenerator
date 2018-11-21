#ifndef _C_TEST_SYSTEM_H_
#define _C_TEST_SYSTEM_H_

#include "PaticleSystem.h"

class CSystemConfig;
class CTestSystem : public CPaticleSystem  
{
public:
	void Init(const CSystemConfig& p_config, LPDIRECT3DDEVICE7 &p_D3DDevice, LPDIRECTDRAW7 &p_DirectDraw);
	CTestSystem();
	virtual ~CTestSystem();
	virtual void InitOnReset();
};

#endif // _C_TEST_SYSTEM_H_
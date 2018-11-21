#include "stdafx.h"
#include "A3DObj.h"

CA3DObj::CA3DObj()
{
	ZeroMemory( &m_pmtrlObjectMtrl1, sizeof(D3DMATERIAL7));
	ZeroMemory( &m_pmtrlObjectMtrl2, sizeof(D3DMATERIAL7));
	m_texture1= NULL;
	m_texture2= NULL;
}

CA3DObj::~CA3DObj()
{

}

void CA3DObj::OnCleanUp()
{
	short i;
	if(m_texture1){ delete m_texture1; m_texture1= NULL;}
	if(m_texture2){ delete m_texture2; m_texture2= NULL;}
}

void CA3DObj::Update(float p_fLastTimeKey, float p_fTimeDif, float factor)
{
	D3DMATRIX mat;

	mat._11 = mat._22 = mat._33 = mat._44 = 1.0f;
	mat._12 = mat._13 = mat._14 = mat._41 = 0.0f;
	mat._21 = mat._23 = mat._24 = mat._42 = 0.0f;
	mat._31 = mat._32 = mat._34 = mat._43 = 0.0f;

}

//Rotate Axe X
//	mat._22 = (float)cos(p_fLastTimeKey);
//	mat._33 = (float)cos(p_fLastTimeKey);
//	mat._23 = (float)sin(p_fLastTimeKey);
//	mat._32 = (float)-sin(p_fLastTimeKey);

//Rotate Axe Y
//	mat._11 = (float)cos(p_fLastTimeKey);
//	mat._33 = (float)cos(p_fLastTimeKey);
//	mat._13 = (float)sin(p_fLastTimeKey);
//	mat._31 = (float)-sin(p_fLastTimeKey);


//Rotate Axe Z
//	mat._11 = (float)cos(p_fTimeKey);
//	mat._22 = (float)cos(p_fTimeKey);
//	mat._12 = (float)sin(p_fTimeKey);
//	mat._21 = (float)-sin(p_fTimeKey);

//Transl X
//	mat._41 = p_fLastTimeKey;
//Transl Y
//	mat._42 = p_fTimeKey;
//Transl Z
//	mat._43 = p_fLastTimeKey;

//Scale X
//	mat._11 = p_fTimeKey;
//Scale Y
//	mat._22 = p_fTimeKey;
//Scale Z
//	mat._33 = p_fTimeKey;
//Scale X & Y & Z
//	mat._11 = p_fTimeKey;
//	mat._22 = p_fTimeKey;
//	mat._33 = p_fTimeKey;

//	mat._42 = p_fTimeKey;
//	mat._43 = p_fTimeKey;
//	mat._11 = (float)cos(0);
//	mat._33 = (float)cos(0);
//	mat._13 = (float)sin(0);
//	mat._31 = (float)-sin(0);
//Set a 
//	HRESULT hres= D3DDevice->SetTransform( D3DTRANSFORMSTATE_WORLD, &matTransl);
	//[cos(t), 0.0,sin(t), 0.0]
	//[ 0.0  , 1.0, 0.0  , 0.0]
	//[sin(t), 0.0,cos(t), 0.0]
	//[ 0.0  , 0.0, 0.0  , 1.0]
//	m_matTri1= mat;
//Rotation sur Axe X
	//[ 1.0   , 0.0   ,0.0    , 0.0]
	//[ 0.0   , cos(t), sin(t), 0.0]
	//[ 0.0   ,-sin(t), cos(t), 0.0]
	//[ 0.0   , 0.0   , 0.0   , 1.0]
//Rotation sur Axe Y 
	//[cos(t) , 0.0   ,-sin(t), 0.0]
	//[ 0.0   , 1.0   , 0.0   , 0.0]
	//[sin(t) , 0.0   , cos(t), 0.0]
	//[ 0.0   , 0.0   , 0.0   , 1.0]
//Rotation sur Axe Z 
	//[ cos(t), sin(t), 0.0  , 0.0]
	//[-sin(t), cos(t), 0.0  , 0.0]
	//[ 0.0   , 0.0   , 1.0  , 0.0]
	//[ 0.0   , 0.0   , 0.0  , 1.0]

//Translation
	//[1.0   ,0.0    ,0.0    ,0.0]
	//[0.0   ,1.0    ,0.0    ,0.0]
	//[0.0   ,0.0    ,1.0    ,0.0]
	//[f(X)	 ,f(Y)   ,f(Z)   ,1.0]

//Scaling
	//[s(X)  ,0.0    ,0.0    ,0.0]
	//[0.0   ,s(Y)   ,0.0    ,0.0]
	//[0.0   ,0.0    ,s(Z)   ,0.0]
	//[0.0   ,0.0    ,0.0    ,1.0]

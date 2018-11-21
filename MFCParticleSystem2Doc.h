// MFCParticleSystem2Doc.h : interface of the CMFCParticleSystem2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCPARTICLESYSTEM2DOC_H__74D13940_BE79_48CA_940C_A7E44F21BF98__INCLUDED_)
#define AFX_MFCPARTICLESYSTEM2DOC_H__74D13940_BE79_48CA_940C_A7E44F21BF98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SystemConfig.h"
#include <map>


class CATest3DPlugin;
class CATexture;
class CMFCParticleSystem2Doc : public CDocument
{
protected: // create from serialization only
	CMFCParticleSystem2Doc();
	DECLARE_DYNCREATE(CMFCParticleSystem2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCParticleSystem2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CATest3DPlugin* m_renderer;
	std::map<HTREEITEM,CSystemConfig*> m_mapSystems;
	virtual ~CMFCParticleSystem2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCParticleSystem2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPARTICLESYSTEM2DOC_H__74D13940_BE79_48CA_940C_A7E44F21BF98__INCLUDED_)

// MFCParticleSystem2.h : main header file for the MFCPARTICLESYSTEM2 application
//

#if !defined(AFX_MFCPARTICLESYSTEM2_H__4E17D219_2367_404A_B6E4_17895938C4E7__INCLUDED_)
#define AFX_MFCPARTICLESYSTEM2_H__4E17D219_2367_404A_B6E4_17895938C4E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2App:
// See MFCParticleSystem2.cpp for the implementation of this class
//

class CMFCParticleSystem2App : public CWinApp
{
public:
	CMFCParticleSystem2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCParticleSystem2App)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCParticleSystem2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPARTICLESYSTEM2_H__4E17D219_2367_404A_B6E4_17895938C4E7__INCLUDED_)

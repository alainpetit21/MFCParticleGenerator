// MFCParticleSystem2View.h : interface of the CMFCParticleSystem2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCPARTICLESYSTEM2VIEW_H__4158BA92_4F6C_4EA2_B10D_33E3DB8D270E__INCLUDED_)
#define AFX_MFCPARTICLESYSTEM2VIEW_H__4158BA92_4F6C_4EA2_B10D_33E3DB8D270E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSystemConfig;
class CMFCParticleSystem2View : public CFormView
{
protected: // create from serialization only
	CMFCParticleSystem2View();
	DECLARE_DYNCREATE(CMFCParticleSystem2View)

public:
	//{{AFX_DATA(CMFCParticleSystem2View)
	enum { IDD = IDD_MFCPARTICLESYSTEM2_FORM };
	short	m_nNbParticules;
	short	m_fctBlendSrc;
	short	m_fctBlendDst;
	float	m_fSize;
	float	m_accelX;
	float	m_accelY;
	float	m_accelZ;
	float	m_accelRX;
	float	m_accelRY;
	float	m_accelRZ;
	float	m_posRX;
	float	m_posRY;
	float	m_posRZ;
	float	m_posX;
	float	m_posY;
	float	m_posZ;
	float	m_velRX;
	float	m_velRY;
	float	m_velRZ;
	float	m_velX;
	float	m_velY;
	float	m_velZ;
	float	m_fLive;
	//}}AFX_DATA

// Attributes
public:
	CMFCParticleSystem2Doc* GetDocument();

// Operations
public:
	void OnPlay(HTREEITEM p_item);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCParticleSystem2View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	unsigned char m_nType;
	void UpdateConfig(CSystemConfig*& rpConfig);
	CSystemConfig* BuildConfig();
	COLORREF m_colorParticule;
	virtual ~CMFCParticleSystem2View();


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCParticleSystem2View)
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnRotLeft();
	afx_msg void OnRotRight();
	afx_msg void OnStop();
	afx_msg void OnChooseColor();
	afx_msg void OnViewFullscreen();
	afx_msg void OnUpdateToolbars(CCmdUI* pCmdUI);
	afx_msg void OnNightDay();
	afx_msg void OnChoosePatern();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnVelRandom();
	afx_msg void OnPosRandom();
	afx_msg void OnAccRandom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCParticleSystem2View.cpp
inline CMFCParticleSystem2Doc* CMFCParticleSystem2View::GetDocument()
   { return (CMFCParticleSystem2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPARTICLESYSTEM2VIEW_H__4158BA92_4F6C_4EA2_B10D_33E3DB8D270E__INCLUDED_)

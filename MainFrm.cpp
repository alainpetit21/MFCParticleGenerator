// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MFCParticleSystem2.h"

#include "MainFrm.h"
#include "LeftView.h"
#include "MFCParticleSystem2Doc.h"
#include "MFCParticleSystem2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_NEW_SYSTEME, OnNewSysteme)
	ON_COMMAND(ID_NEW_SYSTEME_UNDER, OnNewSystemeUnder)
	ON_COMMAND(ID_SAVE_SYSTEM, OnSaveSystem)
	ON_COMMAND(ID_PLAY, OnPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	// create splitter window
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CMFCParticleSystem2View), CSize(100, 100), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	SetActiveView((CView*)m_wndSplitter.GetPane(0, 1));

	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	CView* pview= this->GetActiveView();
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnNewSysteme() 
{
	((CLeftView*)m_wndSplitter.GetPane(0, 0))->OnAddFatherSystem();
}

void CMainFrame::OnNewSystemeUnder() 
{
	((CLeftView*)m_wndSplitter.GetPane(0, 0))->OnHookChildrenSystem();
	
}

void CMainFrame::OnSaveSystem() 
{
	CLeftView*					gauche= (CLeftView*)m_wndSplitter.GetPane(0, 0);
	CMFCParticleSystem2View*	droite= (CMFCParticleSystem2View*)m_wndSplitter.GetPane(0, 1);

	HTREEITEM item= gauche->GetSelectedItem();
	
	if(((CMFCParticleSystem2Doc*)GetActiveDocument())->m_mapSystems.find(item) == ((CMFCParticleSystem2Doc*)GetActiveDocument())->m_mapSystems.end())
		((CMFCParticleSystem2Doc*)GetActiveDocument())->m_mapSystems[item]= droite->BuildConfig();
	else
		droite->UpdateConfig(((CMFCParticleSystem2Doc*)GetActiveDocument())->m_mapSystems[item]);

	((CMFCParticleSystem2Doc*)GetActiveDocument())->m_mapSystems[item]->m_ucType= !(gauche->GetTreeCtrl()).ItemHasChildren(item);
}

void CMainFrame::OnPlay() 
{
	CLeftView*					gauche= (CLeftView*)m_wndSplitter.GetPane(0, 0);
	CMFCParticleSystem2View*	droite= (CMFCParticleSystem2View*)m_wndSplitter.GetPane(0, 1);

	droite->OnPlay(gauche->GetSelectedItem());
}

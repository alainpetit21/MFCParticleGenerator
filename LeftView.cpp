// LeftView.cpp : implementation of the CLeftView class
//

#include "stdafx.h"
#include "MFCParticleSystem2.h"

#include "MFCParticleSystem2Doc.h"
#include "MFCParticleSystem2View.h"
#include "LeftView.h"
#include "Mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_COMMAND(ID_NEW_SYSTEME, OnNewSysteme)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView construction/destruction

CLeftView::CLeftView()
{
	// TODO: add construction code here

}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CMFCParticleSystem2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


/////////////////////////////////////////////////////////////////////////////
// CLeftView printing

BOOL CLeftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLeftView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLeftView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	CTreeCtrl& ctrlTree= GetTreeCtrl();
	HTREEITEM item;
	HTREEITEM item2;
	
	GetDocument()->UpdateAllViews(this);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CMFCParticleSystem2Doc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCParticleSystem2Doc)));
	return (CMFCParticleSystem2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

BOOL CLeftView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle | TVS_HASLINES | TVS_SHOWSELALWAYS | TVS_LINESATROOT | TVS_TRACKSELECT | TVS_HASBUTTONS , rect, pParentWnd, nID, pContext);
}

void CLeftView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	
}

void CLeftView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CTreeCtrl& ctrlTree= GetTreeCtrl();
	HTREEITEM item= ctrlTree.GetSelectedItem();

	if(GetDocument()->m_mapSystems.find(item) != GetDocument()->m_mapSystems.end())
		GetDocument()->UpdateAllViews(this, 1, (CObject*) item);
	*pResult = 0;
}

void CLeftView::OnAddFatherSystem()
{
	CTreeCtrl& ctrlTree= GetTreeCtrl();
	HTREEITEM item;
	CString string;

	string.Format("System : %d", ctrlTree.GetCount());
	item= ctrlTree.InsertItem(LPCSTR(string));
	ctrlTree.SetItemData(item, (DWORD) NULL);

}

void CLeftView::OnSaveParticles()
{
	CTreeCtrl& ctrlTree= GetTreeCtrl();

	HTREEITEM item;
	
}

void CLeftView::OnHookChildrenSystem()
{
	CTreeCtrl& ctrlTree= GetTreeCtrl();
	HTREEITEM item;
	
}

void CLeftView::OnNewSysteme() 
{
	OnAddFatherSystem();	
}


HTREEITEM CLeftView::GetSelectedItem()
{
	CTreeCtrl& ctrlTree= GetTreeCtrl();
	return ctrlTree.GetSelectedItem();

}

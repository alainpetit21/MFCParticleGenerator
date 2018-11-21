// MFCParticleSystem2Doc.cpp : implementation of the CMFCParticleSystem2Doc class
//

#include "stdafx.h"
#include "MFCParticleSystem2.h"

#include "MFCParticleSystem2Doc.h"
#include "ATest3DApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2Doc

IMPLEMENT_DYNCREATE(CMFCParticleSystem2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCParticleSystem2Doc, CDocument)
	//{{AFX_MSG_MAP(CMFCParticleSystem2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2Doc construction/destruction

CMFCParticleSystem2Doc::CMFCParticleSystem2Doc():
m_renderer(NULL)
{

}

CMFCParticleSystem2Doc::~CMFCParticleSystem2Doc()
{
	m_renderer->GameDone();
	delete m_renderer;

	for(std::map<HTREEITEM,CSystemConfig*>::iterator it= m_mapSystems.begin();
		it != m_mapSystems.end(); ++it)
			delete (*it).second;
}

BOOL CMFCParticleSystem2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	UpdateAllViews(NULL);
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2Doc serialization

void CMFCParticleSystem2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2Doc diagnostics

#ifdef _DEBUG
void CMFCParticleSystem2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCParticleSystem2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2Doc commands

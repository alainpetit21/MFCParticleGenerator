// MFCParticleSystem2View.cpp : implementation of the CMFCParticleSystem2View class
//

#include "stdafx.h"
#include "MFCParticleSystem2.h"

#include "MFCParticleSystem2Doc.h"
#include "MFCParticleSystem2View.h"
#include "ATest3DApp.h"
#include "TestSystem.h"
#include "Particle.h"
#include "SystemConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define COLORREF2RGBA(a)  D3DRGBA((a & 0x000000FF),\
								  (a & 0x0000FF00),\
								  (a & 0x00FF0000),0xFF)
/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2View
#define RandFloat ((float)(rand()%1000)/1000.0f)

IMPLEMENT_DYNCREATE(CMFCParticleSystem2View, CFormView)

BEGIN_MESSAGE_MAP(CMFCParticleSystem2View, CFormView)
	//{{AFX_MSG_MAP(CMFCParticleSystem2View)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ROT_LEFT, OnRotLeft)
	ON_BN_CLICKED(IDC_ROT_RIGHT, OnRotRight)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_PARTICULE_COLOR, OnChooseColor)
	ON_BN_CLICKED(IDC_VIEW_FULLSCREEN, OnViewFullscreen)
	ON_UPDATE_COMMAND_UI(ID_NEW_SYSTEME, OnUpdateToolbars)
	ON_BN_CLICKED(IDC_NIGHT_DAY, OnNightDay)
	ON_BN_CLICKED(IDC_PARTICLE_VIEW, OnChoosePatern)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_VEL_RANDOM, OnVelRandom)
	ON_BN_CLICKED(IDC_POS_RANDOM, OnPosRandom)
	ON_BN_CLICKED(IDC_ACCEL_RANDOM, OnAccRandom)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ADDPARTICULES, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ADDSYSTEM, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ADDSYSTEMUNDER, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EXPORTSYSTEM, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SAVEDATABASE, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_GENERATE_OBJECT, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_NEW_PARTICULES, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_NEW_SYSTEME_UNDER, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_SAVE_SYSTEM, OnUpdateToolbars)
	ON_UPDATE_COMMAND_UI(ID_PLAY, OnUpdateToolbars)
	ON_BN_CLICKED(IDC_VEL_RANDOM_SQUARED, OnVelRandom)
	ON_BN_CLICKED(IDC_VEL_RANDOM_RADIUS, OnVelRandom)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2View construction/destruction

CMFCParticleSystem2View::CMFCParticleSystem2View()
	: CFormView(CMFCParticleSystem2View::IDD)
{
	//{{AFX_DATA_INIT(CMFCParticleSystem2View)
	m_nNbParticules = 0;
	m_fctBlendSrc = 1;
	m_fctBlendDst = 1;
	m_fSize = 0.0f;
	m_accelX = 0.0f;
	m_accelY = 0.0f;
	m_accelZ = 0.0f;
	m_accelRX = 0.0f;
	m_accelRY = 0.0f;
	m_accelRZ = 0.0f;
	m_posRX = 0.0f;
	m_posRY = 0.0f;
	m_posRZ = 0.0f;
	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;
	m_velRX = 0.0f;
	m_velRY = 0.0f;
	m_velRZ = 0.0f;
	m_velX = 0.0f;
	m_velY = 0.0f;
	m_velZ = 0.0f;
	m_fLive = 0.0f;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_colorParticule= RGB(0x00, 0x00, 0x00);

}

CMFCParticleSystem2View::~CMFCParticleSystem2View()
{

}

void CMFCParticleSystem2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCParticleSystem2View)
	DDX_Text(pDX, IDC_NB_PARTICULES, m_nNbParticules);
	DDV_MinMaxInt(pDX, m_nNbParticules, 0, 30000);
	DDX_Text(pDX, IDC_BLEND_SRC, m_fctBlendSrc);
	DDV_MinMaxInt(pDX, m_fctBlendSrc, 1, 13);
	DDX_Text(pDX, IDC_BLEND_DST, m_fctBlendDst);
	DDV_MinMaxInt(pDX, m_fctBlendDst, 1, 13);
	DDX_Text(pDX, IDC_SIZE_PARTICULES, m_fSize);
	DDV_MinMaxFloat(pDX, m_fSize, 0.f, 10.f);
	DDX_Text(pDX, IDC_ACCX, m_accelX);
	DDX_Text(pDX, IDC_ACCY, m_accelY);
	DDX_Text(pDX, IDC_ACCZ, m_accelZ);
	DDX_Text(pDX, IDC_ACCRX, m_accelRX);
	DDX_Text(pDX, IDC_ACCRY, m_accelRY);
	DDX_Text(pDX, IDC_ACCRZ, m_accelRZ);
	DDX_Text(pDX, IDC_POSRX, m_posRX);
	DDX_Text(pDX, IDC_POSRY, m_posRY);
	DDX_Text(pDX, IDC_POSRZ, m_posRZ);
	DDX_Text(pDX, IDC_POSX, m_posX);
	DDX_Text(pDX, IDC_POSY, m_posY);
	DDX_Text(pDX, IDC_POSZ, m_posZ);
	DDX_Text(pDX, IDC_VELRX, m_velRX);
	DDX_Text(pDX, IDC_VELRY, m_velRY);
	DDX_Text(pDX, IDC_VELRZ, m_velRZ);
	DDX_Text(pDX, IDC_VELX, m_velX);
	DDX_Text(pDX, IDC_VELY, m_velY);
	DDX_Text(pDX, IDC_VELZ, m_velZ);
	DDX_Text(pDX, IDC_LIVE, m_fLive);
	DDV_MinMaxFloat(pDX, m_fLive, 0.f, 100.f);
	//}}AFX_DATA_MAP
}

BOOL CMFCParticleSystem2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCParticleSystem2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CWnd* target= GetDlgItem(IDC_D3D_RENDER_VIEW);
	RECT rec;
	target->GetWindowRect(&rec);
	GetDocument()->m_renderer= new CATest3DPlugin(target->GetSafeHwnd(), 0, 0, rec.right - rec.left, rec.bottom - rec.top, 32, 1);
	GetDocument()->m_renderer->GameInit();
	GetDocument()->UpdateAllViews(this);

	OnVelRandom();
	OnAccRandom();
	OnPosRandom();
}

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2View printing

BOOL CMFCParticleSystem2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCParticleSystem2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCParticleSystem2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCParticleSystem2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2View diagnostics

#ifdef _DEBUG
void CMFCParticleSystem2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCParticleSystem2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCParticleSystem2Doc* CMFCParticleSystem2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCParticleSystem2Doc)));
	return (CMFCParticleSystem2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCParticleSystem2View message handlers

void CMFCParticleSystem2View::OnLeft() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_LEFT;
}

void CMFCParticleSystem2View::OnRight() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_RIGHT;
	
}

void CMFCParticleSystem2View::OnUp() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_UP;
	
}

void CMFCParticleSystem2View::OnDown() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_DOWN;
	
}

void CMFCParticleSystem2View::OnRotLeft() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_ROTATE_Y_PLUS;
	
}

void CMFCParticleSystem2View::OnRotRight() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= KEY_PAD_ROTATE_Y_MINUS;
	
}

void CMFCParticleSystem2View::OnStop() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_renderer->keyPad= 0;
	
}

void CMFCParticleSystem2View::OnChooseColor() 
{
	CColorDialog dlg;

	if(dlg.DoModal() == IDOK)
	{
		m_colorParticule	= dlg.GetColor();
		Invalidate();
	}
}

void CMFCParticleSystem2View::OnViewFullscreen() 
{
	// TODO: Add your control notification handler code here
	
}

void CMFCParticleSystem2View::OnDraw(CDC* pDC) 
{
	RECT rec;
	CWnd*	previewColor;
	CDC*	DcPreviewControl;

	previewColor		= GetDlgItem(IDC_PARTICULE_COLOR);
	DcPreviewControl	= previewColor->GetDC();
	
	previewColor->GetClientRect(&rec);
	DcPreviewControl->FillSolidRect(CRect(0, 0, rec.right - rec.left, rec.bottom - rec.top), m_colorParticule);
}

void CMFCParticleSystem2View::OnUpdateToolbars(CCmdUI* pCmdUI) 
{
	switch(pCmdUI->m_nID)
	{
	case ID_PLAY:
		if(GetDocument()->m_renderer->m_testSystem == 0)
			pCmdUI->Enable(TRUE);
		else
			pCmdUI->Enable(FALSE);

//		pCmdUI->Enable(!(GetDocument()->m_renderer->m_testSystem));
		break;
//	case ID_GENERATE_OBJECT:
//	case ID_NEW_SYSTEME:
	default:
		pCmdUI->Enable(TRUE);
/*	case ID_NEW_SYSTEME_UNDER:
//		pCmdUI->Enable(DoesSelectionIsTree());
	case ID_NEW_PARTICULES:
//		pCmdUI->Enable(DoesSelectionIsTree());
	case ID_SAVE_DATABASE:
//		pCmdUI->Enable(TRUE);
	case ID_GENERATE_OBJECT:
		pCmdUI->Enable(DoesSelectionIsTree() && DoesSelectionHasParents());
*/	
	}
}


void CMFCParticleSystem2View::OnNightDay() 
{
	static bool value= 0;
	value= !value;
	CWnd* button= this->GetDlgItem(IDC_NIGHT_DAY);

	button->SetWindowText((value)? "Day":"Night");
	(value)?
		GetDocument()->m_renderer->D3DDevice->SetRenderState(D3DRENDERSTATE_AMBIENT,  0x55555555):
		GetDocument()->m_renderer->D3DDevice->SetRenderState(D3DRENDERSTATE_AMBIENT,  0xFFFFFFFF);
}

void CMFCParticleSystem2View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	HTREEITEM item= (HTREEITEM) pHint;

	switch(lHint)
	{
		case 1:
		{
			GetDocument()->m_mapSystems[item]->Update(
												m_nType,
												m_nNbParticules,
												m_colorParticule,
												m_fctBlendSrc,
												m_fctBlendDst,
												m_fSize,
												m_accelX,
												m_accelY,
												m_accelZ,
												m_accelRX,
												m_accelRY,
												m_accelRZ,
												m_posRX,
												m_posRY,
												m_posRZ,
												m_posX,
												m_posY,
												m_posZ,
												m_velRX,
												m_velRY,
												m_velRZ,
												m_velX,
												m_velY,
												m_velZ,
												m_fLive);
			UpdateData(FALSE);
		}

	}
	
}

						

void CMFCParticleSystem2View::OnPlay(HTREEITEM p_item) 
{
/*	CTestSystem* testSys;
	long couleur;
	
	UpdateData(true);
	if(GetDocument()->m_renderer->m_testSystem)	return;
	couleur= COLORREF2RGBA(m_colorParticule);

	testSys= GetDocument()->m_renderer->m_testSystem= new CTestSystem();
	testSys->Init(m_nNbParticules, CTestSystem::tagArrayType::PT_PARTICLE,GetDocument()->m_renderer->D3DDevice, GetDocument()->m_renderer->DirectDraw);
	testSys->Start(D3DVECTOR(m_posX+(RandFloat*m_posRX), m_posY+(RandFloat*m_posRY), m_posZ+(RandFloat*m_posRZ)));
	testSys->m_color= RGBA_MAKE(((m_colorParticule & 0x000000FF)),
								((m_colorParticule & 0x0000FF00)) >> 8,
								((m_colorParticule & 0x00FF0000)) >> 16, 0xFF);
	testSys->m_methodSrcBlend= m_fctBlendSrc;
	testSys->m_methodDstBlend= m_fctBlendDst;
	testSys->m_nSizeP= m_fSize;

	for (short i=0; i < testSys->m_nSizeArray; i++)
	{
		testSys->m_arrays.m_pParticleChildArr[i].m_pos=		testSys->m_initialPosition;
		testSys->m_arrays.m_pParticleChildArr[i].m_vel=		D3DVECTOR(m_velX+((RandFloat*m_velRX)-(m_velRX/2)), m_velY+((RandFloat*m_velRY)-(m_velRY/2)), m_velZ+((RandFloat*m_velRZ)-(m_velRZ/2)));
		testSys->m_arrays.m_pParticleChildArr[i].m_accel=	D3DVECTOR(m_accelX+(RandFloat*m_accelRX), m_accelY+(RandFloat*m_accelRY), m_accelZ+(RandFloat*m_accelRZ));
	}
	testSys->m_ageMax= m_fLive;
*/
	CTestSystem* testSys;
	testSys= GetDocument()->m_renderer->m_testSystem= new CTestSystem();
	testSys->Init(*GetDocument()->m_mapSystems[p_item], GetDocument()->m_renderer->D3DDevice, GetDocument()->m_renderer->DirectDraw);
}

void CMFCParticleSystem2View::OnChoosePatern() 
{
	CFileDialog dlg(true,"bmp", NULL, OFN_FILEMUSTEXIST, "Bitmap Files (*.bmp)|*.bmp|Direct Draw Surfaces Files (*.dds)|*.dds|All Files (*.*)|*.*||",this);

	if(dlg.DoModal() == IDOK)
	{
		Invalidate();
	}
}

void CMFCParticleSystem2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//Tcheker pour les 2 controles comstom
	CWnd*	item;
	RECT	rectItem;
	RECT	rectVue;
	CRect	rectVueMFC;
	CRect	rectItemMFC;
	POINT	pointBASE;
	
	GetWindowRect(&rectVue);
	rectVueMFC= rectVue;

	item=	GetDlgItem(IDC_PARTICULE_COLOR);
	item->GetWindowRect(&rectItem);
	rectItemMFC= rectItem;
	rectItemMFC+= rectVueMFC;
	rectItemMFC.right= rectItemMFC.left + (rectItem.right - rectItem.left);
	rectItemMFC.bottom= rectItemMFC.top + (rectItem.bottom - rectItem.top);

	pointBASE.x= point.x;
	pointBASE.y= point.y;

	if(rectItemMFC.PtInRect(pointBASE))
	{	OnChooseColor();	return;}

	item=	GetDlgItem(IDC_PARTICLE_VIEW);
	item->GetWindowRect(&rectItem);
	rectItemMFC= rectItem;
	rectItemMFC+= rectVueMFC;
	rectItemMFC.right= rectItemMFC.left + (rectItem.right - rectItem.left);
	rectItemMFC.bottom= rectItemMFC.top + (rectItem.bottom - rectItem.top);

	if(rectItemMFC.PtInRect(pointBASE))
	{	OnChoosePatern();	return;}

	CFormView::OnLButtonDown(nFlags, point);
}

void CMFCParticleSystem2View::OnVelRandom() 
{
	CButton* button;
	CButton* buttonRadio[2];
	CWnd* ctrlVel[3];
	CWnd* ctrlVelR[4];
	unsigned short etat;
	bool etatRadio[2];

	button			= (CButton*)GetDlgItem(IDC_VEL_RANDOM);
	buttonRadio[0]	= (CButton*)GetDlgItem(IDC_VEL_RANDOM_SQUARED);
	buttonRadio[1]	= (CButton*)GetDlgItem(IDC_VEL_RANDOM_RADIUS);
	ctrlVel[0]= GetDlgItem(IDC_VELX);
	ctrlVel[1]= GetDlgItem(IDC_VELY);
	ctrlVel[2]= GetDlgItem(IDC_VELZ);
	ctrlVelR[0]= GetDlgItem(IDC_VELRX);
	ctrlVelR[1]= GetDlgItem(IDC_VELRY);
	ctrlVelR[2]= GetDlgItem(IDC_VELRZ);
	ctrlVelR[3]= GetDlgItem(IDC_VELR_RADIUS);

	etat= button->GetState();
	etat&= 0x0003;
	etat>= 3;
	etatRadio[0]= buttonRadio[0]->GetState();
	etatRadio[1]= buttonRadio[1]->GetState();
	
	ctrlVel[0]->EnableWindow((etat & 0x02) || !etat);
	ctrlVel[1]->EnableWindow((etat & 0x02) || !etat);
	ctrlVel[2]->EnableWindow((etat & 0x02) || !etat);
	ctrlVelR[0]->EnableWindow(etat && (etatRadio[0]));
	ctrlVelR[1]->EnableWindow(etat && (etatRadio[0]));
	ctrlVelR[2]->EnableWindow(etat && (etatRadio[0]));
	ctrlVelR[3]->EnableWindow(etat && (etatRadio[1]));
}

void CMFCParticleSystem2View::OnPosRandom() 
{
	CButton* button;
	CWnd* ctrlPos[3];
	CWnd* ctrlPosR[3];
	unsigned short etat;

	button= (CButton*)GetDlgItem(IDC_POS_RANDOM);
	ctrlPos[0]= GetDlgItem(IDC_POSX);
	ctrlPos[1]= GetDlgItem(IDC_POSY);
	ctrlPos[2]= GetDlgItem(IDC_POSZ);
	ctrlPosR[0]= GetDlgItem(IDC_POSRX);
	ctrlPosR[1]= GetDlgItem(IDC_POSRY);
	ctrlPosR[2]= GetDlgItem(IDC_POSRZ);

	etat= button->GetState();
	etat&= 0x0003;
	etat>= 3;
	
	ctrlPos[0]->EnableWindow((etat & 0x02) || !etat);
	ctrlPos[1]->EnableWindow((etat & 0x02) || !etat);
	ctrlPos[2]->EnableWindow((etat & 0x02) || !etat);
	ctrlPosR[0]->EnableWindow(etat);
	ctrlPosR[1]->EnableWindow(etat);
	ctrlPosR[2]->EnableWindow(etat);
}

void CMFCParticleSystem2View::OnAccRandom() 
{
	CButton* button;
	CWnd* ctrlAcc[3];
	CWnd* ctrlAccR[3];
	unsigned short etat;

	button= (CButton*)GetDlgItem(IDC_ACCEL_RANDOM);
	ctrlAcc[0]= GetDlgItem(IDC_ACCX);
	ctrlAcc[1]= GetDlgItem(IDC_ACCY);
	ctrlAcc[2]= GetDlgItem(IDC_ACCZ);
	ctrlAccR[0]= GetDlgItem(IDC_ACCRX);
	ctrlAccR[1]= GetDlgItem(IDC_ACCRY);
	ctrlAccR[2]= GetDlgItem(IDC_ACCRZ);

	etat= button->GetState();
	etat&= 0x0003;
	etat>= 3;
	
	ctrlAcc[0]->EnableWindow((etat & 0x02) || !etat);
	ctrlAcc[1]->EnableWindow((etat & 0x02) || !etat);
	ctrlAcc[2]->EnableWindow((etat & 0x02) || !etat);
	ctrlAccR[0]->EnableWindow(etat);
	ctrlAccR[1]->EnableWindow(etat);
	ctrlAccR[2]->EnableWindow(etat);
}

CSystemConfig* CMFCParticleSystem2View::BuildConfig()
{
	UpdateData();
	return new CSystemConfig(
				m_nType,
				m_nNbParticules,
				m_colorParticule,
				m_fctBlendSrc,
				m_fctBlendDst,
				m_fSize,
				m_accelX,
				m_accelY,
				m_accelZ,
				m_accelRX,
				m_accelRY,
				m_accelRZ,
				m_posRX,
				m_posRY,
				m_posRZ,
				m_posX,
				m_posY,
				m_posZ,
				m_velRX,
				m_velRY,
				m_velRZ,
				m_velX,
				m_velY,
				m_velZ,
				m_fLive);
}


/*
		const short&	p_nNbParticules,
		const COLORREF&	p_colorParticule,
		const short&	p_fctBlendSrc,
		const short&	p_fctBlendDst,
		const float&	p_fSize,
		const float&	p_accelX,
		const float&	p_accelY,
		const float&	p_accelZ,
		const float&	p_accelRX,
		const float&	p_accelRY,
		const float&	p_accelRZ,
		const float&	p_posRX,
		const float&	p_posRY,
		const float&	p_posRZ,
		const float&	p_posX,
		const float&	p_posY,
		const float&	p_posZ,
		const float&	p_velRX,
		const float&	p_velRY,
		const float&	p_velRZ,
		const float&	p_velX,
		const float&	p_velY,
		const float&	p_velZ):
*/

void CMFCParticleSystem2View::UpdateConfig(CSystemConfig *&rpConfig)
{
	UpdateData(true);
	delete rpConfig;
	rpConfig= new CSystemConfig(
				m_nType,
				m_nNbParticules,
				m_colorParticule,
				m_fctBlendSrc,
				m_fctBlendDst,
				m_fSize,
				m_accelX,
				m_accelY,
				m_accelZ,
				m_accelRX,
				m_accelRY,
				m_accelRZ,
				m_posRX,
				m_posRY,
				m_posRZ,
				m_posX,
				m_posY,
				m_posZ,
				m_velRX,
				m_velRY,
				m_velRZ,
				m_velX,
				m_velY,
				m_velZ,
				m_fLive);
}

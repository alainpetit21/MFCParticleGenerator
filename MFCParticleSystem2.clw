; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCParticleSystem2.h"
LastPage=0

ClassCount=6
Class1=CMFCParticleSystem2App
Class2=CMFCParticleSystem2Doc
Class3=CMFCParticleSystem2View
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CLeftView
Class6=CAboutDlg
Resource3=IDD_MFCPARTICLESYSTEM2_FORM

[CLS:CMFCParticleSystem2App]
Type=0
HeaderFile=MFCParticleSystem2.h
ImplementationFile=MFCParticleSystem2.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMFCParticleSystem2App

[CLS:CMFCParticleSystem2Doc]
Type=0
HeaderFile=MFCParticleSystem2Doc.h
ImplementationFile=MFCParticleSystem2Doc.cpp
Filter=N
LastObject=CMFCParticleSystem2Doc

[CLS:CMFCParticleSystem2View]
Type=0
HeaderFile=MFCParticleSystem2View.h
ImplementationFile=MFCParticleSystem2View.cpp
Filter=D
LastObject=CMFCParticleSystem2View
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_PLAY
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
Filter=T
BaseClass=CTreeView
VirtualFilter=VWC
LastObject=CLeftView

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCParticleSystem2.cpp
ImplementationFile=MFCParticleSystem2.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_ADDSYSTEM
Command3=ID_EDIT_ADDSYSTEMUNDER
Command4=ID_EDIT_ADDPARTICULES
Command5=ID_EDIT_SAVEDATABASE
Command6=ID_EDIT_EXPORTSYSTEM
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_MFCPARTICLESYSTEM2_FORM]
Type=1
Class=CMFCParticleSystem2View
ControlCount=67
Control1=IDC_ROT_LEFT,button,1342242816
Control2=IDC_ROT_RIGHT,button,1342242816
Control3=IDC_UP,button,1342242816
Control4=IDC_LEFT,button,1342242816
Control5=IDC_DOWN,button,1342242816
Control6=IDC_RIGHT,button,1342242816
Control7=IDC_STOP,button,1342242816
Control8=IDC_VIEW_FULLSCREEN,button,1342242816
Control9=IDC_NIGHT_DAY,button,1342242816
Control10=IDC_SYSTEM_NAME,edit,1484849280
Control11=IDC_TRG_ON_START,button,1342308361
Control12=IDC_TRG_ON_PARENT_DIE,button,1342242825
Control13=IDC_LIVE,edit,1350631552
Control14=IDC_LIVE_USE_RANDOM,button,1476460547
Control15=IDC_LIVE_RANDOM_ADDITION,edit,1484849280
Control16=IDC_NB_PARTICULES,edit,1350631552
Control17=IDC_PARTICULE_COLOR,static,1342181383
Control18=IDC_SIZE_PARTICULES,edit,1350631552
Control19=IDC_BLEND_SRC,edit,1350631552
Control20=IDC_BLEND_DST,edit,1350631552
Control21=IDC_VELX,edit,1350631552
Control22=IDC_VELY,edit,1350631552
Control23=IDC_VELZ,edit,1350631552
Control24=IDC_POSX,edit,1350631552
Control25=IDC_POSY,edit,1350631552
Control26=IDC_POSZ,edit,1350631552
Control27=IDC_ACCX,edit,1350631552
Control28=IDC_ACCY,edit,1350631552
Control29=IDC_ACCZ,edit,1350631552
Control30=IDC_PARTICLE_VIEW,static,1342181383
Control31=IDC_VEL_RANDOM_SQUARED,button,1342308361
Control32=IDC_VEL_RANDOM_RADIUS,button,1342242825
Control33=IDC_VELRX,edit,1350631552
Control34=IDC_VELRY,edit,1350631552
Control35=IDC_VELRZ,edit,1350631552
Control36=IDC_VELR_RADIUS,edit,1350631552
Control37=IDC_POS_RANDOM_SQUARED,button,1342308361
Control38=IDC_POS_RANDOM_RADIUS,button,1342242825
Control39=IDC_POSRX,edit,1350631552
Control40=IDC_POSRY,edit,1350631552
Control41=IDC_POSRZ,edit,1350631552
Control42=IDC_POSR_RADIUS,edit,1350631552
Control43=IDC_ACC_RANDOM_SQUARED,button,1342308361
Control44=IDC_ACCEL_RANDOM_RADIUS,button,1342242825
Control45=IDC_ACCRX,edit,1350631552
Control46=IDC_ACCRY,edit,1350631552
Control47=IDC_ACCRZ,edit,1350631552
Control48=IDC_ACCELR_RADIUS,edit,1350631552
Control49=IDC_D3D_RENDER_VIEW,static,1342177287
Control50=IDC_STATIC,static,1342308352
Control51=IDC_STATIC,static,1342308352
Control52=IDC_STATIC,static,1342308352
Control53=IDC_STATIC,static,1342308352
Control54=IDC_STATIC,static,1476526080
Control55=IDC_STATIC,static,1476526080
Control56=IDC_STATIC,static,1476526080
Control57=IDC_STATIC,button,1342177287
Control58=IDC_STATIC,button,1342177287
Control59=IDC_STATIC,button,1342177287
Control60=IDC_STATIC,static,1342308352
Control61=IDC_STATIC,static,1342308352
Control62=IDC_STATIC,static,1342308352
Control63=IDC_STATIC,static,1342308352
Control64=IDC_STATIC,static,1342308352
Control65=IDC_VEL_RANDOM,button,1342242822
Control66=IDC_POS_RANDOM,button,1342242822
Control67=IDC_ACCEL_RANDOM,button,1342242822

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_NEW_SYSTEME
Command2=ID_NEW_SYSTEME_UNDER
Command3=ID_NEW_PARTICULES
Command4=ID_SAVE_SYSTEM
Command5=ID_GENERATE_OBJECT
Command6=ID_PLAY
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8


# Microsoft Developer Studio Project File - Name="MFCParticleSystem2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MFCParticleSystem2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MFCParticleSystem2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MFCParticleSystem2.mak" CFG="MFCParticleSystem2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MFCParticleSystem2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MFCParticleSystem2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MFCParticleSystem2 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MFCParticleSystem2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MFCParticleSystem2 - Win32 Release"
# Name "MFCParticleSystem2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\A3DObj.cpp
# End Source File
# Begin Source File

SOURCE=.\AD3DApp.cpp
# End Source File
# Begin Source File

SOURCE=.\ATerrain.cpp
# End Source File
# Begin Source File

SOURCE=.\ATest3DApp.cpp
# End Source File
# Begin Source File

SOURCE=.\ATexture1.cpp
# End Source File
# Begin Source File

SOURCE=.\d3dmath.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2.cpp
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2.rc
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2Doc.cpp
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2View.cpp
# End Source File
# Begin Source File

SOURCE=.\Particle.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleIndependant.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticlePhysique.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticulePhysiqueIndependant.cpp
# End Source File
# Begin Source File

SOURCE=.\PaticleSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SystemConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\TestSystem.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\A3DObj.h
# End Source File
# Begin Source File

SOURCE=.\AD3DApp.h
# End Source File
# Begin Source File

SOURCE=.\ATerrain.h
# End Source File
# Begin Source File

SOURCE=.\ATest3DApp.h
# End Source File
# Begin Source File

SOURCE=.\ATexture1.h
# End Source File
# Begin Source File

SOURCE=.\d3dmath.h
# End Source File
# Begin Source File

SOURCE=.\LeftView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2.h
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2Doc.h
# End Source File
# Begin Source File

SOURCE=.\MFCParticleSystem2View.h
# End Source File
# Begin Source File

SOURCE=.\Particle.h
# End Source File
# Begin Source File

SOURCE=.\ParticleIndependant.h
# End Source File
# Begin Source File

SOURCE=.\ParticlePhysique.h
# End Source File
# Begin Source File

SOURCE=.\ParticulePhysiqueIndependant.h
# End Source File
# Begin Source File

SOURCE=.\PaticleSystem.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SystemConfig.h
# End Source File
# Begin Source File

SOURCE=.\TestSystem.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\MFCParticleSystem2.ico
# End Source File
# Begin Source File

SOURCE=.\res\MFCParticleSystem2.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MFCParticleSystem2Doc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "library"

# PROP Default_Filter "*.lib"
# Begin Source File

SOURCE="..\..\Program Files\Microsoft Visual Studio\Vc98\Lib\Winmm.lib"
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\dxguid.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\d3dx.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\d3dxd.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\d3dxof.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\ddraw.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\dinput.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\dplayx.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\DSETUP.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\dsound.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk7\lib\d3dim.lib
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project

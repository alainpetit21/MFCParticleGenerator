#include "stdafx.h"
#include "AD3DApp.h"

#define DDRAW_INIT_STRUCT(ddstruct) { memset(&ddstruct,0,sizeof(ddstruct)); ddstruct.dwSize=sizeof(ddstruct); }
CAD3DPlugin::CAD3DPlugin()
{
	Clipper = NULL;
	WindowClipper = NULL;
	DirectDraw = NULL;
	Primary = NULL;
	BBuffer = NULL;
	keyPad= 0;
}

CAD3DPlugin::~CAD3DPlugin()
{
	if (Direct3D)		Direct3D->Release();
	if (Clipper)		Clipper->Release();
	if (WindowClipper)	WindowClipper->Release();
	if (BBuffer)		BBuffer->Release();
	if (Primary)		Primary->Release();
	if (DirectDraw)		DirectDraw->Release();
}

void CAD3DPlugin::Init(HWND WinHandle, int nx, int ny, int nw, int nh, int nbpp, int nWindowed) 
{
	MainWindow		= WinHandle;
	WindowClientX0	= nx;
	WindowClientY0	= ny;
	ScreenWidth		= nw;
	ScreenHeight	= nh;
	BitDepth		= nbpp;
	Windowed		= nWindowed;
};

void CAD3DPlugin::InitDirectDraw() 
{
	LPDIRECTDRAW lpddTemp = NULL;

	if (FAILED(DirectDrawCreateEx(NULL,(void**)&DirectDraw,IID_IDirectDraw7,NULL))) 
	{
		ReportError("Unable to initialise basic DirectDraw Object");
		ReportError("Unable to upgrade to recent DirectDraw");
		exit(10);
	};

	if (Windowed) 
	{
		if (FAILED(DirectDraw->SetCooperativeLevel(MainWindow,DDSCL_NORMAL))) 
		{
			ReportError("Failed to cooperate (windowed mode) with Windows");
			exit(10);
		};
	} 
	else 
	{
		if (FAILED(DirectDraw->SetCooperativeLevel(MainWindow,DDSCL_ALLOWMODEX | DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE | DDSCL_ALLOWREBOOT | DDSCL_FPUSETUP))) 
		{
			ReportError("Failed to cooperate (fullscreen mode) with Windows");
			exit(10);
		};
	};

	if (!Windowed) 
	{
		if (FAILED(DirectDraw->SetDisplayMode(ScreenWidth,ScreenHeight,BitDepth,0,0))) 
		{
			ReportError("Couldn't get 16bpp, trying 24");
			
			if (BitDepth == 16) 
			{
				BitDepth = 24;
				if (FAILED(DirectDraw->SetDisplayMode(ScreenWidth,ScreenHeight,BitDepth,0,0))) 
				{
					ReportError("No 24bpp either.");
					exit(10);
				};
			} 
			else 
			{
				ReportError("Screen initialisation failed horribly. Don't use 8 bpp.");
				exit(10);
			};
		};
	};

	memset(&SurfaceDescription,0,sizeof(SurfaceDescription));
	SurfaceDescription.dwSize = sizeof(SurfaceDescription);

	if (!Windowed) 
	{
		SurfaceDescription.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
		SurfaceDescription.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE  | DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_3DDEVICE;
   
		SurfaceDescription.dwBackBufferCount = 1;
	} 
	else 
	{
		SurfaceDescription.dwFlags = DDSD_CAPS;
		SurfaceDescription.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_3DDEVICE;
		SurfaceDescription.dwBackBufferCount = 0;
	};
	
	DirectDraw->CreateSurface(&SurfaceDescription,&Primary,NULL);

	DDPIXELFORMAT ddpf;
	DDRAW_INIT_STRUCT(ddpf);
	Primary->GetPixelFormat(&ddpf);
	PixelFormat = ddpf.dwRGBBitCount;

	if (!Windowed) 
	{
		SurfaceDescription.dwFlags = DDSD_CAPS;
		SurfaceDescription.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER | DDSCAPS_3DDEVICE;
		SurfaceDescription.dwBackBufferCount = 1;
 
		if (FAILED(Primary->GetAttachedSurface(&SurfaceDescription.ddsCaps,&BBuffer))) 
		{
			ReportError("Double buffering isn't possible.");
			exit(10);
		};
	} 
	else 
		BBuffer = CreateSurface(ScreenWidth,ScreenHeight,DDSCAPS_3DDEVICE,0);

	if (Windowed) 
	{
		FillSurface(BBuffer,0,NULL);
	} 
	else 
	{
		FillSurface(BBuffer,0,NULL);
		FillSurface(Primary,0,NULL);
	};

	ClipMinX = 0;
	ClipMaxX = ScreenWidth -1;
	ClipMinY = 0;
	ClipMaxY = ScreenHeight -1;

	RECT ScreenRect = {0,0,ScreenWidth,ScreenHeight};	/*@Ptet la le trouble@*/
	Clipper = AttachClipper(BBuffer,1,&ScreenRect);

	if (Windowed) 
	{
		if (FAILED(DirectDraw->CreateClipper(0,&WindowClipper,NULL))) 
		{
			ReportError("Failed to create a clipper");
			exit(10);
		};
		if (FAILED(WindowClipper->SetHWnd(0, MainWindow))) 
		{
			ReportError("Failed to attach clipper to window");
			exit(10);
		};

		if (FAILED(Primary->SetClipper(WindowClipper))) 
		{
			ReportError("Failed to set the clipper on the primary buffer");
			exit(10);
		};
   };
}

LPDIRECTDRAWCLIPPER CAD3DPlugin::AttachClipper(LPDIRECTDRAWSURFACE7 surface, int RectCount, LPRECT ClipList)
{
	int Count;
	LPDIRECTDRAWCLIPPER Clipper;
	LPRGNDATA RegionData;

	if (FAILED(DirectDraw->CreateClipper(0,&Clipper,NULL))) 
		return NULL;

	RegionData = (LPRGNDATA)malloc(sizeof(RGNDATAHEADER)+RectCount*sizeof(RECT));
	memcpy(RegionData->Buffer, ClipList, sizeof(RECT)*RectCount);

	RegionData->rdh.dwSize          = sizeof(RGNDATAHEADER);
	RegionData->rdh.iType           = RDH_RECTANGLES;
	RegionData->rdh.nCount          = RectCount;
	RegionData->rdh.nRgnSize        = RectCount*sizeof(RECT);

	RegionData->rdh.rcBound.left    =  64000;
	RegionData->rdh.rcBound.top     =  64000;
	RegionData->rdh.rcBound.right   = -64000;
	RegionData->rdh.rcBound.bottom  = -64000;

	for (Count = 0; Count < RectCount; Count++) 
	{
		if (ClipList[Count].left < RegionData->rdh.rcBound.left)	 RegionData->rdh.rcBound.left = ClipList[Count].left;
		if (ClipList[Count].right > RegionData->rdh.rcBound.right)	 RegionData->rdh.rcBound.right = ClipList[Count].right;
		if (ClipList[Count].top < RegionData->rdh.rcBound.top)		 RegionData->rdh.rcBound.top = ClipList[Count].top;
		if (ClipList[Count].bottom > RegionData->rdh.rcBound.bottom) RegionData->rdh.rcBound.bottom = ClipList[Count].bottom;
	};

	if (FAILED(Clipper->SetClipList(RegionData,0))) 
	{
		free(RegionData);
		return(NULL);
	};

	if (FAILED(surface->SetClipper(Clipper))) 
	{
		free(RegionData);
		return(NULL);
	};

	free(RegionData);
	return Clipper;
};

LPDIRECTDRAWSURFACE7 CAD3DPlugin::CreateSurface(int width, int height, int mem_flags, USHORT colour_key_value)
{
	DDSURFACEDESC2 TempDescription;
	LPDIRECTDRAWSURFACE7 Surface;

	memset(&TempDescription,0,sizeof(TempDescription));
	TempDescription.dwSize = sizeof(TempDescription);
	TempDescription.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;

	TempDescription.dwWidth = width;
	TempDescription.dwHeight = height;

	TempDescription.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | mem_flags;

	if (FAILED(DirectDraw->CreateSurface(&TempDescription,&Surface,NULL)))
	{
		ReportError("Surface creation failed!");
		exit(10);
		return NULL;
	};

	DDCOLORKEY ColourKey;
	ColourKey.dwColorSpaceLowValue = colour_key_value;
	ColourKey.dwColorSpaceHighValue = colour_key_value;

	Surface->SetColorKey(DDCKEY_SRCBLT,&ColourKey);

	return Surface;
}

void CAD3DPlugin::FillSurface(LPDIRECTDRAWSURFACE7 lpdds, USHORT colour, RECT * client)
{
	DDBLTFX BlitFX;

	DDRAW_INIT_STRUCT(BlitFX);
	BlitFX.dwFillColor = colour;
	lpdds->Blt(client,NULL,NULL,DDBLT_COLORFILL | DDBLT_WAIT,&BlitFX);
}

void CAD3DPlugin::InitDirect3D() 
{
	D3DFINDDEVICESEARCH search;
	D3DFINDDEVICERESULT result;

	if (FAILED(DirectDraw->QueryInterface(IID_IDirect3D7, (VOID**)&Direct3D))) 
	{
		ReportError("Direct3D Query Failed");
	};

	memset(&search,0,sizeof(search));
	search.dwSize = sizeof(search);
	search.bHardware = 1;
	
	memset(&result,0,sizeof(result));
	result.dwSize = sizeof(result);
/*	if (FAILED(Direct3D->CreateDevice(IID_IDirect3DTnLHALDevice,BBuffer,&D3DDevice,NULL))) 
	{
		if (FAILED(Direct3D->CreateDevice(IID_IDirect3DHALDevice,BBuffer,&D3DDevice,NULL))) 
		{
			ReportError("Failed to create a HAL device, trying MMX.");
			if (FAILED(Direct3D->CreateDevice(IID_IDirect3DMMXDevice,BBuffer,&D3DDevice,NULL))) 
			{
				ReportError("Failed to create an MMX device, trying RGB");
				if (FAILED(Direct3D->CreateDevice(IID_IDirect3DRGBDevice,BBuffer,&D3DDevice,NULL))) 
				{
					ReportError("Failed to create an RGB device, trying RAMP. Icky.");
					if (FAILED(Direct3D->CreateDevice(IID_IDirect3DRampDevice,BBuffer,&D3DDevice,NULL))) 
					{
						ReportError("No Direct3D Devices are available");
						exit(10);
					};
				};

			};
		};
	};*/
	if (FAILED(Direct3D->CreateDevice(IID_IDirect3DTnLHalDevice,BBuffer,&D3DDevice))) 
		if (FAILED(Direct3D->CreateDevice(IID_IDirect3DHALDevice,BBuffer,&D3DDevice))) 
			if (FAILED(Direct3D->CreateDevice(IID_IDirect3DMMXDevice,BBuffer,&D3DDevice))) 
				if (FAILED(Direct3D->CreateDevice(IID_IDirect3DRGBDevice,BBuffer,&D3DDevice))) 
					exit(10);
};

void CAD3DPlugin::ReportError(char * text) 
{
	MessageBox(MainWindow,text,"Engine Problems",MB_OK);
}

void CAD3DPlugin::Flip()
{
	if (!Windowed) 
		while(FAILED(Primary->Flip(NULL,DDFLIP_WAIT)));
	else 
	{
		RECT dest;

		GetWindowRect(MainWindow, &dest);
		dest.left += WindowClientX0;
		dest.top += WindowClientY0;
		dest.right = dest.left + ScreenWidth;
		dest.bottom = dest.top + ScreenHeight;

		if (FAILED(Primary->Blt(&dest, BBuffer, NULL, DDBLT_WAIT,NULL))) 
		{
			ReportError("Blit failed");
			exit(10);
		};
	};
}

void CAD3DPlugin::InitDirectX() 
{
	InitDirectDraw();
	InitDirect3D();

	if (!Windowed) 
		ShowCursor(FALSE);

	srand(GetTickCount());
};


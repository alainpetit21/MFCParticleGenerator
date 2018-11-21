#ifndef _A_D3D_APP_H_
#define _A_D3D_APP_H_

#define D3D_OVERLOADS
#include <windows.h>
#include <windowsx.h>
#include <ddraw.h>
#include <d3d.h>
#include <d3dtypes.h>

#define KEY_PAD_UP		0x0001
#define KEY_PAD_DOWN	0x0002
#define KEY_PAD_LEFT	0x0004
#define KEY_PAD_RIGHT	0x0008
#define KEY_PAD_MOVE	0x000F


#define KEY_PAD_ROTATE_X_PLUS		0x0010
#define KEY_PAD_ROTATE_X_MINUS		0x0020
#define KEY_PAD_ROTATE_Y_PLUS		0x0040
#define KEY_PAD_ROTATE_Y_MINUS		0x0080
#define KEY_PAD_ROTATE_Z_PLUS		0x0100
#define KEY_PAD_ROTATE_Z_MINUS		0x0200
#define KEY_PAD_ROTATE				0x03F0

#define KEY_PAD_OTHER	0x0400

class CAD3DPlugin 
{
public:
	CAD3DPlugin();
	virtual ~CAD3DPlugin();
	void Init(HWND WinHandle, int nx, int ny, int nw, int nh, int nbpp, int nWindowed);
	void InitDirectX();
	void InitDirectDraw();
	void InitDirect3D();
	LPDIRECTDRAWSURFACE7 CreateSurface(int width,int height, int mem_flags, USHORT colour_key_value);
	LPDIRECTDRAWCLIPPER AttachClipper(LPDIRECTDRAWSURFACE7 surface, int RectCount, LPRECT ClipList);
	void FillSurface(LPDIRECTDRAWSURFACE7 lpdds, USHORT colour, RECT * client);
	void Flip();
	void ReportError(char * text);
	virtual void GameInit()=0;
	virtual void GameMain()=0;
	virtual void GameDone()=0;

	//Win32 gogosses
	HINSTANCE Application;
	HWND MainWindow;

	//DX goggose
	LPDIRECTDRAW7 DirectDraw;
	LPDIRECT3DDEVICE7 D3DDevice;
	LPDIRECT3D7 Direct3D;
	LPDIRECTDRAWCLIPPER Clipper;
	LPDIRECTDRAWCLIPPER WindowClipper;
	LPDIRECTDRAWSURFACE7 Primary;
	LPDIRECTDRAWSURFACE7 BBuffer;
	DDSURFACEDESC2 SurfaceDescription;

	//My Gogosses
	int Windowed;
	int BitDepth;
	int ScreenHeight;
	int ScreenWidth;
	int WindowClientY0;
	int WindowClientX0;

	int ClipMaxY;
	int ClipMinY;
	int ClipMaxX;
	int ClipMinX;

	int PixelFormat;
	short keyPad;
};

#endif // _A_D3D_APP_H_

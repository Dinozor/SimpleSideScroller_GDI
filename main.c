#define WINVER 0x0602
#include <windows.h>

#include <math.h>

#include "includes/graphics.h"

LRESULT CALLBACK ProcessMessagefn(HWND,UINT,WPARAM,LPARAM);

HDC hDC;

#define Circle(Ix,Iy,Radius,Color)(Circle(hDC,Ix,Iy,Radius,Color))

void RenderScene();

int __stdcall WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
    WNDCLASS wc;
	MSG msg;
	HWND hWnd;
	BOOL exit=FALSE;
	
	if(!hPrevInst)
	{
		wc.cbClsExtra=0;
		wc.cbWndExtra=0;
		wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
		wc.hCursor=LoadCursor(NULL,IDC_ARROW);
		wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		wc.hInstance=hInst;
		wc.lpfnWndProc=(WNDPROC)ProcessMessagefn;
		wc.lpszClassName="MyClass";
		wc.lpszMenuName=NULL;
		wc.style=0;

		if(!RegisterClass(&wc))
		{
		    MessageBox(0,"Cannot Register window","Error",MB_OK);
			return FALSE;
		}
	}

	hWnd=CreateWindow("MyClass","SimpleSideScroller",WS_SYSMENU,10,10,900,506,NULL,NULL,hInst,NULL);
	
	if(!hWnd)
	{
		MessageBox(0,"Cannot Create Window","Error",MB_OK);
		return FALSE;
	}

	ShowWindow(hWnd,SW_SHOW);
	HBITMAP MyBitmap = (HBITMAP)LoadImage( hInst,"res/images/ship.bmp",IMAGE_BITMAP,0,0, LR_LOADFROMFILE);

	HDC hdcMem = CreateCompatibleDC(hDC);

	SelectObject(hdcMem, MyBitmap);
	//TransparentBlt(hDC, 0, 0, 64, 64, hdcMem, 0, 0, 64, 64, RGB(0,255,0));
	BitBlt(hDC, 0, 0, 64, 64, hdcMem, 0, 0, SRCPAINT);

	while(!exit)
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if(msg.message==WM_QUIT)
				exit=TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			RenderScene();
			//TransparentBlt(hDC, 0, 0, 64, 64, hdcMem, 0, 0, 64, 64, RGB(0,255,0));
		}
	}
	return(msg.wParam);
}

LRESULT CALLBACK ProcessMessagefn(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		 hDC=GetDC(hWnd);  
		 break;
	case WM_DESTROY:
		 ReleaseDC(hWnd,hDC);
		 PostQuitMessage(0);
		 break;
	default:
		return DefWindowProc(hWnd,message,wParam,lParam);
	}
	return(0);
}

//Redering the screen with random circles 
void RenderScene()
{
	/*int xx=300,yy=400;
	int a=0,b=0,radius=50;
	int IMax=1300,IMin=1;
	int MinClr=0,MaxClr=255;
	int Ix = IMin + rand() % (IMax - IMin);
	int Iy = IMin + rand() % (IMax - IMin);
	
	int R = MinClr + rand() % (MaxClr - MinClr);
	int G = MinClr + rand() % (MaxClr - MinClr);
	int B = MinClr + rand() % (MaxClr - MinClr);
	
	for(int Radius=0;Radius<100;Radius=Radius+15)
	{
		COLORREF Color=RGB(R,G,B); 
		Circle(Ix,Iy,Radius,Color);
		Circle(Ix,Iy,Radius+1,Color);
		Circle(Ix,Iy,Radius+2,Color);
		Circle(Ix,Iy,Radius+3,Color);
		Circle(Ix,Iy,Radius+4,Color);
		Circle(Ix,Iy,Radius+5,Color);
	}*/
	Sleep(2);
	
	//TextOut(hDC,10,10,WINVER,11);//Draw text on device context
}

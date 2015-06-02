#include "engine.h"

struct _window
{
	struct _window* next;
	
	int id;
};
struct _windowsList
{
	struct _window* _HEAD;
	struct _window* _CURRENT;
	unsigned int length;
	unsigned int _NEXT_ID;
};
struct _windows* _next(struct _windowsList* handler)
{
	if (handler==NULL)
		return NULL;
	if (handler->_CURRENT==NULL)
		return NULL;
	if (handler->_CURRENT->_)
		return NULL;
}
/*
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
	//BitBlt(hDC, 0, 0, 64, 64, hdcMem, 0, 0, SRCPAINT);

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
*/

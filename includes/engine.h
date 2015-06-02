#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <windows.h>

struct _window{
	WNDCLASS wc;
	MSG msg;
	HWND hWnd;
	BOOL exit=FALSE;
};

InitWindow();
ShowWindow();
CloseWindow();

AddCallback();
RemoveCallback();



SwitchWindow();

#endif

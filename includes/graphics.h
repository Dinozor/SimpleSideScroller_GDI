#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <windows.h>

void Circle(HDC hDC, int x0, int y0, int radius, COLORREF Clr);

struct _image
{
	HBITMAP bitmap;
	char *full_name;
	
};

#endif

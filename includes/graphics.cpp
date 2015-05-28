#include "graphics.h"

void Circle(HDC hDC, int x0, int y0, int radius, COLORREF Clr)
{
	int f = 1 - radius;
	int ddF_x = 1;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;

	SetPixel(hDC,x0, y0 + radius,Clr);
	SetPixel(hDC,x0, y0 - radius,Clr);
	SetPixel(hDC,x0 + radius, y0,Clr);
	SetPixel(hDC,x0 - radius, y0,Clr);

	while(x < y)
	{

		if(f >= 0) 
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;    
		SetPixel(hDC,x0 + x, y0 + y,Clr);
		SetPixel(hDC,x0 - x, y0 + y,Clr);
		SetPixel(hDC,x0 + x, y0 - y,Clr);
		SetPixel(hDC,x0 - x, y0 - y,Clr);
		SetPixel(hDC,x0 + y, y0 + x,Clr);
		SetPixel(hDC,x0 - y, y0 + x,Clr);
		SetPixel(hDC,x0 + y, y0 - x,Clr);
		SetPixel(hDC,x0 - y, y0 - x,Clr);
	}
}

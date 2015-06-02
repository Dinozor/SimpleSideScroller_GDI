#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <windows.h>

void Circle(HDC hDC, int x0, int y0, int radius, COLORREF Clr);

struct _image
{
	HBITMAP bitmap;
	char *full_name;
};

LoadImge();
DrawImage();
UnloadImage();

CreateImgAnimation();
AddImgToAnimation();
RemoveImgFromAnimation();
GetImgFromAnimation();
GetAnimationArray();

LaunchAnimation();
StopAnimation();

CreateLayer();
UpdateLayer();
AddImgToLayer();
RemoveImgFromLayer();
DestroyLayer();

AddChildLayer();
RemoveChildLayer();
GetChildLayer();
GetLayerChilds();

#endif

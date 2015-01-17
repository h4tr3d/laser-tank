#include <math.h>

#include <cassert>

#include "func.h"

int convert_error = 0;
int SysColor = 0;


// почему-то не было в стандартной библиотеке
void kos_DrawLine( Word x1, Word y1, Word x2, Word y2, Dword colour, Dword invert )
{
    // TODO: SDL2 DrawLine
    assert(0);
}

// похищено из библиотеки к C--
void DrawRegion(Dword x,Dword y,Dword width,Dword height,Dword color1)
{
	kos_DrawBar(x,y,width,1,color1); //полоса гор сверху
	kos_DrawBar(x,y+height,width,1,color1); //полоса гор снизу
	kos_DrawBar(x,y,1,height,color1); //полоса верт слева
	kos_DrawBar(x+width,y,1,height+1,color1); //полоса верт справа
}

// поскольку я портировал с древнего доса...
void line( int x1, int y1, int x2, int y2)
{
	kos_DrawLine(x1,y1,x2,y2,SysColor,0);
}

void outtextxy( int x, int y, char *s, int len)
{
	kos_WriteTextToWindow(x,y,0,SysColor,s,len);
}

double textwidth( char *s, int len)
{
	int i;
	for (i = 0; i < len; i++)
		if (s[i] == 0)
			break;
	return id(i * 6);
}

double textheight( char *s, int len)
{
	return 8.0;
}

void setcolor( DWORD color)
{
	SysColor = color;
}

void rectangle( int x1, int y1, int x2, int y2)
{
	kos_DrawBar(x1,y1,x2-x1,y2-y1,SysColor);
}

int di(double x)
{
    //return static_cast<int>(floor(x));
    return static_cast<int>(round(x));
    //return static_cast<int>(x);
}

double id(int x)
{
    return static_cast<double>(x);
}

int roundInt(double x)
{
    return static_cast<int>(round(x));
}

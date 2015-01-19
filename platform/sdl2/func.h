#ifndef LINUX_FUNC_H
#define LINUX_FUNC_H

#include "kosSyst.h"
#include "kosFile.h"

#include <stdarg.h>
#include <math.h>

#include <algorithm>

#define ERROR -1
#define ERROR_END -2

extern int convert_error;

typedef int HDC;
typedef int DWORD;

extern int SysColor;

typedef double (*function_t)(double);

typedef struct
{
  double x, y;
} TCoord;

struct kosBDVK 
{
	Dword attrib;
	Dword name_type;
	Dword create_time;
	Dword create_date;
	Dword access_time;
	Dword access_date;
	Dword modify_time;
	Dword modify_date;
	Dword size_low;
	Dword size_high;	
};

void kos_DrawLine( Word x1, Word y1, Word x2, Word y2, Dword colour, Dword invert);
void DrawRegion(Dword x,Dword y,Dword width,Dword height,Dword color1);

void line( int x1, int y1, int x2, int y2);

void outtextxy( int x, int y, char *s, int len);
void settextstyle( int a1, int a2, int a3);


double textwidth( char *s, int len);
double textheight( char *s, int len);
void setcolor( DWORD color);
void unsetcolor(HDC hdc);
void rectangle( int x1, int y1, int x2, int y2);

typedef struct 
{
unsigned	p00 ;
unsigned	p04 ;
unsigned	p08 ;
unsigned	p12 ;
unsigned	p16 ;
char		p20 ;
char		*p21 ;
} kol_struct70 ;


typedef struct
{
unsigned	p00 ;
char		p04 ;
char		p05[3] ;
unsigned	p08 ;
unsigned	p12 ;
unsigned	p16 ;
unsigned	p20 ;
unsigned	p24 ;
unsigned	p28 ;
unsigned	p32[2] ;
unsigned	p40 ;
} kol_struct_BDVK ;

typedef struct
{
char	*name ;
void	*data ;
} kol_struct_import ;


int di(double x); 
double id(int x);

#define arccos(x) acos(x)
#define sqrtd(x)  sqrt(x)
int roundInt(double x);


#endif // LINUX_FUNC_H

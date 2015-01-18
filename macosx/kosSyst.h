#include <stdint.h>

#pragma once

#define __declspec(x) __attribute__((x))

typedef uint32_t Dword;
typedef uint16_t Word;
typedef uint8_t  Byte;
//typedef unsigned __int32 size_t;

extern "C" char kosCmdLine[];	// command line initialized by OS
extern "C" char kosExePath[];	// path to binary initialized by OS

#define MAX_PATH				256

#define FO_READ					0
#define FO_WRITE				2

#define EM_WINDOW_REDRAW		1
#define EM_KEY_PRESS			2
#define EM_BUTTON_CLICK			4
#define EM_APP_CLOSE			8
#define EM_DRAW_BACKGROUND		16
#define EM_MOUSE_EVENT			32
#define EM_IPC					64
#define EM_NETWORK				256

#define KM_CHARS				0
#define KM_SCANS				1

#define WRS_BEGIN				1
#define WRS_END					2

#define PROCESS_ID_SELF			-1


struct kosFileInfo
{
	Dword rwMode;
	Dword OffsetLow;
	Dword OffsetHigh;
	Dword dataCount;
	Byte *bufferPtr;
	char fileURL[MAX_PATH];
};

struct Point
{
	int X;
	int Y;

    Point() {}
	Point(int x, int y)
	{
		this->X = x;
		this->Y = y;
    }

    bool operator != (const Point &a){ return this->X != a.X || this->Y != a.Y; }
    bool operator == (const Point &a){ return this->X == a.X && this->Y == a.Y; }
    Point operator + (const Point &a){ return Point(this->X + a.X, this->Y + a.Y); }
	Point operator + (int a){ return Point(this->X + a, this->Y + a); }
    Point operator - (const Point &a){ return Point(this->X - a.X, this->Y - a.Y); }
	Point operator - (int a){ return Point(this->X - a, this->Y - a); }
    Point operator * (const Point &a){ return Point(this->X * a.X, this->Y * a.Y); }
	Point operator * (int a){ return Point(this->X * a, this->Y * a); }
    Point operator / (const Point &a){ return Point(this->X / a.X, this->Y / a.Y); }
	Point operator / (int a){ return Point(this->X / a, this->Y / a); }
	
	float Lingrh();
	float Angle();
};

struct Rect
{
	int X;
	int Y;
	int Width;
	int Height; 
	Rect() {}
	Rect(int X, int Y, int Width, int Height)
	{
		this->X = X;
		this->Y = Y;
		this->Width = Width;
		this->Height = Height;
	}
};

struct RGBA
{
	Byte b;
	Byte g;
	Byte r;
	Byte a;

    RGBA() {}

	RGBA(Dword value)
	{
		a = (Byte)(value >> 24);
		r = (Byte)(value >> 16);
		g = (Byte)(value >> 8);
		b = (Byte)value;
    }
	//
	bool operator != (RGBA &another)
	{
		return this->b != another.b || this->g != another.g || this->r != another.r || this->a != another.a;
    }
	//
	bool operator == (RGBA &another)
	{
		return this->b == another.b && this->g == another.g && this->r == another.r && this->a == another.a;
    }
} __attribute__((packed));


struct RGB
{
	Byte b;
	Byte g;
	Byte r;
	//
    RGB() {}
	//
	RGB( Dword value )
	{
		r = (Byte)(value >> 16);
		g = (Byte)(value >> 8);
		b = (Byte)value;
    }
	//
	bool operator != ( RGB &another )
	{
		return this->b != another.b || this->g != another.g || this->r != another.r;
    }
	//
	bool operator == ( RGB &another )
	{
		return this->b == another.b && this->g == another.g && this->r == another.r;
    }
} __attribute__((packed));

struct Player
{
	Point vector;
	Point position;
	float angle;

	Player() {}
	Player(Point position)
	{
		this->vector = Point(0, -1);
		this->position = position;
		this->angle = 270;
	};
};

#pragma pack(push, 1)
union sProcessInfo
{
	Byte rawData[1024];
	struct
	{
		Dword cpu_usage;
		Word window_stack_position;
		Word window_stack_value;
		Word reserved1;
		char process_name[12];
		Dword memory_start;
		Dword used_memory;
		Dword PID;
		Dword x_start;
		Dword y_start;
		Dword x_size;
		Dword y_size;
		Word slot_state;
	} processInfo;
};
#pragma pack(pop)

//
void initGraph();
void deinitGraph();

//
void rtlSrand( Dword seed );
Dword rtlRand( void );

unsigned int num2hex( unsigned int num );
// ������� -1 ���������� ��������
void kos_ExitApp() __attribute__((noreturn));
// ������� 0
void kos_DefineAndDrawWindow(Word x, Word y,
    Word sizeX, Word sizeY,
    Byte mainAreaType, Dword mainAreaColour,
    Byte headerType, Dword headerColour,
    const char *title
    );
// ������� 1 ��������� �����
void kos_PutPixel( Dword x, Dword y, Dword colour );
// ������� 2 �������� ��� ������� �������
bool kos_GetKey( Byte &keyCode );
// ������� 3 �������� �����
Dword kos_GetSystemClock();
// ������� 4
void kos_WriteTextToWindow(
	Word x, Word y,
	Byte fontType,
	Dword textColour,
	const char *textPtr,
	Dword textLen
	);
// ������� 7 ���������� �����������
void kos_PutImage(const RGB *imagePtr, Word sizeX, Word sizeY, Word x, Word y );
// ������� 8 ���������� ������
void kos_DefineButton( Word x, Word y, Word sizeX, Word sizeY, Dword buttonID, Dword colour ) __attribute__((noinline));
// ������� 5 �����, � ����� ����� �������
void kos_Pause( Dword value );
// ������� 9 - ���������� � ��������
Dword kos_ProcessInfo( sProcessInfo *targetPtr, Dword processID = PROCESS_ID_SELF );
// ������� 10
Dword kos_WaitForEvent();
// ������� 11
Dword kos_CheckForEvent();
// ������� 12
void kos_WindowRedrawStatus( Dword status );
// ������� 13 ���������� ������
void __declspec(noinline) kos_DrawBar( Word x, Word y, Word sizeX, Word sizeY, Dword colour );
// ������� 17
bool kos_GetButtonID( Dword &buttonID );
// ������� 23
Dword kos_WaitForEventTimeout( Dword timeOut );
//
enum eNumberBase
{
	nbDecimal = 0,
	nbHex,
	nbBin
};
// ��������� ���������� � ��������� "����" ������� 37
void kos_GetMouseState( Dword & buttons, int & cursorX, int & cursorY );
// ������� 40 ���������� ����� �������
void kos_SetMaskForEvents( Dword mask );
// ������� 47 ������� � ���� ���������� �����
void kos_DisplayNumberToWindow(
   Dword value,
   Dword digitsNum,
   Word x,
   Word y,
   Dword colour,
   eNumberBase nBase = nbDecimal,
   bool valueIsPointer = false
   );
// ������� 58 ������ � �������� �������
Dword kos_FileSystemAccess( kosFileInfo *fileInfo );
// ������� 63
void kos_DebugOutChar( char ccc );
//
void rtlDebugOutString(const char *str );
// ������� 64 �������� ��������� ����, �������� == -1 �� ��������
void kos_ChangeWindow( Dword x, Dword y, Dword sizeX, Dword sizeY );
// ������� 67 ��������� ���������� ������, ���������� ��� ���������
bool kos_ApplicationMemoryResize( Dword targetSize );
// ������� 66 ����� ��������� ������ �� ����������
void kos_SetKeyboardDataMode( Dword mode );

void kos_InitHeap();

//
void kos_Main();

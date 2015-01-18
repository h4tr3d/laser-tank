#include <iostream>
#include <cassert>
#include <chrono>
#include <thread>

#include <stdarg.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_ttf.h>

#include "kosSyst.h"
#include "func.h"

char kosCmdLine[257];
char kosExePath[1024];

namespace {

SDL_Window   *s_win  = nullptr;
SDL_Renderer *s_ren  = nullptr;
TTF_Font     *s_font = nullptr;

} // ::<empty>


float Point::Lingrh()
{
	return sqrtd(this->X * this->X + this->Y * this->Y);
}

float Point::Angle()
{
	return atan2(this->X, this->Y);
}

//
void rtlSrand( Dword seed )
{
    srand(seed);
}
//
Dword rtlRand( void )
{
    return rand();
}

//////////////////////////////////////////////////////////////////////
//
// ������� ������������������ ����� � ������
//

unsigned int num2hex( unsigned int num )
{
  if( num < 10 )
    return num + '0';
  return num - 10 + 'A';
}


// ������� -1 ���������� ��������
void kos_ExitApp()
{
    exit(0);
}

// ������� 0
void kos_DefineAndDrawWindow(
	Word x, Word y,
	Word sizeX, Word sizeY,
	Byte mainAreaType,
	Dword mainAreaColour,
	Byte headerType,
	Dword headerColour,
    const char *title
	)
{
    static_cast<void>(mainAreaType);
    static_cast<void>(headerType);
    static_cast<void>(headerColour);

    if (s_win == nullptr) {
        s_win = SDL_CreateWindow(title, x, y, sizeX, sizeY, SDL_WINDOW_SHOWN);
        if (s_win == nullptr) {
            std::clog << "Can't create SDL window: " << SDL_GetError() << std::endl;
            exit(1);
        }

        s_ren = SDL_CreateRenderer(s_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (s_ren == nullptr) {
            std::clog << "Can't create SDL renderer: " << SDL_GetError() << std::endl;
            exit(1);
        }

        RGBA rgb(mainAreaColour);
        SDL_SetRenderDrawColor(s_ren, rgb.r, rgb.g, rgb.b, 0);
        SDL_RenderClear(s_ren);
        SDL_RenderPresent(s_ren);

    } else {
        //SDL_SetWindowPosition(s_win, x, y);
        //SDL_SetWindowSize(s_win, sizeX, sizeY);
    }
}


// ������� 1 ��������� �����
void kos_PutPixel( Dword x, Dword y, Dword colour )
{
    RGBA c(colour);
    SDL_SetRenderDrawColor(s_ren, c.r, c.g, c.b, c.a);
    SDL_RenderDrawPoint(s_ren, x, y);
}

// ������� 2 �������� ��� ������� �������
bool kos_GetKey( Byte &keyCode )
{
    static_cast<void>(keyCode);
    assert(0);
    return false;
}


// ������� 3 �������� �����
Dword kos_GetSystemClock()
{
    return 0;
}

// ������� 4
void kos_WriteTextToWindow(
	Word x,
	Word y,
	Byte fontType,
	Dword textColour,
	const char *textPtr,
	Dword textLen
	)
{
    static_cast<void>(fontType);
    static_cast<void>(textLen);

    std::clog << textPtr << std::endl;

    RGBA         color0(textColour);
    SDL_Color    color = SDL_Color();

    color.a = color0.a;
    color.b = color0.b;
    color.g = color0.g;
    color.r = color0.r;

    SDL_Surface *surf = TTF_RenderText_Blended(s_font, textPtr, color);
    if (surf == nullptr) {
        std::clog << "TTF_RenderText_Blended error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(s_ren, surf);
    if (texture == nullptr) {
        std::clog << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

    SDL_Rect rect {x, y, w, h};

    std::clog << "x="   << x
              << ", y=" << y
              << ", w=" << w
              << ", h=" << h
              << std::endl;

    SDL_RenderCopy(s_ren, texture, nullptr, &rect);
    //SDL_RenderPresent(s_ren);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surf);
}


// ������� 5 �����, � ����� ����� �������
void kos_Pause( Dword value )
{
    std::this_thread::sleep_for(std::chrono::milliseconds(value * 10));
}


// ������� 7 ���������� �����������
void kos_PutImage(const RGB * imagePtr, Word sizeX, Word sizeY, Word x, Word y )
{
    SDL_Texture *texture = SDL_CreateTexture(s_ren, SDL_PIXELFORMAT_BGR24, SDL_TEXTUREACCESS_STATIC, sizeX, sizeY);
    SDL_UpdateTexture(texture, nullptr, imagePtr, sizeX * sizeof(RGB));

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = sizeX;
    rect.h = sizeY;

    SDL_RenderCopy(s_ren, texture, nullptr, &rect);

    SDL_DestroyTexture(texture);
}



// ������� 8 ���������� ������
void kos_DefineButton( Word x, Word y, Word sizeX, Word sizeY, Dword buttonID, Dword colour )
{
    static_cast<void>(x);
    static_cast<void>(y);
    static_cast<void>(sizeX);
    static_cast<void>(sizeY);
    static_cast<void>(buttonID);
    static_cast<void>(colour);
    assert(0);
}


// ������� 9 - ���������� � ��������
Dword kos_ProcessInfo( sProcessInfo *targetPtr, Dword processID )
{
    static_cast<void>(targetPtr);
    static_cast<void>(processID);
    assert(0);
}


// ������� 10
Dword kos_WaitForEvent()
{
    // TODO: learn this function
    assert(0);
    return 0;
}


// ������� 11
Dword kos_CheckForEvent()
{
    assert(0);
    return 0;
}


// ������� 12
void kos_WindowRedrawStatus( Dword status )
{
    if (status == 2) {
        SDL_RenderPresent(s_ren);
    }
}


// ������� 13 ���������� ������
void kos_DrawBar( Word x, Word y, Word sizeX, Word sizeY, Dword colour )
{
    static_cast<void>(x);
    static_cast<void>(y);
    static_cast<void>(sizeX);
    static_cast<void>(sizeY);
    static_cast<void>(colour);
    assert(0);
}


// ������� 17
bool kos_GetButtonID( Dword &buttonID )
{
    static_cast<void>(buttonID);
    assert(0);
}


// ������� 23
Dword kos_WaitForEventTimeout( Dword timeOut )
{
    static_cast<void>(timeOut);
    assert(0);
}


// ��������� ���������� � ��������� "����" ������� 37
void kos_GetMouseState( Dword & buttons, int & cursorX, int & cursorY )
{
    static_cast<void>(buttons);
    static_cast<void>(cursorX);
    static_cast<void>(cursorY);
    assert(0);
}


// ������� 40 ���������� ����� �������
void kos_SetMaskForEvents( Dword mask )
{
    static_cast<void>(mask);
    assert(0);
}


// ������� 47 ������� � ���� ���������� �����
void kos_DisplayNumberToWindow(
   Dword value,
   Dword digitsNum,
   Word x,
   Word y,
   Dword colour,
   eNumberBase nBase,
   bool valueIsPointer
   )
{
    static_cast<void>(value);
    static_cast<void>(digitsNum);
    static_cast<void>(x);
    static_cast<void>(y);
    static_cast<void>(colour);
    static_cast<void>(nBase);
    static_cast<void>(valueIsPointer);
    assert(0);
}


// ������� 70 ������ � �������� �������
Dword kos_FileSystemAccess( kosFileInfo *fileInfo )
{
    static_cast<void>(fileInfo);
    assert(0);
}


// ������� 63 ����� ������� � ���� �������
void kos_DebugOutChar( char ccc )
{
    std::clog << ccc ;
}


// ������� 66 ����� ��������� ������ �� ����������
void kos_SetKeyboardDataMode( Dword mode )
{
    static_cast<void>(mode);
    assert(0);
}


// ����� ������ � ���� �������
void rtlDebugOutString( const char *str )
{
    std::clog << str << std::endl;
}


// ������� 64 ��������� ���������� ������, ���������� ��� ���������
bool kos_ApplicationMemoryResize( Dword targetSize )
{
    static_cast<void>(targetSize);
    // sbrk???
    assert(0);
}


// ������� 67 �������� ��������� ����, �������� == -1 �� ��������
void kos_ChangeWindow( Dword x, Dword y, Dword sizeX, Dword sizeY )
{
    static_cast<void>(x);
    static_cast<void>(y);
    static_cast<void>(sizeX);
    static_cast<void>(sizeY);
    assert(0);
}

void kos_InitHeap()
{
    assert(0);
}


void initGraph()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::clog << "SDL_Init error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init()) {
        std::clog << "TTF_Init error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    std::string fontFile {kosExePath};
    fontFile = fontFile.substr(0, fontFile.rfind('/')) + "/DejaVuSans.ttf";

    std::clog << "Path: '" << fontFile << "'" << std::endl;

    s_font = TTF_OpenFont(fontFile.c_str(), 12);
    if (s_font == nullptr) {
        std::clog << "TTF_OpenFont error: " << SDL_GetError() << std::endl;
        exit(1);
    }

}


void deinitGraph()
{
    TTF_CloseFont(s_font);
    TTF_Quit();
    SDL_Quit();
}

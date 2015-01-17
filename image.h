#ifndef __linux__
#include "smalllibc/kosSyst.h"
#else
#include "linux/kosSyst.h"
#endif

#define DRAW_NONE			0
#define DRAW_ALPHA			1
#define DRAW_ALPHA_ADD		2

class CKosImage
{
private:
	bool isColor;
	RGB color;
	int getPixel(int x, int y);
	Byte mode;
	int frame;
	int frameWidth;
	int frameHeight;
public:
    CKosImage(class CKosRender *render, RGBA *buffer, int width, int height);
	~CKosImage(void);

	void Draw(Point position, float angle, RGB color);
	void Draw(Point position, float angle);
	void Draw(Point position, float angle, int frame);
	void Draw(Point position, float angle, int frame, RGB color);
	void SetMode(int mode);
	void SetFrameSize(int width, int height);
protected:
	CKosRender *render;
	RGBA *buffer;
	int width;
	int height;
};

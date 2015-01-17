
class CKosRender
{
public:
	RGB *buffer;
	int width;
	int height;
	CKosRender(int width, int height);
	~CKosRender(void);

	void Draw(Point position);
	void RenderImg(RGB *img, Point position, int width, int height);
	int getPixel(int x, int y);
//	void DrawImage(CKosImage *img, int x, int y, int angle);

#if __cplusplus >= 201103L
    CKosRender(const CKosRender&) = delete;
    CKosRender& operator=(const CKosRender&) = delete;
    CKosRender(CKosRender&&) = default;
    CKosRender& operator=(CKosRender&&) = default;
#else
    CKosRender(const CKosRender&);
    CKosRender& operator=(const CKosRender&);
#endif
};

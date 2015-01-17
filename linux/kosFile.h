#pragma once

#include <cstdio>

class CKosFile
{
public:
    explicit CKosFile(const char *fileName);
    ~CKosFile();
	int	Read(Byte *targetPtr, int readCount);
	int Write(Byte *sourcePtr, int writeCount);
	int Seek(int seekFrom, int seekStep);
	void LoadTex(Byte *targetPtr, Byte Size, int width, int height);

private:
    FILE *m_fp = nullptr;
};

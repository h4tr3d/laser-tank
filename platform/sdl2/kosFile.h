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

    CKosFile(const CKosFile&) = delete;
    CKosFile& operator=(const CKosFile&) = delete;
    CKosFile(CKosFile&&) = default;
    CKosFile& operator=(CKosFile&&) = default;

private:
    FILE *m_fp = nullptr;
};

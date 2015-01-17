#include <exception>
#include <stdexcept>
#include <string>

#include <string.h>

#include "kosSyst.h"
#include "kosFile.h"

CKosFile::CKosFile(const char *fileName)
{
    m_fp = fopen(fileName, "rw+");
    if (!m_fp)
        throw std::runtime_error(std::string("can't open file: ") + fileName + ", error=" + strerror(errno) + " (" + std::to_string(errno) + ")");
}

CKosFile::~CKosFile()
{
    fclose(m_fp);
}

int CKosFile::Seek(int seekFrom, int seekStep)
{
    fseek(m_fp, seekFrom, seekStep);
    return ftell(m_fp);
}


int	CKosFile::Read(Byte *targetPtr, int readCount)
{
    size_t readed = fread(targetPtr, 1, readCount, m_fp);
    return readed;
}


int CKosFile::Write(Byte *sourcePtr, int writeCount)
{
	return 0;
}

void CKosFile::LoadTex(Byte *targetPtr, Byte Size, int width, int height)
{
	this->Read(targetPtr, width * height * Size);
}



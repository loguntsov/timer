//---------------------------------------------------------------------------

#ifndef ZipUnitH
#define ZipUnitH

#include "zlib.h";

// Класс для работы со сжатыми данными внутри одного файла в виде
// аналогичном TFileStream только данные сжимаются
// используется ZLib 1.1.4
class gzFileStream : public TStream
{
private:
    gzFile F;           
public:
    __fastcall gzFileStream(AnsiString File,const char *mode);
    // См. TFileStream
    __fastcall virtual ~gzFileStream();
    virtual int __fastcall Read(void *Buffer, int Count);
    virtual int __fastcall Write(const void *Buffer, int Count);
    virtual int __fastcall Seek(int Offset, Word Origin);    
    //virtual int __fastcall Seek(int Offset, Word Origin);     
};

//---------------------------------------------------------------------------
#endif

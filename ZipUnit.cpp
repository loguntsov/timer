//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ZipUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


// Класс для работы со сжатыми данными внутри одного файла в виде
// аналогичном TFileStream только данные сжимаются
// используется ZLib 1.1.4


__fastcall gzFileStream::gzFileStream(AnsiString File,const char *mode):TStream()
// См. TFileStream
{
    F=gzopen(File.c_str(),mode);// fopen

};
__fastcall  gzFileStream::~gzFileStream()
{
    gzclose(F);
}
int __fastcall gzFileStream::Read(void *Buffer, int Count)
{
    int a=gzread(F,Buffer,Count);
    return a;

}
int __fastcall gzFileStream::Write(const void *Buffer, int Count)
{
    int a=gzwrite(F, Buffer,Count);
    SetSize(Size+a);
    return a;
}
int __fastcall gzFileStream::Seek(int Offset, Word Origin)
{
    int pos;
    switch(Origin)
    {
        case soFromCurrent :
            pos=(int) gzseek(F,Offset,SEEK_CUR);
            break;
        case soFromEnd :
            pos=(int) gzseek(F,Offset,SEEK_END);
            break;
        default:
            pos=(int) gzseek(F,Offset,SEEK_SET);
    }
    //if (pos<0) pos=Position;
    return pos;
}


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SkinClass.h"
#include "ZipUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

SkinClass::SkinClass(TImageList *NumbrNoChange)
{
    Num=NumbrNoChange;
    Numbr=new TImageList(Application);
    BtnRun=new Graphics::TBitmap;
    BtnStop=new Graphics::TBitmap;
    ForeGround=new Graphics::TBitmap;
    BarActivate=new Graphics::TBitmap;
    BarDeactivate=new Graphics::TBitmap;
    LoadSkinFromFolder("");
}

SkinClass::~SkinClass()
{
    delete BarActivate,BarDeactivate,BtnRun,BtnStop,ForeGround;
}
int SkinClass::LoadSkinFromFolder(AnsiString Path)
{
    if (Path=="")
    {
        BarActivate->LoadFromResourceName(0,"BARACTIVATE");
        BarDeactivate->LoadFromResourceName(0,"BARDEACTIVATE");
        BtnRun->LoadFromResourceName(0,"BTNRUN");
        BtnStop->LoadFromResourceName(0,"BTNSTOP");
        ForeGround->LoadFromResourceName(0,"FOREGROUND");
        Numbr->Clear();
        Numbr->Height=Num->Height;
        Numbr->Width=Num->Width;
        Numbr->AddImages(Num);
    } else
    {
        Path=Path+"\\";
        BarActivate->LoadFromFile(Path+"BARACTIVATE.bmp");
        BarDeactivate->LoadFromFile(Path+"BARDEACTIVATE.bmp");
        BtnRun->LoadFromFile(Path+"BTNRUN.bmp");
        BtnStop->LoadFromFile(Path+"BTNSTOP.bmp");
        ForeGround->LoadFromFile(Path+"MAIN.bmp");
        Path=Path+"\\Numbers\\";
        Numbr->Clear();
        Graphics::TBitmap *a=new Graphics::TBitmap;
        Graphics::TBitmap *b=new Graphics::TBitmap;
        b->Width=Numbr->Width;
        b->Height=Numbr->Height;
        for(int i=0;i<10;i++)
        {
            a->LoadFromFile(Path+AnsiString(i)+".bmp");
            b->Canvas->CopyRect(TRect(0,0,b->Width,b->Height),a->Canvas,TRect(0,0,a->Width,a->Height));
            Numbr->Add(b,NULL);
        }
        delete a,b;
    }
    Type=tmFolder;
    return 0;
}
int SkinClass::SaveSkinToFolder(AnsiString Path)
{
    return 0;
}
int SkinClass::LoadSkinFromTSK(AnsiString File)
{
    gzFileStream *gz=new gzFileStream(File,"rb");
    Graphics::TBitmap *a=new Graphics::TBitmap;
    Graphics::TBitmap *b=new Graphics::TBitmap;    
    Numbr->Clear();
    b->Width=Numbr->Width;
    b->Height=Numbr->Height;
    for(int i=0;i<10;i++)
    {
        a->LoadFromStream(gz);
        b->Canvas->CopyRect(TRect(0,0,b->Width,b->Height),a->Canvas,TRect(0,0,a->Width,a->Height));
        Numbr->Add(b,NULL);
    }
    delete a,b;
    BarActivate->LoadFromStream(gz);
    BarActivate->LoadFromStream(gz);
    BarDeactivate->LoadFromStream(gz);
    BtnRun->LoadFromStream(gz);
    BtnStop->LoadFromStream(gz);
    ForeGround->LoadFromStream(gz);
    delete gz;
    Type=tmFile;
    return 0;
}
int SkinClass::SaveSkinToTSK(AnsiString File)
{
    gzFileStream *gz=new gzFileStream(File,"wb9");
    Graphics::TBitmap *a=new Graphics::TBitmap;
    for(int i=0;i<10;i++)
    {
        Numbr->GetBitmap(i,a);
        a->SaveToStream(gz);
    }
    BarActivate->SaveToStream(gz);
    BarActivate->SaveToStream(gz);
    BarDeactivate->SaveToStream(gz);
    BtnRun->SaveToStream(gz);
    BtnStop->SaveToStream(gz);
    ForeGround->SaveToStream(gz);
    delete gz,a;
    return 0;
}


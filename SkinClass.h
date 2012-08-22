//---------------------------------------------------------------------------

#ifndef SkinClassH
#define SkinClassH

#include "GlobalModule.h"

class SkinClass
{
private:
    TImageList *Num;
public:
    SkinClass(TImageList *NumbrNoChange);
    ~SkinClass();
    int LoadSkinFromFolder(AnsiString Folder);
    int SaveSkinToFolder(AnsiString Folder);
    int LoadSkinFromTSK(AnsiString File);
    int SaveSkinToTSK(AnsiString File);
    TimerSkinType Type;
//protected:
    Graphics::TBitmap *BarActivate;
    Graphics::TBitmap *BarDeactivate;
    Graphics::TBitmap *BtnRun;
    Graphics::TBitmap *BtnStop;
    Graphics::TBitmap *ForeGround;
    TImageList *Numbr;
};
//---------------------------------------------------------------------------
#endif

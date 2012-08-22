//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "Unit3.h"
#include "Language.h"
#include "TimerClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Timer1Timer(TObject *Sender)
{

lblText->Visible= ! lblText->Visible;
Application->RestoreTopMosts();
Application->NormalizeTopMosts();
Application->NormalizeAllTopMosts();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void TForm3::PlayForm(AnsiString Str)
{
    if (Str!="") lblText->Caption=Str;
    Width=Screen->Width;
    Height=Screen->Height;
    Left=0;
    Top=0;
    FormStyle=fsStayOnTop;
    Application->NormalizeAllTopMosts();
    Timer1->Enabled=true;
    TimerClass->Play("");    
    ShowModal();
}


void __fastcall TForm3::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_ESCAPE) Close();
}
//---------------------------------------------------------------------------
void TForm3::RefreshLang(void)
{
   BEG_LANG
   LANGSECTION("EndTimeForm\\Hint");
   LANGCONTROLHINT(this);
   LANGSECTION("EndTimeForm\\Caption");
   LANGCONTROLCAPTION(this);
   END_LANG
}
void __fastcall TForm3::FormCreate(TObject *Sender)
{
    RefreshLang();
}
//---------------------------------------------------------------------------


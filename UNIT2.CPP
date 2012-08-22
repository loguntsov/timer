//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GlobalModule.h"
#include "Unit2.h"
#include "Language.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
static int b=0;
b++;
if (b>11) {b=0;}
ImageList1->GetIcon(b,Image1->Picture->Icon);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
/*static int a=0;
Image2->Canvas->Rectangle(0,0,Image2->Width,Image2->Height);
for(int i=0;i<Memo1->Lines->Count;i++)
{
   Image1->Canvas->TextOut(0,a,Memo1->Lines->Strings[i]);
}
a--;*/
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{
//Timer1->Enabled=true;
Timer2->Enabled=true;
lblVersion->Caption=Model;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormDeactivate(TObject *Sender)
{
//Timer1->Enabled=false;
Timer2->Enabled=false;
}
//---------------------------------------------------------------------------
extern int ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd);

void __fastcall TForm2::HelpButtonClick(TObject *Sender)
{
    Close();
    WebBrowserOpenURL((CurDir+"\\Help\\Index.htm").c_str());
}
//---------------------------------------------------------------------------
void TForm2::RefreshLang(void)
{
    BEG_LANG
    LANGSECTION("AboutForm\\Hint");
    LANGCONTROLHINT(this);
    LANGSECTION("AboutForm\\Caption");
    LANGCONTROLCAPTION(this);
    END_LANG
}
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    RefreshLang();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyPress(TObject *Sender, char &Key)
{
    if (Key==27) Close();
}
//---------------------------------------------------------------------------


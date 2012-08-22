//---------------------------------------------------------------------------
#include <vcl.h>
#include <registry.hpp>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
extern TForm1 *Form1;

extern TRegIniFile *IniFile;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (! state) {
x0=X;
y0=Y;
state=True;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (state) {
            state=False;
            IniFile->WriteInteger("Position","Xsmail",Left);
            IniFile->WriteInteger("Position","Ysmail",Top);
            }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
int XLeft,YTop;
if (state) {
            XLeft=Left+X-x0;
            YTop=Top+Y-y0;
            if (abs(XLeft)<15) { XLeft=0; }
            if (abs(YTop)<15) { YTop=0; }
            if (abs(XLeft+Width-Screen->Width)<15) XLeft=Screen->Width-Width;
            if (abs(YTop+Height-Screen->Height)<15) YTop=Screen->Height-Height;
            Left=XLeft;
            Top=YTop;
            }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
Label1->Visible=! Label1->Visible;
OnPaint;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer2Timer(TObject *Sender)
{
Form4->FormStyle=fsStayOnTop;
Application->NormalizeTopMosts();
Application->NormalizeAllTopMosts();
Application->RestoreTopMosts();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Splitter1Moved(TObject *Sender)
{
IniFile->WriteInteger("Option","Splitter",ProgressBar1->Width);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N1Click(TObject *Sender)
{
Form1->Show();
Hide();
//Form1->FormState=apShow;
Form1->SetFocus();
//Form1->MediaPlayer1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::FormShow(TObject *Sender)
{
ProgressBar1->Width=IniFile->ReadInteger("Option","Splitter",70);
}
//---------------------------------------------------------------------------


void __fastcall TForm4::FormPaint(TObject *Sender)
{
Canvas->Draw(0,0,BackGround);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N2Click(TObject *Sender)
{
Application->Minimize();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::ProgressBar1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (! stateResize) {
    x0=X;
    y0=Y;
    stateResize=True;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ProgressBar1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
int XLeft;
if (stateResize) {
            XLeft=Width+X-x0;
            if (XLeft<50) XLeft=50;
            if (XLeft>240) XLeft=240;
            Width=XLeft;
            }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ProgressBar1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (stateResize) {
            stateResize=false;
            //IniFile->WriteInteger("Position","Xsmail",Left);
            //IniFile->WriteInteger("Position","Ysmail",Top);
            }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
Left=IniFile->ReadInteger("Position","Xsmail",100);
Top=IniFile->ReadInteger("Position","Ysmail",100);
state=stateResize=false;
BackGround = new Graphics::TBitmap();
AnsiString a=IniFile->ReadString("Skins","FileDirectory","");
if (a!="") BackGround->LoadFromFile(a+"\\Title.bmp"); else
    ImageList1->GetBitmap(0,BackGround);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormDestroy(TObject *Sender)
{
delete BackGround;
}
//---------------------------------------------------------------------------


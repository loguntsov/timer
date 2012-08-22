//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OutFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOutForm *OutForm;
//---------------------------------------------------------------------------
__fastcall TOutForm::TOutForm(TComponent* Owner)
    : TForm(Owner)
{
}
Graphics::TBitmap *BMP;
//---------------------------------------------------------------------------
void __fastcall TOutForm::Timer1Timer(TObject *Sender)
{
static f=true;
Canvas->Draw(0,0,BMP);
AnsiString Text="Время истекло!!!";
if (f)
    {
        Canvas->Font->Size=60;
        Canvas->Font->Name="Comic Sans MS";
        Canvas->Font->Color=clRed;
        int x=Width/2-Canvas->TextWidth(Text)/2;
        int y=Height/2-Canvas->TextHeight(Text)/2;
        Canvas->Brush->Style=bsClear;
        Canvas->TextOut(x,y,Text);
    }
f=!f;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TOutForm::FormPaint(TObject *Sender)
{
Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------

void __fastcall TOutForm::FormShow(TObject *Sender)
{
BMP=new Graphics::TBitmap;
BMP->Width=Screen->Width;
BMP->Height=Screen->Height;
Width=Screen->Width;
Height=Screen->Height;
Left=0;Top=0;
BitBlt(BMP->Canvas->Handle,0,0,Width,Height,GetDC(GetDesktopWindow()),0,0,SRCCOPY);
//BMP->Canvas->Brush->Style=bsFDiagonal;
//BMP->Canvas->Brush->Color=clBtnFace;
//BMP->Canvas->Rectangle(0, 0, Width, Height);
Canvas->Draw(0,0,BMP);
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TOutForm::FormClick(TObject *Sender)
{
Timer1->Enabled=false;
delete BMP;
Close();
}
//---------------------------------------------------------------------------


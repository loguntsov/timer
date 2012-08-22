//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Play(Graphics::TBitmap *bmp,AnsiString String)
{
    Width=Screen->Width;
    Height=Screen->Height;
    Left=0;Top=0;
    BMP=bmp;
    //BitBlt(BMP->Canvas->Handle,0,0,Width,Height,GetDC(GetDesktopWindow()),0,0,SRCCOPY);
    //BMP->Canvas->Brush->Style=bsFDiagonal;
    //BMP->Canvas->Brush->Color=clBtnFace;
    //BMP->Canvas->Rectangle(0, 0, Width, Height);
    Canvas->Draw(0,0,BMP);
    FormStyle=fsStayOnTop;
    Timer1->Enabled=true;
    Text=String;
    ShowModal();
}
void __fastcall TForm6::Timer1Timer(TObject *Sender)
{
    static f=true;
    if (BMP!=NULL)
    {
        Canvas->Draw(0,0,BMP);
    } else
    {
        Canvas->Brush->Color = clBlack;
        Canvas->Brush->Style = bsSolid;		
        Canvas->FillRect(Rect(0,0,Width,Height));
    }
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
    Application->NormalizeTopMosts();
    Application->NormalizeAllTopMosts();
    Application->RestoreTopMosts();
}
//---------------------------------------------------------------------------


void __fastcall TForm6::FormClick(TObject *Sender)
{
Timer1->Enabled=false;
Close();
}
//---------------------------------------------------------------------------


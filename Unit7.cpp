//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <registry.hpp>
#include "Unit7.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
extern TRegIniFile *IniFile;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton1Click(TObject *Sender)
{
if (ColorDialog1->Execute())
    {
        //ProgressBar->ColBegLeft=ColorDialog1->Color;
        Label2->Color=ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton2Click(TObject *Sender)
{
if (ColorDialog1->Execute())
    {
        //ProgressBar->ColEndLeft=ColorDialog1->Color;
        Label3->Color=ColorDialog1->Color;        
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::SpeedButton4Click(TObject *Sender)
{
if (ColorDialog1->Execute())
    {
        //ProgressBar->ColBegRight=ColorDialog1->Color;
        Label4->Color=ColorDialog1->Color;        
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm7::SpeedButton3Click(TObject *Sender)
{
if (ColorDialog1->Execute())
    {
        //ProgressBar->ColEndRight=ColorDialog1->Color;
        Label5->Color=ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ScrollBar1Change(TObject *Sender)
{
Label1->Caption=IntToStr(ScrollBar1->Position)+" %";
//ProgressBar->Position=ScrollBar1->Position;
//if (!Form1->Timer1->Enabled) Form1->ProgressBar1->Position=float(ScrollBar1->Position)/100*Form1->ProgressBar1->Max;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BtOkClick(TObject *Sender)
{
    Button1Click(this);
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
//    Form1->ProgressBar1->ColBegLeft=ProgressBar->ColBegLeft;
//    Form1->ProgressBar1->ColBegRight=ProgressBar->ColBegRight;
//    Form1->ProgressBar1->ColEndLeft=ProgressBar->ColEndLeft;
//    Form1->ProgressBar1->ColEndRight=ProgressBar->ColEndRight;
//    IniFile->WriteInteger("Option","ColBegLeft",ProgressBar->ColBegLeft);
//    IniFile->WriteInteger("Option","ColBegRight",ProgressBar->ColBegRight);
//    IniFile->WriteInteger("Option","ColEndLeft",ProgressBar->ColEndLeft);
//    IniFile->WriteInteger("Option","ColEndRight",ProgressBar->ColEndRight);
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormCreate(TObject *Sender)
{
//ProgressBar->ColBegLeft=TColor(IniFile->ReadInteger("Option","ColBegLeft",clRed));
//ProgressBar->ColBegRight=TColor(IniFile->ReadInteger("Option","ColBegRight",clBlue));
//ProgressBar->ColEndLeft=TColor(IniFile->ReadInteger("Option","ColEndLeft",clBlue));
//ProgressBar->ColEndRight=TColor(IniFile->ReadInteger("Option","ColEndRight",clRed));
//Label2->Color=ProgressBar->ColBegLeft;
//Label3->Color=ProgressBar->ColEndLeft;
//Label4->Color=ProgressBar->ColBegRight;
//Label5->Color=ProgressBar->ColEndRight;
}
//---------------------------------------------------------------------------


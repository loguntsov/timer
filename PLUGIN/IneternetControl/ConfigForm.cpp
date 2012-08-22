//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfigForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfigF *ConfigF;
//---------------------------------------------------------------------------
__fastcall TConfigF::TConfigF(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfigF::ComboBox1Change(TObject *Sender)
{
Label2->Caption=ComboBox1->Items->Strings[ComboBox1->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TConfigF::ComboBox2Change(TObject *Sender)
{
Label3->Caption=ComboBox2->Items->Strings[ComboBox2->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TConfigF::ComboBox3Change(TObject *Sender)
{
Label4->Caption=ComboBox3->Items->Strings[ComboBox3->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TConfigF::ComboBox4Change(TObject *Sender)
{
Label5->Caption=ComboBox4->Items->Strings[ComboBox4->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TConfigF::ComboBox5Change(TObject *Sender)
{
Label6->Caption=ComboBox5->Items->Strings[ComboBox5->ItemIndex];
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitInfoForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInfoForm *InfoForm;
//---------------------------------------------------------------------------
__fastcall TInfoForm::TInfoForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInfoForm::FormCreate(TObject *Sender)
{
    FormStyle = fsStayOnTop;
    Left=Screen->Width-Width-100;
    Top=0;
}
//---------------------------------------------------------------------------


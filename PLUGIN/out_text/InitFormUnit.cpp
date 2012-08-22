//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InitFormUnit.h"
#include "TimerPlugin.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInitForm *InitForm;
//---------------------------------------------------------------------------
__fastcall TInitForm::TInitForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TInitForm::Button1Click(TObject *Sender)
{
Timer.StickFormEndMove();
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::FormCreate(TObject *Sender)
{
Timer.AddStickForm(Handle);
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::FormDestroy(TObject *Sender)
{
Timer.DeleteStickForm(Handle);
}
//---------------------------------------------------------------------------


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

int Cur=0;
long Tim[100];
//---------------------------------------------------------------------------

void __fastcall TInitForm::FormCreate(TObject *Sender)
{
Timer.AddStickForm(Handle);
cbTaskList->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::FormDestroy(TObject *Sender)
{
Timer.DeleteStickForm(Handle);
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::SpeedButton1Click(TObject *Sender)
{

    Tim[Cur]=Timer.GetTime();
    cbTaskList->ItemIndex=cbTaskList->Items->Add("");
    Timer.SetTime(0);
    Cur=cbTaskList->ItemIndex;
    Tim[Cur]=0;
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::cbTaskListClick(TObject *Sender)
{
    if (Cur>0) Tim[Cur]=Timer.GetTime();
    Cur=cbTaskList->ItemIndex;
    Timer.SetTime(Tim[Cur]);
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::cbTaskListKeyPress(TObject *Sender, char &Key)
{
    cbTaskList->Items->Strings[Cur]=cbTaskList->Text+AnsiString(Key);
}
//---------------------------------------------------------------------------


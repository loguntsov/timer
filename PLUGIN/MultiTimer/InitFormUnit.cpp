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
cbTaskList->Items->Add(Timer.GetFormMessage());
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
    cbTaskList->Items->Strings[Cur]=Timer.GetFormMessage();
    cbTaskList->ItemIndex=cbTaskList->Items->Add("");
    Timer.SetTime(0);
    Cur=cbTaskList->ItemIndex;
    Tim[Cur]=0;
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::cbTaskListClick(TObject *Sender)
{
    if (Cur>=0)
    {
        Tim[Cur]=Timer.GetTime();
        cbTaskList->Items->Strings[Cur]=Timer.GetFormMessage();
    }
    Cur=cbTaskList->ItemIndex;
    Timer.SetFormMessage(cbTaskList->Items->Strings[Cur].c_str());
    Timer.SetTime(Tim[Cur]);
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::cbTaskListKeyPress(TObject *Sender, char &Key)
{
    cbTaskList->Items->Strings[Cur]=cbTaskList->Text+AnsiString(Key);
    Timer.SetFormMessage(cbTaskList->Items->Strings[Cur].c_str());
}
//---------------------------------------------------------------------------
bool f=false;;
int X0,Y0;
void __fastcall TInitForm::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (!f)
    {
        X0=Left;
        Y0=Top;
        f=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if (f)
    {
        Left=Left+X;
        Top=Top+Y;
    }
}
//---------------------------------------------------------------------------

void __fastcall TInitForm::Image1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    f=false;
    Timer.StickFormEndMove();
}
//---------------------------------------------------------------------------


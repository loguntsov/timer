//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitConfigForm.h"
#include "TimerPlugin.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfigForm *ConfigForm;
//---------------------------------------------------------------------------
__fastcall TConfigForm::TConfigForm(TComponent* Owner)
    : TForm(Owner)
{
    IsClosed=true;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::Button1Click(TObject *Sender)
{
    if (OpenDialog1->Execute())
    {
        ExecFileName->Text=OpenDialog1->FileName;
    }
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::Button2Click(TObject *Sender)
{
    Close();
    IsClosed=false;
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::Button3Click(TObject *Sender)
{
    char *str=(AnsiString(Timer.GetPluginDir())+"\\RunProgram\\Help.htm").c_str();
    Timer.WebBrowserOpenURL(str);
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::ExecFileNameChange(TObject *Sender)
{
    Timer.PrmWriteString("RunProgram","FileName",ExecFileName->Text.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::StartModeClick(TObject *Sender)
{
    Timer.PrmWriteInteger("RunProgram","StartMode",StartMode->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::AutoDelClick(TObject *Sender)
{
    Timer.PrmWriteInteger("RunProgram","AutoDel",AutoDel->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::AutoShutDownClick(TObject *Sender)
{
    Timer.PrmWriteInteger("RunProgram","AutoShutDown",AutoShutDown->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::MessageShutDownClick(TObject *Sender)
{
    Timer.PrmWriteInteger("RunProgram","MessageShutDown",MessageShutDown->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::FormCreate(TObject *Sender)
{
    StartMode->Checked=Timer.PrmReadInteger("RunProgram","StartMode",true);
    ExecFileName->Text=Timer.PrmReadString("RunProgram","FileName","");
    AutoDel->Checked=Timer.PrmReadInteger("RunProgram","AutoDel",false);
    AutoShutDown->Checked=Timer.PrmReadInteger("RunProgram","AutoShutDown",false);
    MessageShutDown->Checked=Timer.PrmReadInteger("RunProgram","MessageShutDown",false);
}
//---------------------------------------------------------------------------



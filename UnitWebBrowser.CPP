//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitWebBrowser.h"
#include "GlobalModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TWebBrowserForm *WebBrowserForm=NULL;;
//---------------------------------------------------------------------------
__fastcall TWebBrowserForm::TWebBrowserForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWebBrowserForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    DeleteStickForm(Handle);
    WebBrowserForm=NULL;
    delete this;

}
//---------------------------------------------------------------------------
void  __fastcall TWebBrowserForm::OpenURL(AnsiString URL)
{
    Web->Navigate(WideString(URL));
}


void __fastcall TWebBrowserForm::SpeedButton1Click(TObject *Sender)
{
    if (OpenDialog->Execute())
    {
        OpenURL(OpenDialog->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TWebBrowserForm::SpeedButton4Click(TObject *Sender)
{
    Web->GoBack();    
}
//---------------------------------------------------------------------------

void __fastcall TWebBrowserForm::SpeedButton5Click(TObject *Sender)
{
    Web->GoForward();    
}
//---------------------------------------------------------------------------

void __fastcall TWebBrowserForm::SpeedButton2Click(TObject *Sender)
{
    Web->Refresh();    
}
//---------------------------------------------------------------------------

void __fastcall TWebBrowserForm::SpeedButton3Click(TObject *Sender)
{
    Web->Stop();    
}
//---------------------------------------------------------------------------


void __fastcall TWebBrowserForm::FormResize(TObject *Sender)
{
    StickFormEndMove();
}
//---------------------------------------------------------------------------


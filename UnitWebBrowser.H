//---------------------------------------------------------------------------

#ifndef UnitWebBrowserH
#define UnitWebBrowserH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TWebBrowserForm : public TForm
{
__published:	// IDE-managed Components
    TCppWebBrowser *Web;
    TPanel *Panel1;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton5;
    TOpenDialog *OpenDialog;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWebBrowserForm(TComponent* Owner);
    void __fastcall OpenURL(AnsiString URL);
};
//---------------------------------------------------------------------------
extern TWebBrowserForm *WebBrowserForm;
//---------------------------------------------------------------------------
#endif

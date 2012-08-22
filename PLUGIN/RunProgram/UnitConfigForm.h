//---------------------------------------------------------------------------

#ifndef UnitConfigFormH
#define UnitConfigFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TConfigForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *ExecFileName;
    TButton *Button1;
    TOpenDialog *OpenDialog1;
    TButton *Button2;
    TCheckBox *StartMode;
    TCheckBox *AutoDel;
    TCheckBox *AutoShutDown;
    TCheckBox *MessageShutDown;
    TButton *Button3;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall ExecFileNameChange(TObject *Sender);
    void __fastcall StartModeClick(TObject *Sender);
    void __fastcall AutoDelClick(TObject *Sender);
    void __fastcall AutoShutDownClick(TObject *Sender);
    void __fastcall MessageShutDownClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TConfigForm(TComponent* Owner);
    bool IsClosed;
};
//---------------------------------------------------------------------------
extern PACKAGE TConfigForm *ConfigForm;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef InitFormUnitH
#define InitFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
extern int Cur;
extern long Tim[];
class TInitForm : public TForm
{
__published:	// IDE-managed Components
    TComboBox *cbTaskList;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TImage *Image1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall cbTaskListClick(TObject *Sender);
    void __fastcall cbTaskListKeyPress(TObject *Sender, char &Key);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TInitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInitForm *InitForm;
//---------------------------------------------------------------------------
#endif


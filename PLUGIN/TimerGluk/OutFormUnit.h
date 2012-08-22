//---------------------------------------------------------------------------

#ifndef OutFormUnitH
#define OutFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOutForm : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TOutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOutForm *OutForm;
//---------------------------------------------------------------------------
#endif

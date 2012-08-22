//---------------------------------------------------------------------------

#ifndef InitFormUnitH
#define InitFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TInitForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TInitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInitForm *InitForm;
//---------------------------------------------------------------------------
#endif


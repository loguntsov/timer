//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
    Graphics::TBitmap *BMP;
    AnsiString Text;
public:		// User declarations
    __fastcall TForm6(TComponent* Owner);

    void __fastcall Play(Graphics::TBitmap *BMP,AnsiString String);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
 
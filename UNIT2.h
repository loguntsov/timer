//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TLabel *lblName;
    TTimer *Timer2;
    TImageList *ImageList1;
    TLabel *lblVersion;
    TSpeedButton *Button1;
    TSpeedButton *HelpButton;
    TLabel *lblAuthor;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormDeactivate(TObject *Sender);
    void __fastcall HelpButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
    void RefreshLang(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton1;
    TGroupBox *GroupBox2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TScrollBar *ScrollBar1;
    TLabel *Label1;
    TButton *BtOk;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TColorDialog *ColorDialog1;
    TButton *Button1;
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall ScrollBar1Change(TObject *Sender);
    
    void __fastcall BtOkClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif

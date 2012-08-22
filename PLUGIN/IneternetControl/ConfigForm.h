//---------------------------------------------------------------------------

#ifndef ConfigFormH
#define ConfigFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TConfigF : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TComboBox *ComboBox1;
    TEdit *Edit1;
    TLabel *Label1;
    TLabel *Label2;
    TComboBox *ComboBox2;
    TEdit *Edit2;
    TLabel *Label3;
    TComboBox *ComboBox3;
    TEdit *Edit3;
    TLabel *Label4;
    TComboBox *ComboBox4;
    TEdit *Edit4;
    TLabel *Label5;
    TComboBox *ComboBox5;
    TEdit *Edit5;
    TLabel *Label6;
    TEdit *Edit6;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *Edit7;
    TBitBtn *BitBtn1;
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall ComboBox2Change(TObject *Sender);
    void __fastcall ComboBox3Change(TObject *Sender);
    void __fastcall ComboBox4Change(TObject *Sender);
    void __fastcall ComboBox5Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TConfigF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfigF *ConfigF;
//---------------------------------------------------------------------------
#endif

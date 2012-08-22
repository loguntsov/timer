//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TTimer *Timer1;
    TTimer *Timer2;
    TLabel *Label1;
    TProgressBar *ProgressBar1;
    TSplitter *Splitter1;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TImageList *ImageList1;
    TMenuItem *N2;
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    
    void __fastcall Timer1Timer(TObject *Sender);
    
    
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall Splitter1Moved(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    
    void __fastcall ProgressBar1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ProgressBar1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall ProgressBar1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        int x0,y0;
        bool state,stateResize;
public:		// User declarations
    __fastcall TForm4(TComponent* Owner);
    Graphics::TBitmap *BackGround;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif

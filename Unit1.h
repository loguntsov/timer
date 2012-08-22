//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

#include "TimerClass.h"
#include "NumImage.h"
#include <Graphics.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <MPlayer.hpp>
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    TImageList *NumForBaseSkin;
    TUpDown *UpDownSek;
    TNumImage *NumImage6;
    TNumImage *NumImage5;
    TUpDown *UpDownMin;
    TNumImage *NumImage4;
    TNumImage *NumImage3;
    TUpDown *UpDownHour;
    TNumImage *NumImage2;
    TNumImage *NumImage1;
    TSpeedButton *Btn;
    TSpeedButton *ButMenu;
    TImage *Bar;
    TSpeedButton *ButMinimize;
    TSpeedButton *ButRecov;
    TSpeedButton *ButClose;
    TPopupMenu *PopUpMenu;
    TMenuItem *mnuExit;
    TActionList *Actions;
    TAction *acExit;
    TAction *acMinimize;
    TImageList *MenuIcons;
    TAction *acAbout;
    TMenuItem *mnuAbout;
    TMenuItem *N1;
    TMenuItem *N2;
    TAction *acOption;
    TMenuItem *mnuPreference;
    TImageList *NumForSkin;
    TMenuItem *mnuWebBrowser;
    TMenuItem *mnuOption;
    TMenuItem *mnuMessage;
    TMenuItem *mnuPlayToFile;
    TMenuItem *mnuAlwaysOnTop;
    TMenuItem *mnuMinimizeInSysTray;
    TMediaPlayer *Player;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall UpDownSekClick(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDownMinClick(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDownHourClick(TObject *Sender, TUDBtnType Button);
    void __fastcall BtnClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall BarMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall BarMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
    void __fastcall BarMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall acExitExecute(TObject *Sender);
    void __fastcall acMinimizeExecute(TObject *Sender);
    void __fastcall ButMenuClick(TObject *Sender);
    void __fastcall acAboutExecute(TObject *Sender);
    void __fastcall acOptionExecute(TObject *Sender);
    void __fastcall mnuMessageClick(TObject *Sender);
    void __fastcall mnuPlayToFileClick(TObject *Sender);
    void __fastcall mnuAlwaysOnTopClick(TObject *Sender);
    void __fastcall mnuMinimizeInSysTrayClick(TObject *Sender);
    void __fastcall mnuWebBrowserClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    int x0,y0;
    bool FormMove;
    void LangRefresh(void);
    void __fastcall MsgSysTray(TMessage& Msg); // Cсообщение на реакцию в SystemTray
BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(msgSysTray,TMessage,MsgSysTray)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

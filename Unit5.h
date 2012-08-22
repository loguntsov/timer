//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Tabnotbk.hpp>
#include <Dialogs.hpp>
#include <FileCtrl.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *Page;
    TTabSheet *TabSetup;
    TTabSheet *TabSkins;
    TTabSheet *TabOptions;
    TTabSheet *TabPlugin;
    TGroupBox *LangGroupBox;
    TButton *ButLanguage;
    TButton *ButAddDesktop;
    TButton *ButAddQuickLaunch;
    TButton *ButAddStartMenu;
    TOpenDialog *OpenDialogForSetup;
    TButton *Button5;
    TButton *butBrowse;
    TOpenDialog *OpenDialogForPlay;
    TCheckBox *ckbAlwaysOnTop;
    TCheckBox *ckbMessage;
    TCheckBox *ckbPlayMusic;
    TCheckBox *ckbMinimizeInSysTray;
    TCheckListBox *PluginList;
    TBitBtn *butAddPlug;
    TBitBtn *butDelPlug;
    TBitBtn *butPlugUp;
    TBitBtn *butPlugDown;
    TPopupMenu *pmAddPlug;
    TBitBtn *butPlugAbiut;
    TBitBtn *butPlagConfig;
    TPageControl *SkinPage;
    TTabSheet *tabSkinsInFile;
    TListBox *SkinBox;
    TPopupMenu *pmSkinsInFolder;
    TTabSheet *tabSkinsInFolder;
    TMenuItem *mnuSaveSkinToFile;
    TPopupMenu *pmSkinsInFile;
    TMenuItem *mnuSaveSkinToFolder;
    TSaveDialog *dlgSaveSkinToFile;
    TListBox *FileSkinBox;
    TRadioGroup *rgForAlert;
    TEdit *eOther;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButLanguageClick(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall ckbMessageClick(TObject *Sender);
    void __fastcall ckbPlayMusicClick(TObject *Sender);
    void __fastcall ckbAlwaysOnTopClick(TObject *Sender);
    void __fastcall ckbMinimizeInSysTrayClick(TObject *Sender);
    void __fastcall butBrowseClick(TObject *Sender);
    void __fastcall butAddPlugClick(TObject *Sender);
    void __fastcall butPlagConfigClick(TObject *Sender);
    void __fastcall butPlugAbiutClick(TObject *Sender);
    void __fastcall butDelPlugClick(TObject *Sender);
    void __fastcall butPlugUpClick(TObject *Sender);
    void __fastcall butPlugDownClick(TObject *Sender);
    void __fastcall SkinBoxClick(TObject *Sender);
    void __fastcall mnuSaveSkinToFileClick(TObject *Sender);
    void __fastcall FileSkinBoxClick(TObject *Sender);
    void __fastcall ButAddDesktopClick(TObject *Sender);
    void __fastcall ButAddQuickLaunchClick(TObject *Sender);
    void __fastcall ButAddStartMenuClick(TObject *Sender);
    void __fastcall rgForAlertClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm5(TComponent* Owner);
    void __fastcall AddPlugin(TObject *Sender);    
    void RefreshLang(void);
    void CreateShortCut(AnsiString FileName);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif

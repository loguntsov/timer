//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "GlobalModule.h"
#include "Unit6.h"
#include "Unit1.h"
#include "Unit4.h"
#include "UnitWebBrowser.h"
#include "Language.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


// Модуль для описания глобальных функций.

TIMERAPISTRUCT TimerPlugin;
AnsiString CurDir=GetCurrentDir();
TRegIniFile *IniFile = new TRegIniFile("Timer");
TPlugin *PlugOutPut;

// StickForm
TList *StickForms;
StickForm::StickForm(HWND FormS)
{
    Form=FormS;IsStick=false;
}

int FindStickForm(HWND Form)
{
    for(int i=0;i<StickForms->Count;i++)
    {
        if (((StickForm *) StickForms->Items[i])->Form==Form) return i;
    }
    return -1;
}

void StickFormMoveNotStick(HWND Form,int NewLeft,int NewTop);

void WINAPI StickFormResize(HWND Form,int NewWidth,int NewHeight) // Вызывается при изменении размеров формы плагина
{
    int n=FindStickForm(Form);
    if (n>-1)
    {
        StickForm *x=(StickForm *) StickForms->Items[n];
        RECT XWnd;
        GetClientRect(x->Form,&XWnd);
        //int dWidth=NewWidth-XWnd.right;
        //int dHeight=NewHeight-XWnd.bottom;
        SetWindowPos(x->Form,HWND_NOTOPMOST,XWnd.left,XWnd.top,NewWidth,NewHeight,
            SWP_NOMOVE|SWP_NOZORDER);

    }
}
void StickFormMoveNotStick(HWND Form,int NewLeft,int NewTop) // Вызывается при перемещении формы плагина.
{
    int n=FindStickForm(Form);
    if (n>-1)
    {
        StickForm *x=(StickForm *) StickForms->Items[n];
        RECT XWnd;
        GetWindowRect(x->Form,&XWnd);
        int dLeft=NewLeft-XWnd.left;
        int dTop=NewTop-XWnd.top;
        if (dLeft==0 && dTop==0) return;
        XWnd.left=NewLeft;
        XWnd.top=NewTop;
        SetWindowPos(Form,HWND_NOTOPMOST,XWnd.left,XWnd.top,0,0,SWP_NOZORDER|SWP_NOSIZE);
    }
}
void StickFormStayOnTop(bool Flag)
{
    if (Flag)
    {
        for(int i=0;i<StickForms->Count;i++) SetWindowPos(((StickForm *) StickForms->Items[i])->Form,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
    } else
    {
        for(int i=0;i<StickForms->Count;i++) SetWindowPos(((StickForm *) StickForms->Items[i])->Form,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
    }
}
void WINAPI StickFormMove(HWND Form,int NewLeft,int NewTop) // Вызывается при перемещении формы плагина.
{
    int n=FindStickForm(Form);
    if (n>-1)
    {
        StickForm *XWnd=(StickForm *) StickForms->Items[n];
        RECT x;
        GetWindowRect(XWnd->Form,&x);
        x.left=NewLeft;
        x.top=NewTop;
        for(int i=0;i<StickForms->Count;i++)
        {
            if (i!=n)
            {
                StickForm *YWnd=(StickForm *) StickForms->Items[i];
                RECT y;
                //HWND Frm=YWnd->Form;
                GetWindowRect(YWnd->Form,&y);
                if ((x.right>=y.left-15) &&
                    (x.bottom>=y.top-15) &&
                    (x.left<=y.right+15) &&
                    (x.top<=y.bottom+15))
                {
                    if (abs(x.right-y.left)<=15)
                    {
                        NewLeft=y.left-(x.right-x.left);
                    } else
                    if (abs(x.bottom-y.top)<=15)
                    {
                        NewTop=y.top-(x.bottom-x.top);
                    } else
                    if (abs(x.left-y.right)<=15)
                    {
                        NewLeft=y.right;
                    } else
                    if (abs(x.top-y.bottom)<=15)
                    {
                        NewTop=y.bottom;
                    }
                }
            }
        }
        StickFormMoveNotStick(XWnd->Form,NewLeft,NewTop);
        //SetWindowPos(XWnd->Form,HWND_NOTOPMOST,NewLeft,NewTop,0,0,SWP_NOZORDER|SWP_NOSIZE);
    }

}
void WINAPI StickFormEndMove(void)
{
    for(int i=0;i<StickForms->Count;i++)
    {
        StickForm *y=(StickForm *) StickForms->Items[i];
        y->IsStick=false;
    }
    ((StickForm *) StickForms->Items[0])->IsStick=true;
    for(int i=0;i<StickForms->Count;i++)
    {
        StickForm *YWnd=(StickForm *) StickForms->Items[i];
        RECT y;
        GetWindowRect(YWnd->Form,&y);
        for(int j=1;j<StickForms->Count;j++)
        {
            if (i!=j)
            {
                StickForm *XWnd=(StickForm *) StickForms->Items[j];
                RECT x;
                GetWindowRect(XWnd->Form,&x);
                if ((x.right>=y.left-10) &&
                    (x.bottom>=y.top-10) &&
                    (x.left<=y.right+10) &&
                    (x.top<=y.bottom+10) && (!XWnd->IsStick))
                {
                    int NewLeft=x.left,NewTop=x.top;
                    if (abs(x.right-y.left)<=10)
                    {
                        if (YWnd->IsStick) XWnd->IsStick=true;
                        NewLeft=y.left-(x.right-x.left);
                    } else
                    if (abs(x.bottom-y.top)<=10)
                    {
                        if (YWnd->IsStick) XWnd->IsStick=true;
                        NewTop=y.top-(x.bottom-x.top);
                    } else
                    if (abs(x.left-y.right)<=10)
                    {
                        if (YWnd->IsStick) XWnd->IsStick=true;
                        NewLeft=y.right;
                    } else
                    if (abs(x.top-y.bottom)<=10)
                    {
                        if (YWnd->IsStick) XWnd->IsStick=true;
                        NewTop=y.bottom;
                    }
                    StickFormMoveNotStick(XWnd->Form,NewLeft,NewTop);
                }
            }
        }
    }
}
void WINAPI AddStickForm(HWND Form) // Добавление формы, которая прилипает к основной форме таймера.
{
    StickForm *x=new StickForm(Form);
    StickForms->Add(x);
    if (StickForms->Count>1)
        StickFormStayOnTop(TimerClass->Option[opAlwaysOnTop]);
}
void ChangeMainStickForm(HWND Handle)
{
    if (StickForms->Count>1)
    {
        StickForms->Items[0]=Handle;
    }
}
void WINAPI DeleteStickForm(HWND Form) // Удаление формы, прилипающей к основной форме таймера.
{
    int n=FindStickForm(Form);
    if (n>-1)
    {
        StickForms->Delete(n);
        //StickFormEndMove();
    }
}
int WINAPI GetLanguage(void)
{
    if (Lang==NULL) return 0;
    return Lang->File->ReadInteger("Language","LangNumber",0);
}
long WINAPI GetTime(void)
{
    return TimerClass->Time;
}
void WINAPI SetTime(long Time)
{
    TimerClass->Time=Time;
    TimerClass->RefreshFD();
}
char * WINAPI GetFormMessage(void) // Возвращает строку, для формы оповещения
{
    if (TimerClass->StrToMessage!="") return TimerClass->StrToMessage.c_str();
    else
    {
        BEG_LANG
            LANGSECTION("EndTimeForm\\Caption");
            return Lang->Text("lblText").c_str();
        ELSE_LANG
            return "Время истекло !!!";
        END_LANG
    }
}
void WINAPI SetFormMessage(char * Str) // Устанавливает строку для формы оповещения
{
    TimerClass->StrToMessage=AnsiString(Str);
}
int WINAPI PrmReadInteger(char * Section,char *Key, int Default)
{
    return TimerClass->Prm->ReadInteger(AnsiString(Section),AnsiString(Key),Default);
}
void WINAPI PrmWriteInteger(char *Section,char *Key, int Value)
{
    TimerClass->Prm->WriteInteger(AnsiString(Section),AnsiString(Key),Value);
}
char * WINAPI PrmReadString(char *Section,char *Key,char *Default)
{
    return (TimerClass->Prm->ReadString(AnsiString(Section),AnsiString(Key),AnsiString(Default))).c_str();
}
void WINAPI PrmWriteString(char *Section,char *Key, char * Value)
{
    TimerClass->Prm->WriteString(AnsiString(Section),AnsiString(Key),AnsiString(Value));
}
//
// TPluginClass
//
bool TPluginClass::PlugOpen(char *FilName)
{
    PlugClose();
    LoadLibrary(FilName);
    HMODULE=GetModuleHandle(FilName);
    bool (WINAPI *Init)(TIMERAPISTRUCT *);
    Init=(bool (WINAPI *)(TIMERAPISTRUCT *)) GetProcAddress(HMODULE,"Init");
    if (Init!=NULL)
    {
                Init(&TimerPlugin);
                HVersionTimer=(int WINAPI (*)(void)) GetProcAddress(HMODULE,"VersionTimer");
                if (VersionTimer()>VerTimer) { PlugClose();return false;}
                HActivate=(bool WINAPI (*)(void)) GetProcAddress(HMODULE,"Activate");
                HClose=(bool WINAPI (*)(void)) GetProcAddress(HMODULE,"Close");
                HConfigure=(void WINAPI (*)(void)) GetProcAddress(HMODULE,"Configure");
                HAboutPlugin=(void WINAPI (*)(void)) GetProcAddress(HMODULE,"AboutPlugin");
                HPluginName=(char * WINAPI (*)(void)) GetProcAddress(HMODULE,"PluginName");
                HStartClick=(bool WINAPI (*)(void)) GetProcAddress(HMODULE,"StartClick");
                HStopClick=(bool WINAPI (*)(void)) GetProcAddress(HMODULE,"StopClick");
                HDropFiles=(void WINAPI (*)(char *)) GetProcAddress(HMODULE,"DropFiles");
                FileName=FilName;
    } else { FileName="";PlugClose();return false;}
    return true;
}
bool TPluginClass::StartClick(void)
{
    if (HStartClick!=NULL) return HStartClick(); else return true;
}
bool TPluginClass::StopClick(void)
{
    if (HStopClick!=NULL) return HStopClick(); else return true;;
}

TPluginClass::TPluginClass()
{
    Initialize();
}
TPluginClass::~TPluginClass()
{
    PlugClose();
}
void TPluginClass::PlugClose(void)
{
    if (HMODULE!=NULL) {
            Close();
            FreeLibrary(HMODULE);
            Initialize();
            }
}
int TPluginClass::VersionTimer(void)
{
    if (HVersionTimer==NULL) return 9999999999; else return HVersionTimer();
}
bool TPluginClass::Activate(void)
{
    if (HActivate==NULL) return false; else return HActivate();
}
bool TPluginClass::Close(void)
{
    if (HClose==NULL) return false; else return HClose();
}
void TPluginClass::Configure(void)
{
    if (HConfigure!=NULL) HConfigure();
}
void TPluginClass::AboutPlugin(void)
{
    if (HAboutPlugin!=NULL) HAboutPlugin();
}
char * TPluginClass::PluginName(void)
{
    if (HPluginName==NULL) return "Неизвестно..."; else return HPluginName();
}
void TPluginClass::Initialize(void)
{
    HMODULE=0;
    HVersionTimer=NULL;HActivate=NULL;HClose=NULL;
    HConfigure=NULL;HAboutPlugin=NULL;HPluginName=NULL;
    HStartClick=NULL;HStopClick=NULL;
    HDropFiles=NULL;Enabled=true;
}
void TPluginClass::DropFiles(char *Str)
{
    if (HDropFiles!=NULL) HDropFiles(Str);
}

//
// TPlugin
//
//

TPlugin::TPlugin() : TPluginClass()
{
    Initialize();
}
bool TPlugin::PlugOpen(char *FileName)
{
    if (TPluginClass::PlugOpen(FileName))
    {
        HRunPlugin=(int WINAPI (*)(int Tim,char *WaveFile)) GetProcAddress(HMODULE,"RunPlugin");
        HTimerEvent=(void WINAPI (*)(void)) GetProcAddress(HMODULE,"TimerEvent");
        return true;
    };
    return false;
}
int TPlugin::RunPlugin(int Tim,char *WaveFile)
{
    if (HRunPlugin==NULL) return 999999999; else return HRunPlugin(Tim,WaveFile);
}
void TPlugin::TimerEvent(void)
{
    if (HRunPlugin!=NULL) HTimerEvent();
}
void TPlugin::Initialize(void)
{
    TPluginClass::Initialize();
    HRunPlugin=NULL;
    HTimerEvent=NULL;
}
//--------------------------------------------------------------------
void WINAPI ViewFormAfterTime(char * FileNameToPlay,HDC HBitmap,char * Str)
{
/*    if (Form1->N1->Checked)
    {
        Form1->MediaPlayer1->FileName=AnsiString(FileNameToPlay);
        Form1->MediaPlayer1->DeviceType=dtAutoSelect;
        Form1->MediaPlayer1->Open();
        if (Form1->MediaPlayer1->ErrorMessage!=0)
        {
            Form1->MediaPlayer1->Play();
            if (Form1->MediaPlayer1->Error!=0)
            {
                Form1->MediaPlayer1->FileName="c:\\windows\\media\\Tada.wav";
                Form1->MediaPlayer1->DeviceType=dtAutoSelect;
                Form1->MediaPlayer1->Open();
                if (Form1->MediaPlayer1->Error!=0)
                {
                    Form1->MediaPlayer1->FileName=GetCurrentDir()+"\\Start.wav";
                    Form1->MediaPlayer1->DeviceType=dtAutoSelect;
                    Form1->MediaPlayer1->Open();
                    Form1->MediaPlayer1->Play();
                } else
                {
                    Form1->MediaPlayer1->Play();
                }
            }
        }
    } else Form1->MediaPlayer1->Play();
    if (Form1->N2->Checked)
    {
        if (Form1->FormState==apMiniForm) Form4->Hide();
        Graphics::TBitmap *BMP=NULL;
        if (HBitmap!=NULL)
        {
            BMP=new Graphics::TBitmap;
            BMP->Width=Screen->Width;
            BMP->Height=Screen->Height;
            BitBlt(BMP->Canvas->Handle,0,0,Screen->Width,Screen->Height,HBitmap,0,0,SRCCOPY);
        }
        Form6->Play(BMP,AnsiString(Str));
        delete BMP;
        Form1->MediaPlayer1->Close();
        if (Form1->FormState==apMiniForm) Form4->Show();
    }
    */
}

int ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd)
{

  char zFileName[255], zParams[255], zDir[255];
  return (int) ShellExecute(Application->MainForm->Handle,
                            NULL,
                            strcpy(zFileName,
                                   FileName.c_str()),
                            strcpy(zParams,
                                   Params.c_str()),
                            strcpy(zDir,
                                   DefaultDir.c_str()),
                            ShowCmd);
}
char * WINAPI GetRegistryPath(void) // Возвращает местоположение настроек плагинов для таймера.
{
    return (CurDir+"\\Timer\\PlugIn").c_str();
}
HWND WINAPI GetHWNDMainTimerForm(void) // Возвращает HWND главной формы Таймера.
{
    return Form1->Handle;
}
//
// WebBrowser
//

void WebBrowserShow(void)
{
    if (WebBrowserForm==NULL)
    {
        WebBrowserForm=new TWebBrowserForm(Form1);
        WebBrowserForm->Top=Form1->Top+Form1->Height;
        WebBrowserForm->Left=Form1->Left;
        AddStickForm(WebBrowserForm->Handle);
        StickFormEndMove();
        WebBrowserForm->Show();
    } else WebBrowserForm->Visible=true;
}
void WINAPI WebBrowserOpenURL(char * URL)
{
    if (WebBrowserForm==NULL) WebBrowserShow();
    WebBrowserForm->OpenURL(AnsiString(URL));
}

char * WINAPI GetPluginDir(void)
{
    return (CurDir+"\\PlugIn").c_str();
}
void WINAPI ButtonStartClick(void) // Эмулирует нажатие кнопки ПУСК
{
    TimerClass->Start();
}
void WINAPI ButtonStopClick(void) // Эмулирует нажатие кнопки СТОП
{
    TimerClass->Stop();
}


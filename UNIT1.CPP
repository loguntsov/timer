//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
#include "GlobalModule.h"
#include "Language.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "NumImage"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    FormMove=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//long tim=UpDownHour->Position*3600+UpDownMin->Position*60+UpDownSek->Position;
    TimerClass->NextSek();
    Application->NormalizeAllTopMosts();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDownSekClick(TObject *Sender, TUDBtnType Button)
{
    NumImage6->Value=UpDownSek->Position;
    NumImage5->Value=UpDownSek->Position/10;
    TimerClass->Time=UpDownHour->Position*3600+UpDownMin->Position*60+UpDownSek->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDownMinClick(TObject *Sender, TUDBtnType Button)
{
    NumImage4->Value=UpDownMin->Position;
    NumImage3->Value=UpDownMin->Position/10;
    TimerClass->Time=UpDownHour->Position*3600+UpDownMin->Position*60+UpDownSek->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDownHourClick(TObject *Sender, TUDBtnType Button)
{
    NumImage2->Value=UpDownHour->Position;
    NumImage1->Value=UpDownHour->Position/10;
    TimerClass->Time=UpDownHour->Position*3600+UpDownMin->Position*60+UpDownSek->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnClick(TObject *Sender)
{
    if (TimerClass->GetState() & tmRun) TimerClass->Stop(); else TimerClass->Start();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TimerClass=new TTimerClass(this);
    TimerClass->LoadPluginLIst();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormPaint(TObject *Sender)
{
    TimerClass->OnPaint();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if(!FormMove)
    {
        FormMove=true;
        StickFormEndMove();        
        x0=X;
        y0=Y;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if(FormMove)
    {
        int dx=X-x0,dy=Y-y0;
        for(int i=1;i<StickForms->Count;i++)
        {
            StickForm *YWnd=(StickForm *) StickForms->Items[i];
            if (YWnd->IsStick)
            {
                RECT y;
                GetWindowRect(YWnd->Form,&y);
                StickFormMoveNotStick(YWnd->Form,y.left+dx,y.top+dy);
            }
        }
        TimerClass->ChangeXY(Left+dx,Top+dy);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    FormMove=false;
    StickFormEndMove();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete TimerClass;    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acExitExecute(TObject *Sender)
{
    Application->Terminate();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acMinimizeExecute(TObject *Sender)
{
    TimerClass->Minimize();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButMenuClick(TObject *Sender)
{
    PopUpMenu->Popup(Left,Top);        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acAboutExecute(TObject *Sender)
{
    TForm2 *a=new TForm2(this);
    a->ShowModal();
    delete a;    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acOptionExecute(TObject *Sender)
{
    if (Form5==NULL)
    {
        Form5=new TForm5(this);
        Form5->Show();
    }
}
//---------------------------------------------------------------------------
void TForm1::LangRefresh(void)
{
    LANGSECTION("MainForm\\Hint");
    LANGCONTROLHINT(this);
    LANGSECTION("MainForm\\Caption");
    LANGCONTROLCAPTION(this);
}

void __fastcall TForm1::mnuMessageClick(TObject *Sender)
{
    TimerClass->Option[opMessage]=!TimerClass->Option[opMessage];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuPlayToFileClick(TObject *Sender)
{
    TimerClass->Option[opPlayMusic]=!TimerClass->Option[opPlayMusic];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuAlwaysOnTopClick(TObject *Sender)
{
    TimerClass->Option[opAlwaysOnTop]=!TimerClass->Option[opAlwaysOnTop];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuMinimizeInSysTrayClick(TObject *Sender)
{
    TimerClass->Option[opMinimInSysTray]=!TimerClass->Option[opMinimInSysTray];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MsgSysTray(TMessage& Msg) // Cсообщение на реакцию в SystemTray
{
    switch(Msg.LParam)
    {
        case WM_RBUTTONUP :
            PopUpMenu->Popup(Mouse->CursorPos.x,Mouse->CursorPos.y);
            break;
        case WM_LBUTTONUP :
            Show();
            TimerClass->DeleteSysTray();
            Application->Restore();
            StickFormStayOnTop(true);
            if (!TimerClass->Option[opAlwaysOnTop]) StickFormStayOnTop(false);            
            break;
    }
    Msg.LParam=0;
}


void __fastcall TForm1::mnuWebBrowserClick(TObject *Sender)
{
    WebBrowserOpenURL((CurDir+"\\Help\\Index.htm").c_str());    
}
//---------------------------------------------------------------------------


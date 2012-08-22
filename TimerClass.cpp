//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TimerClass.h"
#include "Unit1.h"
#include "Language.h"
#include <Sysutils.hpp>
#include "Unit3.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TTimerClass *TimerClass;
//
//  TPluginList
//

TPlugin * TPluginList::GetItem(int Index)
{
    return (TPlugin *) TList::Items[Index];
}
void TPluginList::SetItem(int Index,TPlugin * Plug)
{
    TList::Items[Index]=Plug;
}
void TPluginList::Add(TPlugin * Plug)
{
    TList::Add(Plug);
}
bool TPluginList::Delete(int Index)
{
    Item[Index]->PlugClose();
    delete Item[Index];
    TList::Delete(Index);
    return true;
}
bool TPluginList::Delete(TPlugin * Plug)
{
    int n=Find(Plug);
    if (n>-1) return Delete(n); else return false;
}
bool TPluginList::AddPlugIn(AnsiString Path)
{
    TPlugin *Plug=new TPlugin;
    if (Plug->PlugOpen(Path.c_str()))
    {
        TList::Add(Plug);
        return true;
    } else return false;
}
//bool TPluginList::Clear(void)
//{
//    int n=Count;
//    bool f=true;
//    for(int i=0;i<n;i++)
//    {
//        f=f && Delete(0);
//    }
//}
int TPluginList::Find(TPlugin *Plug)
{
    int n=-1;
    for(int i=0;i<Count;i++)
    {
        if (Item[i]==Plug) { n=i;break;}
    }
    return n;
}
//TPluginList::~TPluginList()
//{
//    Clear();
//}

//
// TTimerClass
//

TTimerClass::TTimerClass(TForm1 *F)
{
    FD=F;State=0;Time=0;
    Param=new TIniFile(CurDir+"\\Timer.ini");
    if (Param->ReadString("RunProgram","FileNameExe",Application->ExeName)!=Application->ExeName)
    {
        delete Param;
        DeleteFile(CurDir+"\\Timer.ini");
        Param=new TIniFile(CurDir+"\\Timer.ini");
        Param->WriteString("RunProgram","FileNameExe",Application->ExeName);
    }
    FPlugIn=new TPluginList();
    FSkin=new SkinClass(FD->NumForBaseSkin);
    Application->OnActivate=OnActivate;
    Application->OnDeactivate=OnDeactivate;
    Application->OnMinimize=OnMinimize;
    Application->OnRestore=OnRestore;
    LoadParam();Time=0;StrToMessage="";
    for(int i=0;i<OptionCount;i++) SetOption(i,GetOption(i));
    AddStickForm(FD->Handle);
    StickFormStayOnTop(Option[opAlwaysOnTop]);    
}
TTimerClass::~TTimerClass()
{
    delete FPlugIn,FSkin;
    if (Lang!=NULL) delete Lang;
    DeleteSysTray();
}
TPluginList * TTimerClass::GetPlugIn(void)
{
    return FPlugIn;
}
bool TTimerClass::Start(void) // Начало счета
{
    Time=FD->UpDownHour->Position*3600+FD->UpDownMin->Position*60+FD->UpDownSek->Position;
    if (Time>0)
    {
        bool f=true;
        for(int i=0;i<PlugList->Count;i++) f=f&&PlugList->Item[i]->StartClick();
        if (f)
        {
            FD->Timer1->Enabled=true;
            FD->Btn->Glyph->Assign(Skin->BtnStop);
            NextSek();
            State=State|tmRun;
        } else Stop();
    }
    RefreshFD();
    return true;
}
bool TTimerClass::Stop(void) // Конец счета
{
    FD->Timer1->Enabled=false;
    FD->Btn->Glyph->Assign(Skin->BtnRun);
    Application->Title=GetTitle();
    State=State&~tmRun;
    for(int i=0;i<PlugList->Count;i++) PlugList->Item[i]->StopClick();
    RefreshFD();
    return true;    
}
int TTimerClass::GetState(void)
{
    return State;
}
void TTimerClass::NextSek(void) // Следующая секунда
{
    Time--;
    long tim=Time;
    if (tim>=0)
    {
        RefreshFD();
        Application->Title=GetTimeString();
    } else
    {
        Stop();
        TForm3 *a=new TForm3(FD);
        a->PlayForm(StrToMessage);
        if (State&tmMinimizeInSysTray)
        {
            TimerClass->DeleteSysTray();
            Application->Restore();
        }
        delete a;
    }
    RefreshSysTray();
    for(int i=0;i<PlugList->Count;i++) PlugList->Item[i]->TimerEvent();
}

void __fastcall TTimerClass::OnActivate(TObject *Sender) // Активация формы
{
    FD->Bar->Picture->Bitmap->Assign(Skin->BarActivate);
    State=State|tmIsActive;
}
void __fastcall TTimerClass::OnDeactivate(TObject *Sender) // Деактивация формы
{
    FD->Bar->Picture->Bitmap->Assign(Skin->BarDeactivate);
    State=State&~tmIsActive;    
}
void __fastcall TTimerClass::OnMinimize(TObject *Sender) // Минимизация приложения
{
// Выполняется при минимизации приложения.
    State=State|tmMinimize;
}
void __fastcall TTimerClass::OnRestore(TObject *Sender) // Восстановление приложения
{
// Вызывается при восстановлении приложения из минимизированного состояния
    State=State&~tmMinimize;
}

void TTimerClass::OnPaint(void) // Действует во время перерисовки
{
    FD->Canvas->Draw(0,0,Skin->ForeGround);

}
void TTimerClass::Minimize(void) // Минимизация
{
    Application->Minimize();
    if (Option[opMinimInSysTray])
    {
        CreateSysTray();
        FD->Hide();
    }
    State=State|tmMinimize;
}
bool TTimerClass::ChangeSkin(AnsiString Path,TimerSkinType Type) // Изменение скина
{
    Param->WriteString("Skin","SkinPath",Path);
    Param->WriteInteger("Skin","SkinType",Type);
    RefreshFD();
    return true;
}
void TTimerClass::RefreshLang(AnsiString FileName) // Обновление языка
{
    if (Lang!=NULL) delete Lang;
    Lang=new TLang(FileName);
    AnsiString a=Param->ReadString("Language","LanguageFile","");
    Param->WriteString("Language","LanguageFile",FileName);
    if (FileName=="" && a!="") { LANGMESSAGE("REBOOT","Требуется перезагрузка программы !!!",MB_OK);Exit();}
    if (FileName!="")
    {
        FD->LangRefresh();
    } else { delete Lang;Lang=NULL; }
    Application->Title=GetTitle();    
}
TIniFile * TTimerClass::GetParam(void)
{
    return Param;
}
void TTimerClass::Exit(void)
{
    if (State&tmRun) Stop();
    Application->Terminate();

}
AnsiString TTimerClass::GetTitle(void)
// Возвравет заголовок приложения Таймера на нужном языке
{
    AnsiString a="";
    BEG_LANG
    LANGSECTION("Application");
    a=TL("Title");
    END_LANG
    if (a=="") a="Таймер";
    return a;
}
void TTimerClass::RefreshFD(void)
{
    FD->UpDownHour->Position=Time/3600;
    FD->UpDownMin->Position=(Time/60) % 60;
    FD->UpDownSek->Position=Time % 60;
    FD->NumImage6->Value=FD->UpDownSek->Position;
    FD->NumImage5->Value=FD->UpDownSek->Position/10;
    FD->NumImage4->Value=FD->UpDownMin->Position;
    FD->NumImage3->Value=FD->UpDownMin->Position/10;
    FD->NumImage2->Value=FD->UpDownHour->Position;
    FD->NumImage1->Value=FD->UpDownHour->Position/10;
    //FD->Bar->Picture->Bitmap->Assign(Skin->BarActivate);
    if (!(GetState()&tmRun))
        FD->Btn->Glyph->Assign(Skin->BtnRun);
    else
        FD->Btn->Glyph->Assign(Skin->BtnStop);
    if (GetState()&tmIsActive) OnActivate(NULL); else OnDeactivate(NULL); 
    OnPaint();
    FD->Bar->Repaint();
}
void TTimerClass::LoadParam(void)
{
    FD->NumImage1->Images=Skin->Numbr;
    FD->NumImage2->Images=Skin->Numbr;
    FD->NumImage3->Images=Skin->Numbr;
    FD->NumImage4->Images=Skin->Numbr;
    FD->NumImage5->Images=Skin->Numbr;
    FD->NumImage6->Images=Skin->Numbr;
    if (Param->ReadInteger("Skin","SkinType",tmFolder)==tmFolder)
        Skin->LoadSkinFromFolder(Param->ReadString("Skin","SkinPath",""));
        else
        Skin->LoadSkinFromTSK(Param->ReadString("Skin","SkinPath",""));
    RefreshLang(Param->ReadString("Language","LanguageFile",""));
    Application->Title=GetTitle();
    ChangeXY(Param->ReadInteger("Position","X",FD->Left),Param->ReadInteger("Position","Y",FD->Top));
    RefreshFD();    
}
void TTimerClass::ChangeXY(int X,int Y) // Вызывается при изменении координат окна
{
    x=X;y=Y;
    Param->WriteInteger("Position","X",x);
    Param->WriteInteger("Position","Y",y);
    FD->Left=x;
    FD->Top=y;
}
bool TTimerClass::GetOption(int Index)
{
    switch(Index)
    {
        case opMessage :
            return Param->ReadBool("Option","Message",true);
        case opPlayMusic :
            return Param->ReadBool("Option","PlayMusic",true);
        case opAlwaysOnTop :
            return Param->ReadBool("Option","AlwaysOnTop",false);
        case opMinimInSysTray :
            return Param->ReadBool("Option","SysTray",false);
        default:
            return false;
    };
}
void TTimerClass::SetOption(int Index,bool Value)
{
    switch(Index)
    {
        case opMessage :
            Param->WriteBool("Option","Message",Value);
            FD->mnuMessage->Checked = Value;
        break;
        case opPlayMusic :
            Param->WriteBool("Option","PlayMusic",Value);
            FD->mnuPlayToFile->Checked = Value;
        break;
        case opAlwaysOnTop :
            Param->WriteBool("Option","AlwaysOnTop",Value);
            FD->mnuAlwaysOnTop->Checked = Value;
            if (Value)
            {
                StickFormStayOnTop(true);
                //FD->FormStyle=fsStayOnTop;
            } else
            {
                StickFormStayOnTop(false);
                //FD->FormStyle=fsNormal;
            }
            //ChangeMainStickForm(FD->Handle);
        break;
        case opMinimInSysTray :
            Param->WriteBool("Option","SysTray",Value);
            FD->mnuMinimizeInSysTray->Checked = Value;
        break;
        default:
        ;
    };
}
//---------------------------------------------------------------------
void TTimerClass::SavePluginList(void)
{
    Prm->EraseSection("Plugin");
    for(int i=0;i<PlugList->Count;i++)
    {
        Prm->WriteString("Plugin","Name"+IntToStr(i),PlugList->Item[i]->FileName);
        Prm->WriteBool("Plugin","Enabled"+IntToStr(i),PlugList->Item[i]->Enabled);
    }
}
void TTimerClass::LoadPluginLIst(void)
{
    PlugList->Clear();
    AnsiString Name;int i=0;
    Name=Prm->ReadString("Plugin","Name0","");
    while (Name!="")
    {
        if (PlugList->AddPlugIn(Name))
        {
            PlugList->Item[PlugList->Count-1]->Enabled=Prm->ReadBool("Plugin","Enabled"+IntToStr(i),true);
            PlugList->Item[PlugList->Count-1]->Activate();
        }
        i++;
        Name=Prm->ReadString("Plugin","Name"+IntToStr(i),"");
    }
}
void TTimerClass::CreateSysTray(void) // Создание иконки в SysTray
{
    if (!(State&tmSysTray))
    {
        State=State|tmSysTray;
        SysTrayIconData.cbSize = sizeof(NOTIFYICONDATA);
        SysTrayIconData.hWnd = FD->Handle ;
        SysTrayIconData.uID=0;
        SysTrayIconData.hIcon=LoadIcon(HInstance,"TIMERICONSMALL");
        SysTrayIconData.uFlags = NIF_ICON |NIF_TIP|NIF_MESSAGE ;
        SysTrayIconData.uCallbackMessage = msgSysTray;
        strcpy(SysTrayIconData.szTip,GetTimeString().c_str());
        Shell_NotifyIcon(NIM_ADD,&SysTrayIconData);
    }
}
void TTimerClass::DeleteSysTray(void) // Удаление иконки из SysTray
{
    if (State&tmSysTray)
    {
        State=State&~tmSysTray;
        Shell_NotifyIcon(NIM_DELETE,&SysTrayIconData);
        DestroyIcon(SysTrayIconData.hIcon);
    }
}
void TTimerClass::RefreshSysTray(void) // Обновление иконки в SysTray
{
    if (State&tmSysTray)
    {
        strcpy(SysTrayIconData.szTip,GetTimeString().c_str());
        Shell_NotifyIcon(NIM_MODIFY,&SysTrayIconData);
    }
}
AnsiString TTimerClass::GetTimeString(void) // Возвращает строку с временем
{
    AnsiString Title="";
    if (Time>0)
    {
        Title=Title+Format("%-2.2d",ARRAYOFCONST(((int)(Time/3600))))+":";
        Title=Title+Format("%-2.2d",ARRAYOFCONST(((int)((Time/60)%60))))+":";
        Title=Title+Format("%-2.2d",ARRAYOFCONST(((int)(Time%60))));
    } else Title=GetTitle();
        return Title;
}
SkinClass * TTimerClass::GetSkinClass()
{
    return FSkin;
}
int TTimerClass::Play(AnsiString File)// Играем файл. Если пусто - то имя файла по умолчанию.
{
    if (!TimerClass->Option[opPlayMusic]) return 0;
    if (File=="")
        File=Param->ReadString("Option","FileForPlay","");
    if (File=="") return 0;
    FD->Player->FileName=File;
    try {
        FD->Player->Open();
        FD->Player->Play();
    } catch (...)
    {
        return -1;
    }
    return 0;
}



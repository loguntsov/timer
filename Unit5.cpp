//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "Unit5.h"
#include "TimerClass.h"
#include <dir.h>
#include <SysUtils.hpp>
#include "Language.h"
#include "TimerClass.h"
#include "GlobalModule.h"
#include "ShortCutClass.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm5 *Form5=NULL;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form5=NULL;
    DeleteStickForm(Handle);    
    delete this;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormCreate(TObject *Sender)
{
// Выбор языка
    if (Lang!=NULL) RefreshLang();
   int done;
   struct ffblk ffblk;

// Скины
    // Cкины в каталогах
   {
   done = findfirst((CurDir+"\\Skins\\*.").c_str(),&ffblk,FA_DIREC	);
   while (!done)
   {
      AnsiString Name=ffblk.ff_name;
      if (Name[1]!='.') SkinBox->Items->Add(Name);
      done = findnext(&ffblk);
   }
   }
   // Cкины в файлах
   {
   done = findfirst((CurDir+"\\Skins\\*.tsk").c_str(),&ffblk,0	);
   while (!done)
   {
      AnsiString Name=ffblk.ff_name;
      if (Name[1]!='.') FileSkinBox->Items->Add(Name);
      done = findnext(&ffblk);
   }
   }
   
// Установка
    AnsiString File=ExtractFileName(TimerClass->Prm->ReadString("Language","LanguageFile",""));
    if (File=="")
    {
        ButLanguage->Caption="Select language";
    } else ButLanguage->Caption=File;
// Опции
    ckbMessage->Checked = TimerClass->Option[opMessage];
    ckbPlayMusic->Checked = TimerClass->Option[opPlayMusic];
    ckbAlwaysOnTop->Checked = TimerClass->Option[opAlwaysOnTop];
    ckbMinimizeInSysTray->Checked = TimerClass->Option[opMinimInSysTray];
// Плагины
    PluginList->Clear();
    for (int i=0;i<TimerClass->PlugList->Count;i++)
    {
        PluginList->Items->Add(TimerClass->PlugList->Item[i]->PluginName());
    }
    // Список плагинов
    done = findfirst((CurDir+"\\PlugIn\\*.").c_str(),&ffblk,FA_DIREC	);
    while (!done)
    {
      AnsiString Name=ffblk.ff_name;
      if (Name[1]!='.')
      {
        TMenuItem *a=new TMenuItem(this);
            a->Caption=Name;
            a->OnClick=AddPlugin;
        pmAddPlug->Items->Add(a);
      }
      done = findnext(&ffblk);
    }
// Начальные установки формы.
    if (TimerClass->Skin->Type==tmFolder)
        SkinPage->ActivePageIndex=0;
        else
        SkinPage->ActivePageIndex=1;
    AddStickForm(Handle);
    StickFormEndMove();
}
//---------------------------------------------------------------------------



void __fastcall TForm5::ButLanguageClick(TObject *Sender)
{
    OpenDialogForSetup->InitialDir=CurDir+"\\Language";
    if (OpenDialogForSetup->Execute())
    {
        TimerClass->RefreshLang(OpenDialogForSetup->FileName);
        ButLanguage->Caption=ExtractFileName(OpenDialogForSetup->FileName);
        RefreshLang();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button5Click(TObject *Sender)
{
    TimerClass->RefreshLang("");
}
//---------------------------------------------------------------------------
void TForm5::RefreshLang(void)
{
    if (Lang!=NULL)
    {
        LANGSECTION("ParamForm\\Hint");
        LANGCONTROLHINT(this);
        LANGSECTION("ParamForm\\Caption");
        LANGCONTROLCAPTION(this);
        Caption=TL("CAPTION");
    }
}

void __fastcall TForm5::ckbMessageClick(TObject *Sender)
{
    TimerClass->Option[opMessage]=ckbMessage->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ckbPlayMusicClick(TObject *Sender)
{
    TimerClass->Option[opPlayMusic]=ckbPlayMusic->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ckbAlwaysOnTopClick(TObject *Sender)
{
    TimerClass->Option[opAlwaysOnTop]=ckbAlwaysOnTop->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ckbMinimizeInSysTrayClick(TObject *Sender)
{
    TimerClass->Option[opMinimInSysTray]=ckbMinimizeInSysTray->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butBrowseClick(TObject *Sender)
{
    if (OpenDialogForPlay->Execute())
    {
        TimerClass->Prm->WriteString("Option","FileForPlay",OpenDialogForPlay->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::AddPlugin(TObject *Sender)
{
    // Добавить плагин к списку используемых
    TMenuItem *a=(TMenuItem *) Sender;
    AnsiString g=CurDir+"\\PlugIn\\"+a->Caption+"\\"+a->Caption+".dll";
    struct ffblk ffblk;
    int done;
    done = findfirst((CurDir+"\\PlugIn\\"+a->Caption+"\\*.dll").c_str(),&ffblk,0);
    while (!done)
    {
        AnsiString Name=(CurDir+"\\PlugIn\\"+a->Caption+"\\"+AnsiString(ffblk.ff_name));
        TPlugin *b=new TPlugin;
        if (b->PlugOpen(Name.c_str()))
        {
            TimerClass->PlugList->Add(b);
            PluginList->Items->Add(b->PluginName());
            b->Path=CurDir+"\\PlugIn\\"+a->Caption;
            b->Activate();
            TimerClass->SavePluginList();
        } else delete b;
        done = findnext(&ffblk);
    }
}

void __fastcall TForm5::butAddPlugClick(TObject *Sender)
{
    pmAddPlug->Popup(Left+butAddPlug->Left+10,Top+butAddPlug->Top+13);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butPlagConfigClick(TObject *Sender)
{
    if (PluginList->ItemIndex>-1) TimerClass->PlugList->Item[PluginList->ItemIndex]->Configure();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butPlugAbiutClick(TObject *Sender)
{
    if (PluginList->ItemIndex>-1) TimerClass->PlugList->Item[PluginList->ItemIndex]->AboutPlugin();    
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butDelPlugClick(TObject *Sender)
{
    if (PluginList->ItemIndex>-1)
    {
        TimerClass->PlugList->Delete(PluginList->ItemIndex);
        PluginList->Items->Delete(PluginList->ItemIndex);
        TimerClass->SavePluginList();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butPlugUpClick(TObject *Sender)
{
    if (PluginList->ItemIndex>0)
    {
        TPlugin *a;
        int n=PluginList->ItemIndex;
        a=TimerClass->PlugList->Item[n];
        TimerClass->PlugList->Item[n]=TimerClass->PlugList->Item[n-1];
        TimerClass->PlugList->Item[n-1]=a;
        AnsiString b;
        b=PluginList->Items->Strings[n];
        PluginList->Items->Strings[n]=PluginList->Items->Strings[n-1];
        PluginList->Items->Strings[n-1]=b;
        TimerClass->SavePluginList();
        PluginList->ItemIndex=n-1;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::butPlugDownClick(TObject *Sender)
{
    if (PluginList->ItemIndex<PluginList->Items->Count-1)
    {
        TPlugin *a;
        int n=PluginList->ItemIndex;
        a=TimerClass->PlugList->Item[n];
        TimerClass->PlugList->Item[n]=TimerClass->PlugList->Item[n+1];
        TimerClass->PlugList->Item[n+1]=a;
        AnsiString b;
        b=PluginList->Items->Strings[n];
        PluginList->Items->Strings[n]=PluginList->Items->Strings[n+1];
        PluginList->Items->Strings[n+1]=b;
        TimerClass->SavePluginList();
        PluginList->ItemIndex=n+1;
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm5::SkinBoxClick(TObject *Sender)
{
    AnsiString Path;
    if (SkinBox->ItemIndex==0)
    {
        Path="";
    } else
    {
        Path=CurDir+"\\Skins\\"+SkinBox->Items->Strings[SkinBox->ItemIndex];
    }
    TimerClass->Skin->LoadSkinFromFolder(Path);
    TimerClass->ChangeSkin(Path,tmFolder);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::mnuSaveSkinToFileClick(TObject *Sender)
{
    if (SkinBox->ItemIndex>-1)
    {
        TimerClass->Skin->SaveSkinToTSK(CurDir+"\\Skins\\"+SkinBox->Items->Strings[SkinBox->ItemIndex]+".tsk");
        ShowMessage("ОК");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FileSkinBoxClick(TObject *Sender)
{
    AnsiString Path=CurDir+"\\Skins\\"+FileSkinBox->Items->Strings[FileSkinBox->ItemIndex];
    TimerClass->Skin->LoadSkinFromTSK(Path);
    TimerClass->ChangeSkin(Path,tmFile);

}
//---------------------------------------------------------------------------

void TForm5::CreateShortCut(AnsiString FileName)
{
    CShortCut *a=new CShortCut(FileName);
    a->LinkFile = Application->ExeName;
    a->LinkPath = ExtractFilePath(Application->ExeName);
    a->LinkDescription = "Timer";
    a->Create();
    delete a;
}
void __fastcall TForm5::ButAddDesktopClick(TObject *Sender)
{
    CreateShortCut(GetSystemPath(CSIDL_DESKTOP)+"\\Timer.lnk");    
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ButAddQuickLaunchClick(TObject *Sender)
{
    CreateShortCut(GetSystemPath(CSIDL_APPDATA)+"\\Microsoft\\Internet Explorer\\Quick Launch\\Timer.lnk");    
}
//---------------------------------------------------------------------------


void __fastcall TForm5::ButAddStartMenuClick(TObject *Sender)
{
    CreateShortCut(GetSystemPath(CSIDL_PROGRAMS)+"\\Timer.lnk");    
}
//---------------------------------------------------------------------------

void __fastcall TForm5::rgForAlertClick(TObject *Sender)
{
    eOther->Enabled=(rgForAlert->ItemIndex==3);
}
//---------------------------------------------------------------------------


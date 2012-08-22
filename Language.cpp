//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Language.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TLang * Lang;

TLang::TLang(AnsiString Path) // Путь к файлу ссобщений
{
    File=new TIniFile(Path);
    Section="";
}
TLang::~TLang()
{
    delete File;
}
AnsiString TLang::Text(AnsiString Key) // Сообщение
{
    return (Key.Length()==0) ? (AnsiString("")) : (File->ReadString(Section,Key.UpperCase(),""));
}
AnsiString TL(AnsiString Key)
{
    return Lang->Text(Key);
}
void LANGSECTION(AnsiString Section)
{
    Lang->Section=Section;
}
void LANGCONTROLCAPTION(TComponent *Control)
{
    //((TLabel *) Control)->Caption=TL(Control->Name);
    for(int i=0;i<Control->ComponentCount;i++)
    {
          TComponent *a=Control->Components[i];
          AnsiString Str=TL(a->Name);
          //LANGCONTROLCAPTION(a);
          if (Str!="")
          {
              switch(a->Tag)
              {
                  case 10: ((TMenuItem *) a)->Caption=Str;break;
                  case 11: ((TLabel *) a)->Caption=Str;break;
                  default:;
              }
          }

    }
}
void LANGCONTROLHINT(TComponent *Control)
{
    TComponent *a=NULL;
    ((TForm *) Control)->Caption=TL(Control->Name);
    for(int i=0;i<Control->ComponentCount;i++)
    {
        try {
        a=Control->Components[i];
        AnsiString Str=TL(a->Name);
        if (Str!="")
        {
            /*switch(a->Tag)
            {
                case 10: ((TMenuItem *) a)->Hint=Str;break;
                case 11: ((TControl *) a)->Hint=Str;break;
                default:;
            }*/
        }
        }catch (...)
        {
            ShowMessage("Ошибка."+AnsiString(i)+AnsiString(char(a==NULL)));
            //Abort();
        }
    }
}
void LANGMESSAGE(AnsiString Key,AnsiString Msg,int Flags)
{
    if (Lang==NULL)
    {
        Application->MessageBox(Msg.c_str(),"",Flags);
    } else
    {
        AnsiString Sec=Lang->Section;
        Lang->Section="Message";
        AnsiString a=TL(Key);
        Lang->Section=Sec;
        if (a=="") a=Msg;
        Application->MessageBox(a.c_str(),"",Flags);
    }
}


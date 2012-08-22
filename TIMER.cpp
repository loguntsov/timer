//---------------------------------------------------------------------------

#include <vcl.h>
#include "GlobalModule.h"
#pragma hdrstop
USERES("TIMER.res");
USEUNIT("GlobalModule.cpp");
USEUNIT("TimerClass.cpp");
USEFORM("UNIT1.CPP", Form1);
USEFORM("UNIT2.CPP", Form2);
USEFORM("UNIT3.CPP", Form3);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("UNIT6.CPP", Form6);
USEFORM("UnitWebBrowser.CPP", WebBrowserForm);
USERES("TimerResource.res");
USEUNIT("Language.cpp");
USEUNIT("TaskBar.cpp");
USEUNIT("ZipUnit.cpp");
USEUNIT("SkinClass.cpp");
USELIB("Zlib\Zlib.lib");
USEUNIT("ShortCutClass.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
           StickForms=new TList;
            StickForms->Clear();
            TimerPlugin.Size=sizeof(TIMERAPISTRUCT);
            TimerPlugin.StickFormResize=StickFormResize;
            TimerPlugin.StickFormMove=StickFormMove;
            TimerPlugin.AddStickForm=AddStickForm;
            TimerPlugin.DeleteStickForm=DeleteStickForm;
            TimerPlugin.StickFormEndMove=StickFormEndMove;
            TimerPlugin.ViewFormAfterTime=ViewFormAfterTime;
            TimerPlugin.GetRegistryPath=GetRegistryPath;
            TimerPlugin.GetHWNDMainTimerForm=GetHWNDMainTimerForm;
            TimerPlugin.WebBrowserOpenURL=WebBrowserOpenURL;
            TimerPlugin.GetPluginDir=GetPluginDir;
            TimerPlugin.ButtonStartClick=ButtonStartClick;
            TimerPlugin.ButtonStopClick=ButtonStopClick;
            TimerPlugin.GetLanguage=GetLanguage;
            TimerPlugin.SetTime=SetTime;
            TimerPlugin.GetTime=GetTime;
            TimerPlugin.PrmReadInteger=PrmReadInteger;
            TimerPlugin.PrmWriteInteger=PrmWriteInteger;
            TimerPlugin.PrmReadString=PrmReadString;
            TimerPlugin.PrmWriteString=PrmWriteString;
            TimerPlugin.SetFormMessage=SetFormMessage;
            TimerPlugin.GetFormMessage=GetFormMessage;

         Application->Initialize();
         Application->Title = "Таймер";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------

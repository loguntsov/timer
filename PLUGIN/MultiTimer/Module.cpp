//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "InitFormUnit.h"

#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
#pragma option -a2

#define __TIMERPLUGINMODULE__
#include "TimerPlugin.hpp"
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    return 1;
}

//---------------------------------------------------------------------------
TIMERAPI int WINAPI _export VersionTimer(void)
{
    return VERTIMER;
}

TIMERAPI bool WINAPI _export Activate(void)
{
    Application->Handle=Timer.GetHWNDMainTimerForm();
    InitForm=new TInitForm(NULL);
    InitForm->Show();
    return true;
}
TIMERAPI bool WINAPI _export Close(void)
{
    //Application->Handle=NULL;
    delete InitForm;
    return true;
}
TIMERAPI void WINAPI _export Configure(void)
{

}
TIMERAPI void WINAPI _export AboutPlugin(void)
{
    ShowMessage("МультиТаймер Логунцов С.В. 2002 г.");
}
TIMERAPI int WINAPI _export RunPlugin(int Tim,char *WaveFile)
{
    Timer.ViewFormAfterTime(WaveFile,GetDC(GetDesktopWindow()),"Время прошло !!!");
    return 0;
}
TIMERAPI char * WINAPI _export PluginName(void)
{
	int lang=Timer.GetLanguage();
    switch(lang)
    {
        case lngRus : return "МультиТаймер";
    }
    return "MultiTimer";
}
TIMERAPI void WINAPI _export TimerEvent(void)
{
    for(int i=0;i<InitForm->cbTaskList->Items->Count;i++)
    {
        if (Tim[i]>0) Tim[i]--;
        if (Tim[i]==0)
        {
            Tim[i]=-1;
            InitForm->cbTaskList->ItemIndex=i;
            InitForm->cbTaskListClick(NULL);
        }
    }
}

TIMERAPI bool WINAPI _export StartClick(void)
{
    if (Cur>=0) Tim[Cur]=Timer.GetTime();
    return true;
}
TIMERAPI bool WINAPI _export StopClick(void)
{
    if (Tim[Cur]<=0)
    {
        for(int i=Cur+1;i<InitForm->cbTaskList->Items->Count;i++)
        {
            Tim[i-1]=Tim[i];
        }
        InitForm->cbTaskList->Items->Delete(Cur);
        Cur=-1;
        if (Tim[0]>0)
        {
            InitForm->cbTaskList->ItemIndex=0;
            InitForm->cbTaskListClick(NULL);
            Timer.ButtonStartClick();
            return false;
        }
    }
    return true;
}
TIMERAPI void WINAPI _export DropFiles(char *Str)
{

}
























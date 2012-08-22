//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "ConfigForm.h"
#include "UnitInfoForm.h"
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

#define __TIMERPLUGINMODULE__
#include "TimerPlugin.hpp"

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    return 1;
}
//---------------------------------------------------------------------------

int Tme[7]={0,4,6,8,20,24,24};
double Cena[]={0,12.24,10.80,12.24,23.76,17.28,0};
double Itogo,ToDay,ToMoment;

TIMERAPI int WINAPI _export VersionTimer(void)
{
    return VERTIMER;
}
TIMERAPI bool WINAPI _export Activate(void)
{
    Application->Handle=NULL;
    Itogo=StrToFloat(Timer.PrmReadString("InternetControl","Total","0"));
    ToDay=StrToFloat(Timer.PrmReadString("InternetControl","ToDay","0"));
    AnsiString Dat=Timer.PrmReadString("InternetControl","Time","");
    TDateTime dt=Date();
    if (dt.DateString() != Dat) { Itogo=Itogo+ToDay;ToDay=0; };
    ToMoment=0;
    Timer.PrmWriteString("InternetControl","Total",FloatToStr(Itogo).c_str());
    Timer.PrmWriteString("InternetControl","ToDay",FloatToStr(ToDay).c_str());
    return true;
}
TIMERAPI bool WINAPI _export Close(void)
{
    return true;
}

TIMERAPI void WINAPI _export Configure(void)
{
    ConfigF=new TConfigF(Application);
    ConfigF->ShowModal();
    delete ConfigF;
}
TIMERAPI void WINAPI _export AboutPlugin(void)
{
    ShowMessage("Плагин для контроля за использованием ИНТЕРНЕТА. Логунцов С.В. 2002 г.");
}
TIMERAPI int WINAPI _export RunPlugin(int Tim,char *WaveFile)
{
    return 0;
}
TIMERAPI char * WINAPI _export PluginName(void)
{
	return "Временной контроль за Интернетом";
}
TIMERAPI void WINAPI _export TimerEvent(void)
{
    int dt=int(double(Date())*24)%24;
    for(int i=0;i<5;i++)
    {
        if (dt<Tme[i+1]) { ToMoment=ToMoment+Cena[i]/3600;break;}
    }
    //Application->NormalizeAllTopMosts();
    InfoForm->Cap->Caption=Format(" %7.2f",ARRAYOFCONST((ToDay)))+"+"+Format(" %7.4f",ARRAYOFCONST((ToMoment)))+" руб.";
    InfoForm->Caption=InfoForm->Cap->Caption;
}
TIMERAPI bool WINAPI _export StartClick(void)
{
    InfoForm=new TInfoForm(NULL);
    InfoForm->Show();
    return true;
}
TIMERAPI bool WINAPI _export StopClick(void)
{
    delete InfoForm;
    Timer.PrmWriteString("InternetControl","Total",FloatToStr(Itogo).c_str());
    ToDay=ToDay+ToMoment;
    Timer.PrmWriteString("InternetControl","ToDay",FloatToStr(ToDay).c_str());
    ToMoment=0;
    return true;    
}







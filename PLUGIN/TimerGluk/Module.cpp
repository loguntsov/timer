//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
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
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    return 1;
}
//---------------------------------------------------------------------------

#define __TIMERPLUGINMODULE__
#include "TimerPlugin.hpp"

//---------------------------------------------------------------------------
TIMERAPI int WINAPI _export VersionTimer(void)
{
    return VERTIMER;
}

TIMERAPI bool WINAPI _export Activate(void)
{
    HRGN hRgn;
    hRgn=CreateRoundRectRgn(0,0,249,57,30,30);
    SetWindowRgn(Timer.GetHWNDMainTimerForm(), hRgn, true);
    return true;
}
TIMERAPI bool WINAPI _export Close(void)
{
    return true;
}
TIMERAPI void WINAPI _export Configure(void)
{

}
TIMERAPI void WINAPI _export AboutPlugin(void)
{
    ShowMessage("Резиновая форма. Логунцов С.В. 2002 г.");
}
TIMERAPI char * WINAPI _export PluginName(void)
{
	int lang=Timer.GetLanguage();
    switch(lang)
    {
        case lngRus : return "Резиновая форма";
    }
    return "Rubber Form";
}
TIMERAPI void WINAPI _export TimerEvent(void)
{
}

TIMERAPI bool WINAPI _export StartClick(void)
{
    return true;
}
TIMERAPI bool WINAPI _export StopClick(void)
{
    return true;
}
TIMERAPI void WINAPI _export DropFiles(char *Str)
{
}














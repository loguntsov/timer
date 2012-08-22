//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "UnitConfigForm.h"
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
PROCESS_INFORMATION ExecProc={0,0,0,0};
TConfigForm *FormConfig;
bool IsRunning;
void ShutDownComputer(void)
{

//if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0))
//    error("ExitWindowsEx");

    if (FormConfig->AutoShutDown->Checked && IsRunning) 
    {
        HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
        &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
        (PTOKEN_PRIVILEGES)NULL, 0);
    // Shut down the system and force all applications to close.
        if (!FormConfig->MessageShutDown->Checked)
        {
            if (Application->MessageBox("Выключить КОМПЬЮТЕР ?","Таймер",MB_YESNO)==IDYES) ExitWindowsEx(EWX_POWEROFF|EWX_SHUTDOWN,0);
        } else ExitWindowsEx(EWX_POWEROFF|EWX_SHUTDOWN,0);
    }

}
TIMERAPI int WINAPI _export VersionTimer(void)
{
    return VERTIMER;
}
TIMERAPI bool WINAPI _export Activate(void)
{
    Application->Handle=NULL;
    IsRunning=false;
    FormConfig=new TConfigForm(Application);
    return true;
}
TIMERAPI bool WINAPI _export Close(void)
{
    TerminateProcess(ExecProc.hProcess,0);
    ShutDownComputer();
    delete FormConfig;
    return true;
}

TIMERAPI void WINAPI _export Configure(void)
{
    FormConfig->ShowModal();
}
TIMERAPI void WINAPI _export AboutPlugin(void)
{
    ShowMessage("Плагин для контроля за программами. Логунцов С.В. 2002 г.");
}
TIMERAPI int WINAPI _export RunPlugin(int Tim,char *WaveFile)
{
    Timer.ViewFormAfterTime(WaveFile,NULL,"Время истекло !!!");
    return 0;
}
TIMERAPI char * WINAPI _export PluginName(void)
{
    return "Программный контроль";
}
TIMERAPI void WINAPI _export TimerEvent(void)
{
    //
    //
    //
}
TIMERAPI bool WINAPI _export StartClick(void)
{
    if (FormConfig->StartMode->Checked) FormConfig->ShowModal();
    if (!FormConfig->IsClosed)
    {
        AnsiString a=FormConfig->ExecFileName->Text;
        STARTUPINFO Param;
        Param.cb=sizeof(STARTUPINFO);
        Param.lpReserved =NULL;
        Param.lpDesktop =NULL;
        Param.lpTitle =NULL;
        Param.cbReserved2 =0;
        Param.lpReserved2 = NULL;
        Param.dwFlags = STARTF_USESHOWWINDOW;
        Param.wShowWindow = SW_SHOW;
        if (!CreateProcess(a.c_str(),"",NULL,NULL,false,0,NULL,NULL,&Param,&ExecProc))
        {
            ExecProc.hProcess=0;
        } else Beep();
        IsRunning=true;
        return true;
    } else return false;
}
TIMERAPI bool WINAPI _export StopClick(void)
{
    if ((int) ExecProc.hProcess!=0)
        if (!FormConfig->AutoDel->Checked)
        {
            if (Application->MessageBox("Отрубить запущенную программу?","Таймер",MB_YESNO)==IDYES) TerminateProcess(ExecProc.hProcess,0);
        } else TerminateProcess(ExecProc.hProcess,0);
    ShutDownComputer();
    IsRunning=false;
    return true;
}







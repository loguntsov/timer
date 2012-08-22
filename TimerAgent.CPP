//---------------------------------------------------------------------------
//#include <vcl.h>
#include <registry.hpp>
#include <ShellAPI.h>
#include <time.h>


#pragma hdrstop
USERES("TimerAgent.res");
//---------------------------------------------------------------------------
int ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd);
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        TRegIniFile *IniFile=new TRegIniFile("Timer");
        UINT Tme=IniFile->ReadInteger("Detect","Time",0);
        UINT Tmd=IniFile->ReadInteger("Detect","Timed",0);
        AnsiString Dte=IniFile->ReadString("Detect","Date","");
        if (Tme+Tmd>time(NULL)) {
                (void) ExecuteFile("Timer.exe","",GetCurrentDir(),SW_SHOW);
            }
        IniFile->CloseKey();
        delete IniFile;
    return 0;
}
int ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd)
{
  char zFileName[255], zParams[255], zDir[255];
  return (int) ShellExecute(NULL,//Application->MainForm->Handle,
                            NULL,
                            strcpy(zFileName,
                                   FileName.c_str()),
                            strcpy(zParams,
                                   Params.c_str()),
                            strcpy(zDir,
                                   DefaultDir.c_str()),
                            ShowCmd);
}
//---------------------------------------------------------------------------

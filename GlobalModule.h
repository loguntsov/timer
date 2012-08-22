//---------------------------------------------------------------------------

#ifndef GlobalModuleH
#define GlobalModuleH

#include <windows.h>
#include <registry.hpp>

#define __TIMERPROGRAMMS__

#include "TimerPlugin.hpp"

extern TIMERAPISTRUCT TimerPlugin;

#define VerTimer 373
#define Model "3.73"
enum TimerSkinType {tmFile,tmFolder}; // ��� �����
class StickForm
{
    public:
    HWND Form;
    bool IsStick;
    StickForm(HWND Form);
};

extern void WINAPI StickFormResize(HWND Form,int NewWidth,int NewHeight); // ���������� ��� ��������� �������� ����� �������
extern void WINAPI StickFormMove(HWND Form,int NewLeft,int NewTop); // ���������� ��� ����������� ����� �������.
extern void WINAPI StickFormEndMove(void);
extern void WINAPI AddStickForm(HWND Form); // ���������� �����, ������� ��������� � �������� ����� �������.
extern void WINAPI DeleteStickForm(HWND Form); // �������� �����, ����������� � �������� ����� �������.
extern void WINAPI ViewFormAfterTime(char * FileNameToPlay,HDC HBitmap,char * Str);
extern char * WINAPI GetRegistryPath(void); // ���������� �������������� �������� �������� ��� �������.
extern HWND WINAPI GetHWNDMainTimerForm(void); // ���������� HWND ������� ����� �������.
extern void WINAPI WebBrowserOpenURL(char * URL);
extern char * WINAPI GetPluginDir(void);
extern void WINAPI ButtonStartClick(void); // ��������� ������� ������ ����
extern void WINAPI ButtonStopClick(void); // ��������� ������� ������ ����
extern int WINAPI GetLanguage(void); // ���������� ��� ����� (��� �������� �������������� ��������� �����)
extern long WINAPI GetTime(void); // ������� ������� ����� ������� � ��������
extern void WINAPI SetTime(long Time); // ������ ����� ������� � ��������
extern int WINAPI PrmReadInteger(char * Section,char *Key, int Default); // ������ ������ �������� �� ���������� �������
extern void WINAPI PrmWriteInteger(char *Section,char *Key, int Value); // ������ ������ ��������
extern char * WINAPI PrmReadString(char *Section,char *Key,char *Default); // ������ ������
extern void WINAPI PrmWriteString(char *Section,char *Key, char * Value); // ������ ������
extern char * WINAPI GetFormMessage(void); // ���������� ������, ��� ����� ����������
extern void WINAPI SetFormMessage(char * Str); // ������������� ������ ��� ����� ����������
extern void ChangeMainStickForm(HWND Handle);
class TPluginClass
{
       private:
        int (WINAPI *HVersionTimer)(void); // ������ ����������� ������ ������� � ������� ��������� ������
        bool (WINAPI *HActivate)(void); // ��������� �������
        bool (WINAPI *HClose)(void); // �������� �������
        void (WINAPI *HConfigure)(void); // ���������������� �������
        void (WINAPI *HAboutPlugin)(void); // ����� ���������� � �������.
        char * (WINAPI *HPluginName)(void); // ���������� ��� �������.
        bool (WINAPI *HStartClick)(void);
        bool (WINAPI *HStopClick)(void);
        void (WINAPI *HDropFiles)(char * );
    public:
        HMODULE HMODULE;
        int VersionTimer(void); // ������ ����������� ������ ������� � ������� ��������� ������
        bool Activate(void); // ��������� �������
        bool Close(void); // �������� �������
        void Configure(void); // ���������������� �������
        void AboutPlugin(void); // ����� ���������� � �������.
        char * PluginName(void); // ���������� ��� �������
        bool PlugOpen(char *FileName);
        void PlugClose(void);
        bool StartClick(void);
        bool StopClick(void);
        void DropFiles(char *Str);
        void Initialize(void);
        AnsiString Path;
        AnsiString FileName;
        bool Enabled;
        TPluginClass();
        ~TPluginClass();
};
class TPlugin: public TPluginClass
{
    private:
        int  (WINAPI *HRunPlugin)(int Tim,char *WaveFile);
        void (WINAPI *HTimerEvent)(void);
    public:
        bool PlugOpen(char *FileName);
        int  RunPlugin(int Tim,char *WaveFile);
        void TimerEvent(void);
        void Initialize(void);
        TPlugin();
};
extern TPlugin *PlugOutPut;
extern TRegIniFile *IniFile;
extern int ExecuteFile(const AnsiString FileName,const AnsiString Params,const AnsiString DefaultDir,int ShowCmd);
extern AnsiString CurDir;
extern TList *StickForms;
extern int FindStickForm(HWND Form);
extern void StickFormMoveNotStick(HWND Form,int NewLeft,int NewTop);
extern void WebBrowserShow(void); // ��������� ���� Web ��������
extern void StickFormStayOnTop(bool Flag); // StayOnTop
//---------------------------------------------------------------------------
#endif

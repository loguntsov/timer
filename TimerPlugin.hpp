/*
    TimerPlugin.hpp

    Plugin API for Timer ver 3.60

    Copyright (c) Sergej Loguntsov 2001-2002
*/

#if !defined(__TIMERPLUGIN__)

#define __TIMERPLUGIN__

#include <windef.h>

#define VERTIMER 360;

#if defined(__BORLANDC__)
    #define _export  WINAPI
    #define TIMERAPI extern "C" __declspec(dllexport)
#elif defined(_MSC_VER)
    #define _export WINAPI
    #define TIMERAPI extern "C" __declspec(dllexport)

#endif


typedef void (WINAPI *TIMERAPISTICKFORMRESIZE)(
  HWND Form,
  int NewWidth,
  int NewHeight
);

typedef void (WINAPI *TIMERAPISTICKFORMMOVE)(
  HWND Form,
  int NewLeft,
  int NewTop
);
typedef void (WINAPI *TIMERAPIADDSTICKFORM)(
  HWND Form
);

typedef void (WINAPI *TIMERAPIDELETESTICKFORM)(
  HWND Form
);

typedef void (WINAPI *TIMERAPISTICKFORMENDMOVE)(void);

typedef void (WINAPI *TIMERAPIVIEWFORMAFTERTIME)(
  char * FileNameToPlay,
  HDC HBitmap,
  char * Str
);

typedef char * (WINAPI *TIMERAPIGETREGISTRYPATH)(void);

typedef HWND (WINAPI *TIMERAPIGETHWNDMAINTIMERFORM)(void);

typedef void (WINAPI *TIMERAPIWEBBROWSEROPENURL)(
  char * URL
);

typedef char * (WINAPI *TIMERAPIGETPLUGINDIR)(void);

typedef void (WINAPI *TIMERAPIBUTTONSTARTCLICK)(void);

typedef void (WINAPI *TIMERAPIBUTTONSTOPCLICK)(void);

typedef int (WINAPI *TIMERAPIGETLANGUAGE)(void);
// ����
#define lngRus 0
#define lngEng 1

typedef void (WINAPI *TIMERAPISETTIME)(long Time);
typedef long (WINAPI *TIMERAPIGETTIME)(void);

typedef int (WINAPI *TIMERAPIPRMREADINTEGER)(char * Section,char *Key, int Default); // ������ ������ �������� �� ���������� �������
typedef void (WINAPI *TIMERAPIPRMWRITEINTEGER)(char *Section,char *Key, int Value); // ������ ������ ��������
typedef char * (WINAPI *TIMERAPIPRMREADSTRING)(char *Section,char *Key,char *Default); // ������ ������
typedef void (WINAPI *TIMERAPIPRMWRITESTRING)(char *Section,char *Key, char * Value); // ������ ������

typedef char * (WINAPI *TIMERAPIGETMESSAGE)(void);
typedef void (WINAPI *TIMERAPISETMESSAGE)(char *);

struct TIMERAPISTRUCT // ������� ��������������� ������� ��������.
{
    int Size;
    TIMERAPISTICKFORMRESIZE StickFormResize; // ���������� ��� ��������� �������� ������ ����� �������
    TIMERAPISTICKFORMMOVE StickFormMove; // ���������� ��� ����������� ������� ����� �������.
    TIMERAPIADDSTICKFORM AddStickForm; // ���������� ����������� �����.
    TIMERAPIDELETESTICKFORM DeleteStickForm; // �������� ����������� �����.
    TIMERAPISTICKFORMENDMOVE StickFormEndMove; // ���������� �� ����� ����������� �������� ����� �������.
    TIMERAPIVIEWFORMAFTERTIME ViewFormAfterTime; // ������� ����������� ����� ������� "����� �������!!!"
    TIMERAPIGETREGISTRYPATH GetRegistryPath; // ���������� �������������� �������� �������� ��� �������.
    TIMERAPIGETHWNDMAINTIMERFORM GetHWNDMainTimerForm; // ���������� HWND ������� ����� �������.
    TIMERAPIWEBBROWSEROPENURL WebBrowserOpenURL; // ��������� �������� �� ������ URL
    TIMERAPIGETPLUGINDIR GetPluginDir; // ���������� ���� � �������� ��������
    TIMERAPIBUTTONSTARTCLICK ButtonStartClick; // ��������� ������� ������ ����
    TIMERAPIBUTTONSTOPCLICK ButtonStopClick; // ��������� ������� ������ ����
    TIMERAPIGETLANGUAGE GetLanguage; // ���������� ��� ����� (��� �������� �������������� ��������� �����)
    TIMERAPISETTIME SetTime; // ������ ����� ������� � ��������
    TIMERAPIGETTIME GetTime; // ������� ������� ����� ������� � ��������
    TIMERAPIPRMREADINTEGER PrmReadInteger; // ������ ������ �������� �� ���������� �������
    TIMERAPIPRMWRITEINTEGER PrmWriteInteger; // ������ ������ ��������
    TIMERAPIPRMREADSTRING PrmReadString; // ������ ������
    TIMERAPIPRMWRITESTRING PrmWriteString; // ������ ������
    TIMERAPISETMESSAGE SetFormMessage; // ������������� ������ ��� ����� ����������
    TIMERAPIGETMESSAGE GetFormMessage; // ���������� ������, ��� ����� ����������
};

/*
#if defined(__BORLANDC__) || defined(_MSC_VER) || defined(__GNUC__)
#ifdef __cplusplus
    extern "C"
    #ifdef _MSC_VER
        __declspec(dllexport)
    #endif
    {
#endif
// Exported Functions

    bool WINAPI _export Init(TIMERAPISTRUCT *x);
    int WINAPI _export VersionTimer(void);
    bool WINAPI _export Activate(void);
    bool WINAPI _export Close(void);
    void WINAPI _export Configure(void);
    void WINAPI _export AboutPlugin(void);
    int WINAPI _export RunPlugin(int Tim,char *WaveFile);
    char * WINAPI _export PluginName(void);
    void WINAPI _export TimerEvent(void);
    bool WINAPI _export StartClick(void);
    bool WINAPI _export StopClick(void);
    void WINAPI _export DropFiles(char *Str);

#ifdef __cplusplus
};
#endif
#endif

#if defined(__BORLANDC__)
  #pragma option -a.
#elif defined(__GNUC__) || (defined(__WATCOMC__) && (__WATCOMC__ < 1100)) || defined(__LCC__)
  #pragma pack()
#else
  #pragma pack(pop)
#endif
*/



#ifndef __TIMERPROGRAMMS__

//#define __EXPORT extern "C" __declspec(dllexport)

#ifndef __TIMERPLUGINMODULE__

    extern TIMERAPISTRUCT Timer;
#else

    TIMERAPISTRUCT Timer;

    TIMERAPI bool _export Init(TIMERAPISTRUCT *x)
    {
        Timer=*x;
        return true;
    }
    #undef __TIMERPLUGINMODULE__
#endif

#endif

#endif

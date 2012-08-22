//---------------------------------------------------------------------------

#ifndef TimerClassH
#define TimerClassH

#include "GlobalModule.h"
#include <Shellapi.h>
#include "SkinClass.h" 
class TForm1;
class TPluginList : public TList
{
private:
    TPlugin * GetItem(int Index);
    void SetItem(int Index,TPlugin * Plug);
public:
    void Add(TPlugin * Plug);
    __property TPlugin * Item[int Index]={read=GetItem, write=SetItem};
    bool Delete(int Index);
    bool Delete(TPlugin * Plug);
    bool AddPlugIn(AnsiString Path);
    //bool Clear(void);
    int Find(TPlugin *Plug); // ���������� ���������� ����� �������
    //~TPluginList();
};

class TTimerClass
{
private:
    SkinClass *FSkin;
    TForm1 *FD;
    TPluginList *FPlugIn;
    TPluginList * GetPlugIn(void);
    bool GetOption(int Index);
    void SetOption(int Index,bool Value);

    TIniFile *Param;
    TIniFile * GetParam(void);
    int x,y;
    NOTIFYICONDATA SysTrayIconData;
    SkinClass * GetSkinClass();
public:
    TTimerClass(
        TForm1 *Form // ��������� �� ����� ������������ ��������
    ); // �����������
    ~TTimerClass(); // ����������

    // ����
    bool ChangeSkin(AnsiString Path,TimerSkinType Type); // ��������� �����
    // ���������� true - ���� ��� ���������

    // PlugIn's
    TPlugin * AddPlugIn(AnsiString PathPlugIn); // ���������� ������� � ������ �������������
    // ���������� ���������� �������, NULL - ���� ������
    bool DeletePlugIn(TPlugin * PlugIn); // ������� ������ �� ������ �������������
    // ���������� true - ���� ��� ������
    __property TPluginList * PlugList={read=GetPlugIn};
    __property TIniFile * Prm={read=GetParam};
    __property bool Option[int Index]={read=GetOption,write=SetOption}; // ����� �������
    __property SkinClass * Skin={read=GetSkinClass};
    // ����������
    long Time;
    long State;
    AnsiString StrToMessage;

    // �������
    bool Start(void); // ������ �����
    bool Stop(void); // ����� �����
    void __fastcall OnActivate(TObject *Sender); // ��������� ����������
    void __fastcall OnDeactivate(TObject *Sender); // ����������� ����������
    void __fastcall OnMinimize(TObject *Sender); // ����������� ����������
    void __fastcall OnRestore(TObject *Sender); // �������������� ����������
    void OnPaint(void); // ��������� �� ����� �����������
    void ChangeXY(int X,int Y); // ���������� ��� ��������� ��������� ����

    // ������
    void Minimize(void); // �����������
    int GetState(void); // ��������� �������
    void NextSek(void); // ��������� �������
    void RefreshLang(AnsiString FileName); // ���������� �����
    void Exit(void); // ��� ������ �� ���������
    AnsiString GetTitle(void); // ��������� ��������� ���������� ������� �� ������ �����
    void LoadParam(void);// �������� ���������� ����������
    void RefreshFD(void);// ���������� FD
    void SavePluginList(void);// ���������� ����������� � �������
    void LoadPluginLIst(void);// �������� ���������� � ��������
    void CreateSysTray(void); // �������� ������ � SysTray
    void DeleteSysTray(void); // �������� ������ �� SysTray
    void RefreshSysTray(void); // ���������� ������ � SysTray
    AnsiString GetTimeString(void); // ���������� ������ � ��������
    int Play(AnsiString File);// ������ ����. ���� ����� - �� ��� ����� �� ���������.
    // ���������� ��� ������ - ���� ����.
};
extern TTimerClass *TimerClass;
// ���������
// ����
// 0 - ������� ������ �������
// 1 - ������� ����, ��� ������ �������������
// 2 - ������ �������� � SysTray'��
// 3 - ������ �������� �������� �����.
// 4
// 5
// 6
// 7
#define tmRun 1 // ��������
#define tmMinimize 2 // ��������������
#define tmMinimizeInSysTray 6 // ������������� � ������ ����
#define tmSysTray 4 // ������ � SysTray
#define tmIsActive 8 // ������ �������� �������� �����.
// ���� ����� ��� �ption
#define OptionCount 4
// ���������� �����
#define opMessage 0
#define opPlayMusic 1
#define opAlwaysOnTop 2
#define opMinimInSysTray 3
// �������������� ��������� Windows
#define msgSysTray (WM_APP+100)
//---------------------------------------------------------------------------
#endif

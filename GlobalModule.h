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
enum TimerSkinType {tmFile,tmFolder}; // Тип скина
class StickForm
{
    public:
    HWND Form;
    bool IsStick;
    StickForm(HWND Form);
};

extern void WINAPI StickFormResize(HWND Form,int NewWidth,int NewHeight); // Вызывается при изменении размеров формы плагина
extern void WINAPI StickFormMove(HWND Form,int NewLeft,int NewTop); // Вызывается при перемещении формы плагина.
extern void WINAPI StickFormEndMove(void);
extern void WINAPI AddStickForm(HWND Form); // Добавление формы, которая прилипает к основной форме таймера.
extern void WINAPI DeleteStickForm(HWND Form); // Удаление формы, прилипающей к основной форме таймера.
extern void WINAPI ViewFormAfterTime(char * FileNameToPlay,HDC HBitmap,char * Str);
extern char * WINAPI GetRegistryPath(void); // Возвращает местоположение настроек плагинов для таймера.
extern HWND WINAPI GetHWNDMainTimerForm(void); // Возвращает HWND главной формы Таймера.
extern void WINAPI WebBrowserOpenURL(char * URL);
extern char * WINAPI GetPluginDir(void);
extern void WINAPI ButtonStartClick(void); // Эмулирует нажатие кнопки ПУСК
extern void WINAPI ButtonStopClick(void); // Эмулирует нажатие кнопки СТОП
extern int WINAPI GetLanguage(void); // Возвращает код языка (для плагинов поддерживающих изменение языка)
extern long WINAPI GetTime(void); // Выводит текущее время таймера в секундах
extern void WINAPI SetTime(long Time); // Задает время таймера в секундах
extern int WINAPI PrmReadInteger(char * Section,char *Key, int Default); // Чтение целого значения из параметров Таймера
extern void WINAPI PrmWriteInteger(char *Section,char *Key, int Value); // Запись целого значения
extern char * WINAPI PrmReadString(char *Section,char *Key,char *Default); // Чтение строки
extern void WINAPI PrmWriteString(char *Section,char *Key, char * Value); // Запись строки
extern char * WINAPI GetFormMessage(void); // Возвращает строку, для формы оповещения
extern void WINAPI SetFormMessage(char * Str); // Устанавливает строку для формы оповещения
extern void ChangeMainStickForm(HWND Handle);
class TPluginClass
{
       private:
        int (WINAPI *HVersionTimer)(void); // Выдает минимальную версию таймера в которой роаботает плагин
        bool (WINAPI *HActivate)(void); // Активация плагина
        bool (WINAPI *HClose)(void); // Закрытие плагина
        void (WINAPI *HConfigure)(void); // Конфигурирование плагина
        void (WINAPI *HAboutPlugin)(void); // Вывод информации о плагине.
        char * (WINAPI *HPluginName)(void); // Возвращяет имя плагина.
        bool (WINAPI *HStartClick)(void);
        bool (WINAPI *HStopClick)(void);
        void (WINAPI *HDropFiles)(char * );
    public:
        HMODULE HMODULE;
        int VersionTimer(void); // Выдает минимальную версию таймера н которой роаботает плагин
        bool Activate(void); // Активация плагина
        bool Close(void); // Закрытие плагина
        void Configure(void); // Конфигурирование плагина
        void AboutPlugin(void); // Вывод информации о плагине.
        char * PluginName(void); // Возвращает имя плагина
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
extern void WebBrowserShow(void); // Открывает окно Web браузера
extern void StickFormStayOnTop(bool Flag); // StayOnTop
//---------------------------------------------------------------------------
#endif

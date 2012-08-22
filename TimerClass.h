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
    int Find(TPlugin *Plug); // Возвращает порядковыЙ номер плагина
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
        TForm1 *Form // указатель на форму используемую таймером
    ); // Конструктор
    ~TTimerClass(); // Деструктор

    // Скин
    bool ChangeSkin(AnsiString Path,TimerSkinType Type); // Изменение скина
    // Возвращает true - если все нормально

    // PlugIn's
    TPlugin * AddPlugIn(AnsiString PathPlugIn); // Добавление плагина к списку выполняющихся
    // Возвращает дескриптор плагина, NULL - если ошибка
    bool DeletePlugIn(TPlugin * PlugIn); // Удаляет плагин из списка выполняющихся
    // Возвращает true - если все хорошо
    __property TPluginList * PlugList={read=GetPlugIn};
    __property TIniFile * Prm={read=GetParam};
    __property bool Option[int Index]={read=GetOption,write=SetOption}; // Опции таймера
    __property SkinClass * Skin={read=GetSkinClass};
    // Переменные
    long Time;
    long State;
    AnsiString StrToMessage;

    // События
    bool Start(void); // Начало счета
    bool Stop(void); // Конец счета
    void __fastcall OnActivate(TObject *Sender); // Активация приложения
    void __fastcall OnDeactivate(TObject *Sender); // Деактивация приложения
    void __fastcall OnMinimize(TObject *Sender); // Минимизация приложения
    void __fastcall OnRestore(TObject *Sender); // Восстановление приложения
    void OnPaint(void); // Действует во время перерисовки
    void ChangeXY(int X,int Y); // Вызывается при изменении координат окна

    // Методы
    void Minimize(void); // Минимизация
    int GetState(void); // Состояние таймера
    void NextSek(void); // Следующая секунда
    void RefreshLang(AnsiString FileName); // Обновление языка
    void Exit(void); // При выходе из программы
    AnsiString GetTitle(void); // Возвравет заголовок приложения Таймера на нужном языке
    void LoadParam(void);// Загрузка логических параметров
    void RefreshFD(void);// Обновление FD
    void SavePluginList(void);// Сохранение информациии о плагина
    void LoadPluginLIst(void);// Загрузка информации о плагинах
    void CreateSysTray(void); // Создание иконки в SysTray
    void DeleteSysTray(void); // Удаление иконки из SysTray
    void RefreshSysTray(void); // Обновление иконки в SysTray
    AnsiString GetTimeString(void); // Возвращает строку с временем
    int Play(AnsiString File);// Играем файл. Если пусто - то имя файла по умолчанию.
    // возвращает код ошибки - если есть.
};
extern TTimerClass *TimerClass;
// Состояния
// Биты
// 0 - признак работы таймера
// 1 - признак того, что таймер минимизирован
// 2 - таймер работает с SysTray'ем
// 3 - таймер является активным окном.
// 4
// 5
// 6
// 7
#define tmRun 1 // Работает
#define tmMinimize 2 // Минимизмирован
#define tmMinimizeInSysTray 6 // Минимизирован в систем трай
#define tmSysTray 4 // Работа с SysTray
#define tmIsActive 8 // таймер является активным окном.
// Коды опций для Оption
#define OptionCount 4
// Количество опций
#define opMessage 0
#define opPlayMusic 1
#define opAlwaysOnTop 2
#define opMinimInSysTray 3
// Дополнительные сообщения Windows
#define msgSysTray (WM_APP+100)
//---------------------------------------------------------------------------
#endif

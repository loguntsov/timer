//---------------------------------------------------------------------------

#ifndef LanguageH
#define LanguageH
#include <inifiles.hpp>
class TLang
{
private:

public:
    TLang(AnsiString Path); // Путь к файлу ссобщений
    ~TLang();
    AnsiString Text(AnsiString Key); // Сообщение
    AnsiString Section;
    TIniFile *File;
};
#define BEG_LANG if (Lang!=NULL) {
#define ELSE_LANG } else {
#define END_LANG }
extern TLang * Lang;
extern AnsiString TL(AnsiString Key);
extern void LANGSECTION(AnsiString Section);
extern void LANGCONTROLCAPTION(TComponent *Control);
extern void LANGCONTROLHINT(TComponent *Control);
extern void LANGMESSAGE(AnsiString Key,AnsiString Msg,int Flags);
//---------------------------------------------------------------------------
#endif



//---------------------------------------------------------------------------

#define VCL_FULL
#include <vcl.h>
#pragma hdrstop
#define NO_WIN32_LEAN_AND_MEAN
#include <Shlobj.h>
#include <io.h>


#include "ShortCutClass.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

CShortCut::CShortCut(AnsiString FName)
{
    FileName=FName;
}
CShortCut::~CShortCut()
{
}
bool CShortCut::Create(void)
{
    bool results;
    HRESULT hres;
    IShellLink *psl;
    IPersistFile *ppf;
    wchar_t wsz[MAX_PATH];
    CoInitialize(NULL);
    hres = CoCreateInstance(CLSID_ShellLink, NULL,
    CLSCTX_INPROC_SERVER, IID_IShellLink, (void**)&psl);
    results=false;
    if (SUCCEEDED(hres))
    {
        psl->SetPath(LinkFile.c_str());
        psl->SetWorkingDirectory(LinkPath.c_str());
        psl->SetDescription(LinkDescription.c_str());
        hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);
        if (SUCCEEDED(hres))
        {
            MultiByteToWideChar(CP_ACP, 0, FileName.c_str(), -1,
            wsz, MAX_PATH);
            hres = ppf->Save(wsz, true);
            ppf->Release();
            results=true;
        }
        psl->Release();
    }
    CoUninitialize();
    return results;
}
bool CShortCut::Delete(void)
{
    return DeleteFile(FileName);
}

AnsiString GetSystemPath(int nFolder)
{
    char StartPath[MAXPATH];
    LPITEMIDLIST pidl;
    SHGetSpecialFolderLocation(Application->Handle, nFolder , &pidl); //CSIDL_STARTUP, CSIDL_STARTMENU, CSIDL_PROGRAMS
    SHGetPathFromIDList(pidl, StartPath);
    return AnsiString(StartPath);
}

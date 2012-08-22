//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TaskBar.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

// MyTaskBarAddIcon - adds an icon to the taskbar status area.
// Returns TRUE if successful, or FALSE otherwise.
// hwnd - handle to the window to receive callback messages.
// uID - identifier of the icon.
// hicon - handle to the icon to add.
// lpszTip - ToolTip text.
bool TaskBarAddIcon(HWND hwnd, UINT uID, HICON hicon, LPSTR lpszTip)
{
    /*BOOL res;
    NOTIFYICONDATA tnid;
    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = hwnd;
    tnid.uID = uID;
    tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    tnid.uCallbackMessage = MYWM_NOTIFYICON;
    tnid.hIcon = hicon;
    if (lpszTip)
        lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip));
    else
        tnid.szTip[0] = '\0';
    res = Shell_NotifyIcon(NIM_ADD, &tnid);
    if (hicon)
        DestroyIcon(hicon);
    return res;
}

// MyTaskBarDeleteIcon - deletes an icon from the taskbar status area.
// Returns TRUE if successful, or FALSE otherwise.
// hwnd - handle to the window that added the icon.
// uID - identifier of the icon to delete.
BOOL TaskBarDeleteIcon(HWND hwnd, UINT uID)
{
    BOOL res;
    NOTIFYICONDATA tnid;
    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = hwnd;
    tnid.uID = uID;
    res = Shell_NotifyIcon(NIM_DELETE, &tnid);
    return res;*/
}


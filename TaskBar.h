//---------------------------------------------------------------------------

#ifndef TaskBarH
#define TaskBarH
//---------------------------------------------------------------------------
// MyTaskBarAddIcon - adds an icon to the taskbar status area.
// Returns TRUE if successful, or FALSE otherwise.
// hwnd - handle to the window to receive callback messages.
// uID - identifier of the icon.
// hicon - handle to the icon to add.
// lpszTip - ToolTip text.
bool TaskBarAddIcon(HWND hwnd, UINT uID, HICON hicon, LPSTR lpszTip);


#endif

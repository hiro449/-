#pragma once
#include<windows.h>
#include<string>


class ValueWindow {

    HWND  hWnd;
    HFONT hFont;

public:

    ValueWindow(ValueWindow&& r)noexcept;
    auto operator =(ValueWindow&& r)noexcept->ValueWindow&;
    ValueWindow(HWND  hWnd);
    ~ValueWindow();
    operator std::wstring();
    ValueWindow& operator+=(wchar_t ch);
    ValueWindow& operator=(std::wstring s);


};

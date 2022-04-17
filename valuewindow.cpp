#include"ValueWindow.h"


    ValueWindow::ValueWindow(ValueWindow&& r)noexcept
    :hWnd(r.hWnd), hFont(r.hFont)
    {
    r.hWnd  = nullptr;
    r.hFont = nullptr;
    }

    auto ValueWindow::operator =(ValueWindow&& r)noexcept->ValueWindow&
    {
        std::swap(hFont, r.hFont);
        std::swap(hWnd, r.hWnd);
        return *this;
    }

    ValueWindow::ValueWindow(HWND hWnd)
        :hWnd(hWnd), hFont()
    {
        RECT rc;
        LOGFONTW lf;
        if (GetClientRect(hWnd, &rc)) {

            if (GetObjectW(GetStockObject(DEFAULT_GUI_FONT), sizeof lf, &lf))
            {
                lf.lfHeight = -rc.bottom;

                if ((hFont = CreateFontIndirectW(&lf)) != nullptr) {
                    SendMessageW(hWnd, WM_SETFONT, WPARAM(hFont), true);

                }
            }

        }

    }



     ValueWindow::~ValueWindow() {
    // DeleteObject(hFont);
     }

    ValueWindow::operator std::wstring() {

    if (const auto n = GetWindowTextLengthW(hWnd)) {
        std::wstring s(n, L'\0');
        s.resize(GetWindowTextW(hWnd, &s.front(), n + 1));
        return s;
    }
    else
        return {};
    }


    ValueWindow& ValueWindow::operator+=(wchar_t ch)
    {
    SetWindowTextW(hWnd, (static_cast<std::wstring>(*this) + ch).c_str());
    return *this;
    }


    ValueWindow& ValueWindow::operator=(std::wstring s)
    {
   
    SetWindowTextW(hWnd, s.c_str());
    return *this;
    }

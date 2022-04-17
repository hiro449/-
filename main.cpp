#include"Cal.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)

{

    DialogBoxParamW(
        hInstance
        , MAKEINTRESOURCEW(IDD_DIALOG1)
        , nullptr
        , [](
            HWND   hDlg
            , UINT   message
            , WPARAM wParam
            , LPARAM lParam

            )->INT_PTR
        {
            switch (message)
            {

            case WM_INITDIALOG:

                try
                {
                   HWND hvalue = GetDlgItem(hDlg, IDC_EDIT1);
                    
                   auto p = new Cal(ValueWindow(hvalue), TypeButton(GetDlgItem(hDlg, IDC_BUTTON_double)));
                SetWindowTextW(hvalue, L"0");
                SetLastError(0);
                if (SetWindowLongPtrW(hDlg, GWLP_USERDATA, LONG_PTR(p))) {
                    if (GetLastError()) {
                        delete p;
                    }

                }

               }
                catch (const std::exception& e)
                {
                    OutputDebugStringA(e.what());
                    OutputDebugStringA("\n");
                }

                return true;

            case WM_COMMAND:
                if (const auto p = reinterpret_cast<Cal*>(GetWindowLongPtrW(hDlg, GWLP_USERDATA))) {
                    p->HM_HANDLE(hDlg, wParam);
                }
               

                return true;

            case WM_NCDESTROY:
                delete reinterpret_cast<Cal*>(GetWindowLongPtrW(hDlg, GWLP_USERDATA));
                return true;


            default:
                return false;
            }

            return false;
        }
        , 0

            );




    return 0;
}

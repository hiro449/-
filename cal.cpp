#include"Cal.h"




    void Cal::first_digits(HWND hDlg, WPARAM wParam) {

        switch (DWORD(wParam))
        {

        case IDC_BUTTON0:  break;
        case IDC_BUTTON1: value = std::wstring(1, L'1'); state = &Cal::following_digits; break;
        case IDC_BUTTON2: value = std::wstring(1, L'2'); state = &Cal::following_digits; break;
        case IDC_BUTTON3: value = std::wstring(1, L'3'); state = &Cal::following_digits; break;
        case IDC_BUTTON4: value = std::wstring(1, L'4'); state = &Cal::following_digits; break;
        case IDC_BUTTON5: value = std::wstring(1, L'5'); state = &Cal::following_digits; break;
        case IDC_BUTTON6: value = std::wstring(1, L'6'); state = &Cal::following_digits; break;
        case IDC_BUTTON7: value = std::wstring(1, L'7'); state = &Cal::following_digits; break;
        case IDC_BUTTON8: value = std::wstring(1, L'8'); state = &Cal::following_digits; break;
        case IDC_BUTTON9: value = std::wstring(1, L'9'); state = &Cal::following_digits; break;

        case IDC_BUTTON_add:  perform(); lhs = value; op = &opAdd; state = &Cal::op_digits; break;
        case IDC_BUTTON_sub:  perform(); lhs = value; op = &opSub; state = &Cal::op_digits; break;
        case IDC_BUTTON_mul:  perform(); lhs = value; op = &opMul; state = &Cal::op_digits; break;
        case IDC_BUTTON_div:  perform(); lhs = value; op = &opDiv; state = &Cal::op_digits; break;

        case IDC_BUTTON_equ: perform(); lhs = value; op = nullptr; state = &Cal::op_digits; break;

        case IDC_BUTTON_dot: value += L'.'; state = &Cal::fractional_digits;  break;

        default:
            break;
        }

    }


    void Cal::following_digits(HWND hDlg, WPARAM wParam) {

        switch (DWORD(wParam))
        {

        case IDC_BUTTON0: value += L'0'; break;
        case IDC_BUTTON1: value += L'1'; break;
        case IDC_BUTTON2: value += L'2'; break;
        case IDC_BUTTON3: value += L'3'; break;
        case IDC_BUTTON4: value += L'4'; break;
        case IDC_BUTTON5: value += L'5'; break;
        case IDC_BUTTON6: value += L'6'; break;
        case IDC_BUTTON7: value += L'7'; break;
        case IDC_BUTTON8: value += L'8'; break;
        case IDC_BUTTON9: value += L'9'; break;

        case IDC_BUTTON_add:  perform(); lhs = value; op = &opAdd; state = &Cal::op_digits; break;
        case IDC_BUTTON_sub:  perform(); lhs = value; op = &opSub; state = &Cal::op_digits; break;
        case IDC_BUTTON_mul:  perform(); lhs = value; op = &opMul; state = &Cal::op_digits; break;
        case IDC_BUTTON_div:  perform(); lhs = value; op = &opDiv; state = &Cal::op_digits; break;

        case IDC_BUTTON_equ: perform(); lhs = value; op = nullptr; state = &Cal::op_digits; break;

        case IDC_BUTTON_dot: value += L'.'; state = &Cal::fractional_digits;  break;

        default:
            break;
        }

    }

    void Cal::op_digits(HWND hDlg, WPARAM wParam)
    {

        switch (DWORD(wParam))
        {

        case IDC_BUTTON0: value = std::wstring(1, L'0'); state = &Cal::following_digits; break;
        case IDC_BUTTON1: value = std::wstring(1, L'1'); state = &Cal::following_digits; break;
        case IDC_BUTTON2: value = std::wstring(1, L'2'); state = &Cal::following_digits; break;
        case IDC_BUTTON3: value = std::wstring(1, L'3'); state = &Cal::following_digits; break;
        case IDC_BUTTON4: value = std::wstring(1, L'4'); state = &Cal::following_digits; break;
        case IDC_BUTTON5: value = std::wstring(1, L'5'); state = &Cal::following_digits; break;
        case IDC_BUTTON6: value = std::wstring(1, L'6'); state = &Cal::following_digits; break;
        case IDC_BUTTON7: value = std::wstring(1, L'7'); state = &Cal::following_digits; break;
        case IDC_BUTTON8: value = std::wstring(1, L'8'); state = &Cal::following_digits; break;
        case IDC_BUTTON9: value = std::wstring(1, L'9'); state = &Cal::following_digits; break;

        case IDC_BUTTON_add: op = &opAdd; break;
        case IDC_BUTTON_sub: op = &opSub; break;
        case IDC_BUTTON_mul: op = &opMul; break;
        case IDC_BUTTON_div: op = &opDiv; break;

        case IDC_BUTTON_dot: value = L"0.";  state = &Cal::fractional_digits; break;

     

        default:
            break;
        }

    }

    void Cal::fractional_digits(HWND hDlg, WPARAM wParam)
    {

        switch (DWORD(wParam))
        {

        case IDC_BUTTON0: value += L'0'; break;
        case IDC_BUTTON1: value += L'1'; break;
        case IDC_BUTTON2: value += L'2'; break;
        case IDC_BUTTON3: value += L'3'; break;
        case IDC_BUTTON4: value += L'4'; break;
        case IDC_BUTTON5: value += L'5'; break;
        case IDC_BUTTON6: value += L'6'; break;
        case IDC_BUTTON7: value += L'7'; break;
        case IDC_BUTTON8: value += L'8'; break;
        case IDC_BUTTON9: value += L'9'; break;

        case IDC_BUTTON_add:  perform(); lhs = value; op = &opAdd; state = &Cal::op_digits; break;
        case IDC_BUTTON_sub:  perform(); lhs = value; op = &opSub; state = &Cal::op_digits; break;
        case IDC_BUTTON_mul:  perform(); lhs = value; op = &opMul; state = &Cal::op_digits; break;
        case IDC_BUTTON_div:  perform(); lhs = value; op = &opDiv; state = &Cal::op_digits; break;

        case IDC_BUTTON_dot:  break;

        case IDC_BUTTON_equ: perform(); lhs = value; op = nullptr; state = &Cal::op_digits; break;

        default:
            break;
        }


    }

    void Cal::perform()
    {

        if (op) {
            value = op->compute(type, lhs, value);
        }
    }



    Cal::Cal(ValueWindow&& value, TypeButton&& type)
        :value(std::move(value)), state(&Cal::first_digits), type(type), op()
    {

    }



    void Cal::HM_HANDLE(HWND hDlg, WPARAM wParam) {

        switch (DWORD(wParam))
        {
        case IDC_BUTTON_double:
            type.changetype();
            break;

        case IDC_BUTTON_clear:
            op = nullptr; value = L"0"; state = &Cal::first_digits;
            break;

        case IDCANCEL:
            EndDialog(hDlg, IDCANCEL);
            break;


        default:
        (this->*state)(hDlg, wParam);
            break;
        }

    }

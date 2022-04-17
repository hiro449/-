#pragma once
#include"resource.h"
#include<string>
#include<windows.h>
#include"ValueWindow.h"
#include"BinaryOperator.h"
#include"TypeButton.h"

class Cal {

    HWND         hWnd;
    ValueWindow value;
    std::wstring lhs ;
    TypeButton   type;
    const BinaryOperator *op;
    void (Cal::* state)(HWND hDlg, WPARAM wParam);

public:

   void first_digits(HWND hDlg, WPARAM wParam);
   void following_digits(HWND hDlg, WPARAM wParam);
   void op_digits(HWND hDlg, WPARAM wParam);
   void fractional_digits(HWND hDlg, WPARAM wParam);
   void perform();
   Cal(ValueWindow&& value, TypeButton&& type);
   void HM_HANDLE(HWND hDlg, WPARAM wParam);

};

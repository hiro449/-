#include "TypeButton.h"
#include"ValueType.h"

static const LPCWSTR rgp[] = {

	  L"DOUBLE"
	, L"QWORD"
	, L"DWORD"
	, L"WORD"
	, L"BYTE"

};




TypeButton::TypeButton(HWND hWnd)
	:hWnd(hWnd)
{

}

void TypeButton::changetype()
{
	const auto i = (GetWindowLongPtrW(hWnd, GWLP_USERDATA) + 1) % _countof(rgp);
	SetWindowLongPtrW(hWnd, GWLP_USERDATA, i);
	SetWindowTextW(hWnd, rgp[i]);
}

TypeButton::operator ValueType() const noexcept
{
	return static_cast<ValueType>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
}

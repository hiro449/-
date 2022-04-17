#pragma once
#include<windows.h>

enum class ValueType;

class TypeButton
{
	HWND hWnd;


public:

	TypeButton(HWND hWnd);

	void changetype();

	operator ValueType() const noexcept;

};

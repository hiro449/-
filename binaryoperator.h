#pragma once
#include<string>

#include"ValueType.h"



struct BinaryOperator {

	double            (*p_DOUBLE)(double             lhs, double             rhs);
	unsigned long long(*p_QWORD )(unsigned long long lhs, unsigned long long rhs);
	unsigned long     (*p_DWORD )(unsigned long      lhs, unsigned long      rhs);
	unsigned short    (*p_WORD  )(unsigned short     lhs, unsigned short     rhs);
	unsigned char     (*p_BYTE  )(unsigned char      lhs, unsigned char      rhs);


	std::wstring compute(ValueType t,  const std::wstring& lhs, const std::wstring& rhs)const;

};


extern const BinaryOperator opAdd;
extern const BinaryOperator opSub;
extern const BinaryOperator opMul;
extern const BinaryOperator opDiv;

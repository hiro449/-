#include "BinaryOperator.h"
#include<sstream>
#include<windows.h>
#include"TypeButton.h"

template <class T>T op_add(T lhs, T rhs) { return lhs + rhs; }
template <class T>T op_sub(T lhs, T rhs) { return lhs - rhs; }
template <class T>T op_mul(T lhs, T rhs) { return lhs * rhs; }
template <class T>T op_div(T lhs, T rhs) { return lhs / rhs; }

const BinaryOperator opAdd = {


     op_add<double            >
    ,op_add<unsigned long long>
    ,op_add<unsigned long     >
    ,op_add<unsigned short    >
    ,op_add<unsigned char     >

};
const BinaryOperator opSub = {


     op_sub<double            >
    ,op_sub<unsigned long long>
    ,op_sub<unsigned long     >
    ,op_sub<unsigned short    >
    ,op_sub<unsigned char     >

};
const BinaryOperator opMul = {


     op_mul<double            >
    ,op_mul<unsigned long long>
    ,op_mul<unsigned long     >
    ,op_mul<unsigned short    >
    ,op_mul<unsigned char     >

};
const BinaryOperator opDiv = {


     op_div<double            >
    ,op_div<unsigned long long>
    ,op_div<unsigned long     >
    ,op_div<unsigned short    >
    ,op_div<unsigned char     >

};


#include<iomanip>
std::wstring BinaryOperator::compute(ValueType t,  const std::wstring& lhs, const std::wstring& rhs)const
{


    

    switch (t)
    {
    case ValueType::t_DOUBLE:
        return (std::wstringstream() << std::setprecision(std::numeric_limits<double>::digits10) << (*p_DOUBLE)(std::stod(lhs), std::stod(rhs))).str();
      
    case ValueType::t_QWORD:
        return (std::wostringstream() << (*p_QWORD)(std::stoull(lhs), std::stoull(rhs))).str();

    case ValueType::t_DWORD:
        return (std::wostringstream() << (*p_DWORD)(std::stoul (lhs), std::stoul (rhs))).str();

    case ValueType::t_WORD:
        return (std::wostringstream() << (*p_WORD )(static_cast<WORD>(std::stoul(lhs)), static_cast<WORD>(std::stoul(rhs)))).str();
      
    case ValueType::t_BYTE:
        return (std::wostringstream() << (*p_BYTE )(static_cast<BYTE>(std::stoul(lhs)), static_cast<BYTE>(std::stoul(rhs)))).str();
     
  
    }



    return std::wstring();
}

#include <vector>
#include <string>
#include <graphics.h>

#include <iostream>
using namespace std;

#ifdef _UNICODE
    typedef wstring tstring;
#define to_tstring(x) to_wstring(x)
#else
    typedef string tstring;
    #define to_tstring(x) to_string(x)
#endif

extern int cursorPosition; // 光标位置

// 将中缀表达式转换为后缀表达式
vector<tstring> RPN(tstring &a);
// 计算后缀表达式
tstring calcRPN(vector<tstring> &a);
// 计算两个数的运算
tstring calculate(tstring &a, tstring &b, TCHAR opt);
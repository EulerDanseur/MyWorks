#include <tchar.h>
//#include <ctype.h>
#include <vector>
#include <string>
//#include <iostream>
using namespace std;

#define TEXT(x) _T(x)

#ifdef _UNICODE
typedef wstring tstring;
#define to_tstring(x) to_wstring(x)
#define fromStdTString(x) fromStdWString(x)
#define toStdTString(x) toStdWString(x)
#else
typedef string tstring;
#define to_tstring(x) to_string(x)
#define fromStdTString(x) fromStdString(x)
#define toStdTString(x) toStdString(x)
#endif

extern int cursorPosition;

class Expression
{

public:
    tstring input;

    tstring result;

    vector<tstring> inputRPN;

    tstring warning;


    bool calculate()
    {
        result = TEXT("");
        inputRPN = {};
        return (RPN() && calcRPN());
    }
    // 将中缀表达式转换为后缀表达式
    bool RPN();
    // 计算后缀表达式
    bool calcRPN();
    // 计算两个数的运算
    tstring calcnum(tstring& a, tstring& b, TCHAR opt);
};

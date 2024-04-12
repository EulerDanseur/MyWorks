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

extern int cursorPosition; // ���λ��

// ����׺���ʽת��Ϊ��׺���ʽ
vector<tstring> RPN(tstring &a);
// �����׺���ʽ
tstring calcRPN(vector<tstring> &a);
// ����������������
tstring calculate(tstring &a, tstring &b, TCHAR opt);
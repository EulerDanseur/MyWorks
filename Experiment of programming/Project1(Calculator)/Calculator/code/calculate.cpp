#include "calculate.h"
#include "graphicSurface.h"

/**************** 全局变量 *****************/

tstring input = TEXT(""); // 输入的表达式

tstring result = TEXT(""); // 计算结果

vector<tstring> inputRPN = {}; // 输入表达式的后缀表达式

/**************** 函数实现 *****************/
vector<tstring> RPN(tstring &expr)
{
    vector<tstring> exprRPN;         // 储存后缀表达式
    tstring num = TEXT("");          // 储存数字
    tstring optStack = TEXT("");     // 储存运算符
    tstring nullstr = TEXT("");      // 空字符串
    bool afterDot = false;           // 判断是否有小数点
    bool isExpressionStart = true;   // 判断表达式是否开始
    bool isAfterPlusOrMinus = false; // 判断是否在加减运算符后
    bool isAfterMultiOrDiv = false;  // 判断是否在乘除运算符后

#ifdef DEBUG
    std::cout << expr.length() << endl;
#endif

    if (expr[0] == '.')
    {
        expr.insert(0, 1, TEXT('0'));
        cursorPosition++;
        showinput();
    }
    // 将表达式中的括号前后加上乘号·
    bool ifvalidInput = true; // 判断输入是否合法
    for (int i = 1; expr.length() >= 1 && i < expr.length(); i++)
    {
        // 有括号，括号前后加上乘号·
        if ((isdigit(expr[i - 1]) && expr[i] == '(') || (isdigit(expr[i]) && expr[i - 1] == ')') || (expr[i] == '(' && expr[i - 1] == ')'))
        {
            expr.insert(i, 1, TEXT('·'));
            cursorPosition++;
            showinput();
        }
        // 小数点括号
        else if ((expr[i - 1] == '.' && expr[i] == '('))
        {
            showwarningbar(TEXT("Dot Before ("));
            exprRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }
        else if (expr[i] == '.' && expr[i - 1] == ')')
        {
            showwarningbar(TEXT("Dot After ("));
            exprRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }
        // 空括号不合法
        else if (expr[i] == ')' && expr[i - 1] == '(')
        {
            showwarningbar(TEXT("Null brackets"));
            exprRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }
        else if (expr[i] == '.' && expr[i - 1] == '.')
        {
            showwarningbar(TEXT("Dot Duplicated"));
            exprRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }

        else if ((!isdigit(expr[i - 1]) && expr[i] == '.') || (!isdigit(expr[i]) && expr[i - 1] == '.') || (expr[i] == '(' && expr[i - 1] == ')'))
        {
            expr.insert(i, 1, TEXT('0'));
            cursorPosition++;
            showinput();
        }
    }
    if (!ifvalidInput)
        return exprRPN;

    // 将中缀表达式转换为后缀表达式
    for (auto i : expr) // 遍历中缀表达式
    {
        if (i >= '0' && i <= '9') // 如果是数字
        {
            // 清空状态
            isExpressionStart = false;
            isAfterPlusOrMinus = false;
            isAfterMultiOrDiv = false;

            // 读取数字
            num.push_back(i);
        }
        else if (i == '.') // 如果是小数点
        {
            if (afterDot) // 判断小数点是否重复
            {
                showwarningbar(TEXT("Dot is repeated"));
                exprRPN.clear();
                return exprRPN;
            }
            num.push_back(i);
            afterDot = true;
        }
        else
        {
            afterDot = false; // 重置小数点状态

            if (num.length()) // 数字放入后缀表达式
            {
                exprRPN.push_back(num);
                num = TEXT("");
            }

            switch (i)
            {
            case ' ': // 忽略空格
                break;

            case '(': // 左括号入栈
                isExpressionStart = true;
                isAfterPlusOrMinus = false;
                isAfterMultiOrDiv = false;
                optStack.push_back(i);
                break;

            case ')':                       // 右括号出栈
                if (optStack.length() == 0) // 出栈后括号不匹配
                {
                    showwarningbar(TEXT("Unmatched brackets"));
                    exprRPN.clear();
                    exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 出现符号重叠
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }
                while (optStack.back() != '(') // 括号内全部出栈
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();

                    if (optStack.length() == 0) // 找不到左括号，出栈后括号不匹配
                    {
                        showwarningbar(TEXT("Unmatched brackets"));
                        exprRPN.clear();
                        return exprRPN;
                    }
                }
                optStack.pop_back(); // 左括号出栈舍弃
                break;

            case '+': // 加减运算符，则直接加入后缀表达式
            case '-':
                if (isExpressionStart) // 如果是表达式开头
                {
                    exprRPN.push_back(TEXT("0")); // 前面加入 0
                    isExpressionStart = false;    // 重置状态
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 符号重叠
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }

                // 重置状态
                isAfterPlusOrMinus = true;
                isAfterMultiOrDiv = false;

                // 重复出栈
                while (optStack.length() && optStack.back() != '(')
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;

            case TEXT('×'): // 乘除运算符
            case '/':
            case TEXT('·'):
                if (isExpressionStart) // 如果是表达式开头
                {
                    showwarningbar(TEXT("Start with × or /"));
                    exprRPN.clear();
                    return exprRPN;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 符号重叠
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }

                // 重置状态
                isAfterMultiOrDiv = true;

                // 重复出栈
                while (optStack.length() && optStack.back() != '(' && (optStack.back() == TEXT('×') || optStack.back() == '/'))
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;

            // 其他情况，不合法
            default:
                exprRPN.clear();
                return exprRPN;
            }
        }
    }

    // 判断表达式结尾是否合法
    if (expr.size() && !(expr.back() >= '0' && expr.back() <= '9') && expr.back() != '.' && expr.back() != ')')
    {
        exprRPN.clear();
        return exprRPN;
    }

    while (num.length()) // 最后一个数字
    {
        exprRPN.push_back(num);
        num = TEXT("");
    }

    while (!optStack.empty()) // 出栈
    {
        if (optStack.back() == '(') // 括号不匹配
        {
            showwarningbar(TEXT("Unmatched brackets"));
            exprRPN.clear();
            return exprRPN;
        }
        exprRPN.push_back(optStack.back() + nullstr);
        optStack.pop_back();
    }

    return exprRPN;
}

tstring calcRPN(vector<tstring> &expr)
{
    vector<tstring> number; // 存储表达式中的数字

    for (unsigned i = 0; i < expr.size(); i++)
    {
        // 如果是运算符，计算
        if (expr[i] == TEXT("+") || expr[i] == TEXT("-") || expr[i] == TEXT("×") || expr[i] == TEXT("/") || expr[i] == TEXT("·"))
        {
            tstring a = number.back();
            number.pop_back();
            tstring b = number.back();
            number.pop_back();
            tstring c = calculate(b, a, expr[i][0]);
            number.push_back(c);
        }
        // 如果是数字，直接入栈
        else
        {
            number.push_back(expr[i]);
        }
    }
    if (number.size())
        return number[0];
    else
        return TEXT("");
}

tstring calculate(tstring &a, tstring &b, TCHAR opt)
{
    if (opt == '+')
        return to_tstring(stod(a) + stod(b));
    else if (opt == '-')
        return to_tstring(stod(a) - stod(b));
    else if (opt == TEXT('×') || opt == TEXT('·'))
        return to_tstring(stod(a) * stod(b));
    else if (opt == '/')
        return to_tstring(stod(a) / stod(b));
    else
        return TEXT("Wrong Operator");
}

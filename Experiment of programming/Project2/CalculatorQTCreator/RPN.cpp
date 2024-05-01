#include "RPN.h"

/**************** 函数实现 *****************/
bool Expression::RPN()
{
    tstring num = TEXT("");          // 储存数字
    tstring optStack = TEXT("");     // 储存运算符
    tstring nullstr = TEXT("");      // 空字符串

    warning = TEXT("");

    bool afterDot = false;           // 判断是否有小数点
    bool isExpressionStart = true;   // 判断表达式是否开始
    bool isAfterPlusOrMinus = false; // 判断是否在加减运算符后
    bool isAfterMultiOrDiv = false;  // 判断是否在乘除运算符后

#ifdef DEBUG
    std::cout << expr.length() << endl;
#endif

    if (input[0] == '.')
    {
        input.insert(0, 1, TEXT('0'));
        cursorPosition++;
    }
    // 将表达式中的括号前后加上乘号·
    bool ifvalidInput = true; // 判断输入是否合法
    for (int i = 1; input.length() >= 1 && i < input.length(); i++)
    {
        // 有括号，括号前后加上乘号·
        if ((isdigit(input[i - 1]) && input[i] == '(') || (isdigit(input[i]) && input[i - 1] == ')') || (input[i] == '(' && input[i - 1] == ')'))
        {
            input.insert(i, 1, TEXT('·'));
            cursorPosition++;
        }
        // 小数点括号
        else if ((input[i - 1] == '.' && input[i] == '('))
        {
            warning = TEXT("Dot Before (");
            inputRPN.clear();
            ifvalidInput = false;
        }
        else if (input[i] == '.' && input[i - 1] == ')')
        {
            warning = (TEXT("Dot After ("));
            inputRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }
        // 空括号不合法
        else if (input[i] == ')' && input[i - 1] == '(')
        {
            warning = (TEXT("Null brackets"));
            inputRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }
        else if (input[i] == '.' && input[i - 1] == '.')
        {
            warning = (TEXT("Dot Duplicated"));
            inputRPN.clear();
            // exprRPN.push_back(TEXT("need backspace"));
            ifvalidInput = false;
        }

        else if ((!isdigit(input[i - 1]) && input[i] == '.') || (!isdigit(input[i]) && input[i - 1] == '.') || (input[i] == '(' && input[i - 1] == ')'))
        {
            input.insert(i, 1, TEXT('0'));
            cursorPosition++;
        }
    }
    if (!ifvalidInput)
        return false;

    // 将中缀表达式转换为后缀表达式
    for (auto i : input) // 遍历中缀表达式
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
                warning = (TEXT("Dot is repeated"));
                inputRPN.clear();
                return false;
            }
            num.push_back(i);
            afterDot = true;
        }
        else
        {
            afterDot = false; // 重置小数点状态

            if (num.length()) // 数字放入后缀表达式
            {
                inputRPN.push_back(num);
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
                    warning = (TEXT("Unmatched brackets"));
                    inputRPN.clear();
                    return false;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 出现符号重叠
                {
                    warning = (TEXT("Operator Duplication"));
                    inputRPN.clear();
                    return false;
                }
                while (optStack.back() != '(') // 括号内全部出栈
                {
                    inputRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();

                    if (optStack.length() == 0) // 找不到左括号，出栈后括号不匹配
                    {
                        warning = (TEXT("Unmatched brackets"));
                        inputRPN.clear();
                        return false;
                    }
                }
                optStack.pop_back(); // 左括号出栈舍弃
                break;

            case '+': // 加减运算符，则直接加入后缀表达式
            case '-':
                if (isExpressionStart) // 如果是表达式开头
                {
                    inputRPN.push_back(TEXT("0")); // 前面加入 0
                    isExpressionStart = false;    // 重置状态
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 符号重叠
                {
                    warning = (TEXT("Operator Duplication"));
                    inputRPN.clear();
                    return false;
                }

                // 重置状态
                isAfterPlusOrMinus = true;
                isAfterMultiOrDiv = false;

                // 重复出栈
                while (optStack.length() && optStack.back() != '(')
                {
                    inputRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;
            
            case '*':
            case TEXT('×'): // 乘除运算符
            case '/':
            case TEXT('·'):
                if (isExpressionStart) // 如果是表达式开头
                {
                    warning = (TEXT("Start with × or /"));
                    inputRPN.clear();
                    return false;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // 符号重叠
                {
                    warning = (TEXT("Operator Duplication"));
                    inputRPN.clear();
                    return false;
                }

                // 重置状态
                isAfterMultiOrDiv = true;

                // 重复出栈
                while (optStack.length() && optStack.back() != '(' && (optStack.back() == TEXT('×') || optStack.back() == '/'))
                {
                    inputRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;

                // 其他情况，不合法
            default:
                inputRPN.clear();
                return false;
            }
        }
    }

    // 判断表达式结尾是否合法
    if (input.size() && !(input.back() >= '0' && input.back() <= '9') && input.back() != '.' && input.back() != ')')
    {
        inputRPN.clear();
        return false;
    }

    while (num.length()) // 最后一个数字
    {
        inputRPN.push_back(num);
        num = TEXT("");
    }

    while (!optStack.empty()) // 出栈
    {
        if (optStack.back() == '(') // 括号不匹配
        {
            warning = (TEXT("Unmatched brackets"));
            inputRPN.clear();
            return false;
        }
        inputRPN.push_back(optStack.back() + nullstr);
        optStack.pop_back();
    }



    return true;
}

bool Expression::calcRPN()
{
    vector<tstring> number; // 存储表达式中的数字

    for (unsigned i = 0; i < inputRPN.size(); i++)
    {
        // 如果是运算符，计算
        if (inputRPN[i] == TEXT("+") || inputRPN[i] == TEXT("-") || inputRPN[i] == TEXT("×") || inputRPN[i] == TEXT("/") || inputRPN[i] == TEXT("·") || inputRPN[i] == TEXT("*"))
        {
            tstring a = number.back();
            number.pop_back();
            tstring b = number.back();
            number.pop_back();
            tstring c = calcnum(b, a, inputRPN[i][0]);
            number.push_back(c);
        }
        // 如果是数字，直接入栈
        else
        {
            number.push_back(inputRPN[i]);
        }
    }
    if (number.size())
        result = number[0];
    else
    {
        result = TEXT("");
        return 0;
    }
    if (result == TEXT("inf"))
    {
        result = TEXT("+∞");
        return 1;
    }
    else if (result == TEXT("-inf"))
    {
        result = TEXT("-∞");
        return 1;
    }
    bool isFloat = false; // 判断有小数点
    for (auto i : result)
    {
        if (i == '.')
        {
            isFloat = true;
            break;
        }
    }
    if (isFloat)
    {
        for (auto i = result.length() - 1; i >= 0 && result[i] != '.'; i--)
        {
            if (result != TEXT("0") && result[i] == '0')
                result.erase(i);
            else
            {
                isFloat = true;
                break;
            }
        }
        if (result.back() == '.') // 不是小数则去掉小数点
            result.erase(result.end() - 1);
    }

    return 1;
}

tstring Expression::calcnum(tstring& a, tstring& b, TCHAR opt)
{
    if (opt == '+')
        return to_tstring(stod(a) + stod(b));
    else if (opt == '-')
        return to_tstring(stod(a) - stod(b));
    else if (opt == TEXT('×') || opt == TEXT('·') || opt == TEXT('*'))
        return to_tstring(stod(a) * stod(b));
    else if (opt == '/')
        return to_tstring(stod(a) / stod(b));
    else
        return TEXT("Wrong Operator");
}

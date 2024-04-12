#include "calculate.h"
#include "graphicSurface.h"

/**************** ȫ�ֱ��� *****************/

tstring input = TEXT(""); // ����ı��ʽ

tstring result = TEXT(""); // ������

vector<tstring> inputRPN = {}; // ������ʽ�ĺ�׺���ʽ

/**************** ����ʵ�� *****************/
vector<tstring> RPN(tstring &expr)
{
    vector<tstring> exprRPN;         // �����׺���ʽ
    tstring num = TEXT("");          // ��������
    tstring optStack = TEXT("");     // ���������
    tstring nullstr = TEXT("");      // ���ַ���
    bool afterDot = false;           // �ж��Ƿ���С����
    bool isExpressionStart = true;   // �жϱ��ʽ�Ƿ�ʼ
    bool isAfterPlusOrMinus = false; // �ж��Ƿ��ڼӼ��������
    bool isAfterMultiOrDiv = false;  // �ж��Ƿ��ڳ˳��������

#ifdef DEBUG
    std::cout << expr.length() << endl;
#endif

    if (expr[0] == '.')
    {
        expr.insert(0, 1, TEXT('0'));
        cursorPosition++;
        showinput();
    }
    // �����ʽ�е�����ǰ����ϳ˺š�
    bool ifvalidInput = true; // �ж������Ƿ�Ϸ�
    for (int i = 1; expr.length() >= 1 && i < expr.length(); i++)
    {
        // �����ţ�����ǰ����ϳ˺š�
        if ((isdigit(expr[i - 1]) && expr[i] == '(') || (isdigit(expr[i]) && expr[i - 1] == ')') || (expr[i] == '(' && expr[i - 1] == ')'))
        {
            expr.insert(i, 1, TEXT('��'));
            cursorPosition++;
            showinput();
        }
        // С��������
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
        // �����Ų��Ϸ�
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

    // ����׺���ʽת��Ϊ��׺���ʽ
    for (auto i : expr) // ������׺���ʽ
    {
        if (i >= '0' && i <= '9') // ���������
        {
            // ���״̬
            isExpressionStart = false;
            isAfterPlusOrMinus = false;
            isAfterMultiOrDiv = false;

            // ��ȡ����
            num.push_back(i);
        }
        else if (i == '.') // �����С����
        {
            if (afterDot) // �ж�С�����Ƿ��ظ�
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
            afterDot = false; // ����С����״̬

            if (num.length()) // ���ַ����׺���ʽ
            {
                exprRPN.push_back(num);
                num = TEXT("");
            }

            switch (i)
            {
            case ' ': // ���Կո�
                break;

            case '(': // ��������ջ
                isExpressionStart = true;
                isAfterPlusOrMinus = false;
                isAfterMultiOrDiv = false;
                optStack.push_back(i);
                break;

            case ')':                       // �����ų�ջ
                if (optStack.length() == 0) // ��ջ�����Ų�ƥ��
                {
                    showwarningbar(TEXT("Unmatched brackets"));
                    exprRPN.clear();
                    exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // ���ַ����ص�
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }
                while (optStack.back() != '(') // ������ȫ����ջ
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();

                    if (optStack.length() == 0) // �Ҳ��������ţ���ջ�����Ų�ƥ��
                    {
                        showwarningbar(TEXT("Unmatched brackets"));
                        exprRPN.clear();
                        return exprRPN;
                    }
                }
                optStack.pop_back(); // �����ų�ջ����
                break;

            case '+': // �Ӽ����������ֱ�Ӽ����׺���ʽ
            case '-':
                if (isExpressionStart) // ����Ǳ��ʽ��ͷ
                {
                    exprRPN.push_back(TEXT("0")); // ǰ����� 0
                    isExpressionStart = false;    // ����״̬
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // �����ص�
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }

                // ����״̬
                isAfterPlusOrMinus = true;
                isAfterMultiOrDiv = false;

                // �ظ���ջ
                while (optStack.length() && optStack.back() != '(')
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;

            case TEXT('��'): // �˳������
            case '/':
            case TEXT('��'):
                if (isExpressionStart) // ����Ǳ��ʽ��ͷ
                {
                    showwarningbar(TEXT("Start with �� or /"));
                    exprRPN.clear();
                    return exprRPN;
                }
                if (isAfterPlusOrMinus || isAfterMultiOrDiv) // �����ص�
                {
                    showwarningbar(TEXT("Operator Duplication"));
                    exprRPN.clear();
                    // exprRPN.push_back(TEXT("need backspace"));
                    return exprRPN;
                }

                // ����״̬
                isAfterMultiOrDiv = true;

                // �ظ���ջ
                while (optStack.length() && optStack.back() != '(' && (optStack.back() == TEXT('��') || optStack.back() == '/'))
                {
                    exprRPN.push_back(optStack.back() + nullstr);
                    optStack.pop_back();
                }
                optStack.push_back(i);
                break;

            // ������������Ϸ�
            default:
                exprRPN.clear();
                return exprRPN;
            }
        }
    }

    // �жϱ��ʽ��β�Ƿ�Ϸ�
    if (expr.size() && !(expr.back() >= '0' && expr.back() <= '9') && expr.back() != '.' && expr.back() != ')')
    {
        exprRPN.clear();
        return exprRPN;
    }

    while (num.length()) // ���һ������
    {
        exprRPN.push_back(num);
        num = TEXT("");
    }

    while (!optStack.empty()) // ��ջ
    {
        if (optStack.back() == '(') // ���Ų�ƥ��
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
    vector<tstring> number; // �洢���ʽ�е�����

    for (unsigned i = 0; i < expr.size(); i++)
    {
        // ����������������
        if (expr[i] == TEXT("+") || expr[i] == TEXT("-") || expr[i] == TEXT("��") || expr[i] == TEXT("/") || expr[i] == TEXT("��"))
        {
            tstring a = number.back();
            number.pop_back();
            tstring b = number.back();
            number.pop_back();
            tstring c = calculate(b, a, expr[i][0]);
            number.push_back(c);
        }
        // ��������֣�ֱ����ջ
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
    else if (opt == TEXT('��') || opt == TEXT('��'))
        return to_tstring(stod(a) * stod(b));
    else if (opt == '/')
        return to_tstring(stod(a) / stod(b));
    else
        return TEXT("Wrong Operator");
}

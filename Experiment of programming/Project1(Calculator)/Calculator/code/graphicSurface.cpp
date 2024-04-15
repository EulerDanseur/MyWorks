#include "graphicSurface.h"

/**************************ȫ�ֱ�������*********************************/
ExMessage mousemsg = {0};     // �����Ϣ
ExMessage &keymsg = mousemsg; // ������Ϣ
bool inputChanged = false;    // �����Ƿ����ı�
int cursorPosition = 0;       // ���λ��

void showscreen()
{

    BeginBatchDraw();

    // ��Ϣѭ��
    while (!peekmessage(&mousemsg, EX_MOUSE | EX_KEY))
    {
        // ��ʾ�����˸
        counttime++;
        counttime %= 4200;
        showcursor();
    }

#ifdef DEBUG
    cout << "key: " << (int)keymsg.vkcode << endl;
#endif

    // �������ͼ���
    if (mousemsg.message == WM_LBUTTONDOWN || mousemsg.message == WM_RBUTTONDOWN || mousemsg.message == WM_MOUSEMOVE)
        showMousebuttons();
    else if (keymsg.message == WM_KEYDOWN || keymsg.message == WM_KEYUP)
        showKeyboard();

    // ��ʾ����
    if (inputChanged)
    {
        showwarningbar(TEXT(""));
        showinput();
        showresult();
    }
    EndBatchDraw();
}

bool button(int x, int y, int w, int h, TCHAR text)
{
    BeginBatchDraw();

    // ��������
    settextstyle(40, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);

    // �ж�����Ƿ��ڰ�ť��
    if (inArea(mousemsg.x, mousemsg.y, x, y, w, h))
    {
        setbkmode(TRANSPARENT);
        switch (text)
        {
        case 'C':
            setfillcolor(RGB(255, 90, 96));
            settextcolor(RGB(243, 170, 76));
            solidcircle(x + w / 2, y + h / 2, 42);
            break;
        case '+':
        case '-':
        case TEXT('��'):
        case '/':
        case '=':
            settextcolor(RGB(243, 170, 76));
            setfillcolor(RGB(126, 120, 118));
            solidcircle(x + w / 2, y + h / 2, 45);
            break;
        default:
            settextcolor(RGB(116, 119, 122));
            setfillcolor(RGB(95, 100, 106));
            solidcircle(x + w / 2, y + h / 2, 45);
        }
    }
    else
    {
        setbkmode(TRANSPARENT);
        switch (text)
        {
        case 'C':
            settextcolor(RGB(243, 170, 76));
            setfillcolor(RGB(85, 90, 96));
            solidrectangle(x, y, x + w, y + h);
            break;
        case '+':
        case '-':
        case TEXT('��'):
        case '/':
        case '=':
            settextcolor(RGB(243, 170, 76));
            setfillcolor(RGB(106, 106, 105));
            solidcircle(x + w / 2, y + h / 2, 45);
            break;
        default:
            settextcolor(RGB(116, 119, 122));
            setfillcolor(RGB(85, 90, 96));
            solidrectangle(x, y, x + w, y + h - 1);
        }
    }

    int horzSpace = (w - textwidth(text)) / 2;
    int vertSpace = (h - textheight(text)) / 2;
    outtextxy(x + horzSpace, y + vertSpace, text);

    EndBatchDraw();

    // �ж���갴��
    if (mousemsg.message == WM_LBUTTONDOWN && inArea(mousemsg.x, mousemsg.y, x, y, w, h))
    {
        return true;
    }
    return false;
}

int buttonCursor(int x, int y, int w, int h, LPCTSTR text)
{

    BeginBatchDraw();
    settextstyle(40, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);

    if (inArea(mousemsg.x, mousemsg.y, x, y, w, h))
    {
        setbkmode(TRANSPARENT);
        setfillcolor(RGB(255, 90, 96));
        settextcolor(RGB(243, 170, 76));
        solidcircle(x + w / 2, y + h / 2, 42);
    }
    else
    {
        setbkmode(TRANSPARENT);
        settextcolor(RGB(243, 170, 76));
        setfillcolor(RGB(85, 90, 96));
        solidrectangle(x, y, x + w, y + h);
    }

    int horzSpace = (w - textwidth(text)) / 2;
    int vertSpace = (h - textheight(text)) / 2;
    outtextxy(x + horzSpace, y + vertSpace, text);

    EndBatchDraw();

    // �ж���갴��
    // ���
    if (mousemsg.message == WM_LBUTTONDOWN && inArea(mousemsg.x, mousemsg.y, x, y, w, h))
    {
        return 1;
    }
    // �Ҽ�
    else if (mousemsg.message == WM_RBUTTONDOWN && inArea(mousemsg.x, mousemsg.y, x, y, w, h))
    {
        return 2;
    }

    return 0;
}

void showMousebuttons()
{
    // BeginBatchDraw();

    // ���ñ�־λ
    inputChanged = false;

    // ����ƶ�


    // ��ť��~
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            // ���ְ�ť
            if (j >= 1 && j < 4 && i <= 2)
            {
                if (button(i * 100, 750 - j * 100, 100, 100, 3 * j - 2 + i + '0') && input.length() < 22)
                {
                    input.insert(cursorPosition, 1, 3 * j - 2 + i + '0');
                    inputChanged = true;
                    cursorPosition++;
                }
            }
            else if (j == 0 && i == 0)
            {
                if (button(i * 100, 750 - j * 100, 100, 100, '0') && input.length() < 22)
                {
                    input.insert(cursorPosition, 1, '0');
                    inputChanged = true;
                    cursorPosition++;
                }
            }
            else // ���ܰ�ť
            {
                // С����
                if (j == 0 && i == 1)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '.') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, '.');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }

                // �˸�
                else if (j == 0 && i == 2)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '<'))
                    {
                        if (input.size() && cursorPosition > 0)
                        {
                            if ((cursorPosition > 1) &&
                                ((input[cursorPosition - 2] == TEXT('��') && input[cursorPosition - 1] == '(') || (input[cursorPosition - 2] == ')' && input[cursorPosition - 1] == TEXT('��'))))
                            {
                                input.erase(cursorPosition - 2, 2);
                                cursorPosition -= 2;
                                inputChanged = true;
                            }
                            else if ((input[cursorPosition - 1] == TEXT('��') && input[cursorPosition] == '(') || (input[cursorPosition - 1] == ')' && input[cursorPosition] == TEXT('��')))
                            {
                                input.erase(cursorPosition - 1, 2);
                                cursorPosition--;
                                inputChanged = true;
                            }
                            else
                            {
                                input.erase(cursorPosition - 1, 1);
                                cursorPosition--;
                                inputChanged = true;
                            }
                        }
                    }
                }

                // ���ڽ��
                else if (j == 0 && i == 3)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '=') && input.length() < 22)
                    {
                        if (inputRPN.size())
                        {
                            showwarningbar(result);
                            inputChanged = 0;
                        }
                        else
                        {
                            if (input.size())
                                showwarningbar(TEXT("Invalid expression!"));
                            else
                                showwarningbar(TEXT("No input!"));
                        }
                    }
                }

                // �Ӽ��˳�
                else if (j == 1 && i == 3)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '+') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, '+');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }
                else if (j == 2 && i == 3)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '-') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, '-');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }
                else if (j == 3 && i == 3)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, TEXT('��')) && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, TEXT('��'));
                        cursorPosition++;
                        inputChanged = true;
                    }
                }
                else if (j == 4 && i == 3)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '/') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, '/');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }

                // ����
                else if (j == 4 && i == 2)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, ')') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, ')');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }
                else if (j == 4 && i == 1)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, '(') && input.length() < 22)
                    {
                        input.insert(cursorPosition, 1, '(');
                        cursorPosition++;
                        inputChanged = true;
                    }
                }

                // ����
                else if (j == 4 && i == 0)
                {
                    if (button(i * 100, 750 - j * 100, 100, 100, 'C'))
                    {
                        input = TEXT("");
                        result = TEXT("");
                        inputRPN = {};
                        cursorPosition = 0;
                        Clear();
                        inputChanged = true;
                    }
                }
            }
        }
    }
    // EndBatchDraw();
}

void showKeyboard()
{

    if (keymsg.message == WM_KEYDOWN)
    {
        // ����ʱ���õİ�ť
        if (input.length() >= 22)
        {
            switch (keymsg.vkcode)
            {
            case 'C': // ����
                input = TEXT("");
                result = TEXT("");
                inputRPN = {};
                cursorPosition = 0;
                Clear();
                break;

            case VK_BACK: // �˸�
                if (input.size() && cursorPosition > 0)
                {
                    // ���ź͡������˸�
                    if ((cursorPosition > 1) &&
                        ((input[cursorPosition - 2] == TEXT('��') && input[cursorPosition - 1] == '(') || (input[cursorPosition - 2] == ')' && input[cursorPosition - 1] == TEXT('��'))))
                    {
                        input.erase(cursorPosition - 2, 2);
                        cursorPosition -= 2;
                        inputChanged = true;
                    }
                    else if ((input[cursorPosition - 1] == TEXT('��') && input[cursorPosition] == '(') || (input[cursorPosition - 1] == ')' && input[cursorPosition] == TEXT('��')))
                    {
                        input.erase(cursorPosition - 1, 2);
                        cursorPosition--;
                        inputChanged = true;
                    }
                    // ��ͨ�˸�
                    else
                    {
                        input.erase(cursorPosition - 1, 1);
                        cursorPosition--;
                        inputChanged = true;
                    }
                }
                break;

            // ����ƶ�
            case VK_LEFT:
                if (cursorPosition > 0)
                    cursorPosition--;
                showinput();
                break;
            case VK_RIGHT:
                if (cursorPosition < input.size())
                    cursorPosition++;
                showinput();
                break;
            case VK_UP:
                cursorPosition = 0;
                showinput();
                break;
            case VK_DOWN:
                cursorPosition = input.length();
                showinput();
                break;
            }

            return;
        }

        // ��ʱ���õİ�ť
        switch (keymsg.vkcode)
        {
        case 'C':
            input = TEXT("");
            result = TEXT("");
            inputRPN = {};
            cursorPosition = 0;
            Clear();
            break;

        // ��������
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            input.insert(cursorPosition, 1, keymsg.vkcode);
            inputChanged = true;
            cursorPosition++;
            break;

        case VK_NUMPAD0:
        case VK_NUMPAD1:
        case VK_NUMPAD2:
        case VK_NUMPAD3:
        case VK_NUMPAD4:
        case VK_NUMPAD5:
        case VK_NUMPAD6:
        case VK_NUMPAD7:
        case VK_NUMPAD8:
        case VK_NUMPAD9:
            input.insert(cursorPosition, 1, keymsg.vkcode - 0x60 + '0');
            inputChanged = true;
            cursorPosition++;
            break;

        // ����С����
        // case VK_OEM_PERIOD:
        case VK_DECIMAL:
            input.insert(cursorPosition, 1, '.');
            inputChanged = true;
            cursorPosition++;
            break;

        // �������ţ�С����
        case 229:
            break;

        // ������ţ����ţ��˺ţ��Ӻ�
        case VK_DIVIDE:
            input.insert(cursorPosition, 1, '/');
            inputChanged = true;
            cursorPosition++;
            break;
        case VK_OEM_MINUS:
        case VK_SUBTRACT:
            input.insert(cursorPosition, 1, '-');
            inputChanged = true;
            cursorPosition++;
            break;
        case VK_OEM_PLUS:
        case VK_ADD:
            input.insert(cursorPosition, 1, '+');
            inputChanged = true;
            cursorPosition++;
            break;
        case 'x':
        case VK_MULTIPLY:
            input.insert(cursorPosition, 1, TEXT('��'));
            inputChanged = true;
            cursorPosition++;
            break;

        // ����س�
        case VK_RETURN:
            if (inputRPN.size())
            {
                showwarningbar(result);
                inputChanged = 0;
            }
            else
            {
                if (input.size())
                    showwarningbar(TEXT("Invalid expression!"));
                else
                    showwarningbar(TEXT("No input!"));
            }
            break;

        // �����˸�
        case VK_BACK:
            if (input.size() && cursorPosition > 0)
            {
                if ((cursorPosition > 1) &&
                    ((input[cursorPosition - 2] == TEXT('��') && input[cursorPosition - 1] == '(') || (input[cursorPosition - 2] == ')' && input[cursorPosition - 1] == TEXT('��'))))
                {
                    input.erase(cursorPosition - 2, 2);
                    cursorPosition -= 2;
                    inputChanged = true;
                }
                else if ((input[cursorPosition - 1] == TEXT('��') && input[cursorPosition] == '(') || (input[cursorPosition - 1] == ')' && input[cursorPosition] == TEXT('��')))
                {
                    input.erase(cursorPosition - 1, 2);
                    cursorPosition--;
                    inputChanged = true;
                }
                else
                {
                    input.erase(cursorPosition - 1, 1);
                    cursorPosition--;
                    inputChanged = true;
                }
            }
            break;

        // ����ƶ�
        case VK_LEFT:
            if (cursorPosition > 0)
                cursorPosition--;
            showinput();
            break;
        case VK_RIGHT:
            if (cursorPosition < input.size())
                cursorPosition++;
            showinput();
            break;
        case VK_UP:
            cursorPosition = 0;
            showinput();
            break;
        case VK_DOWN:
            cursorPosition = input.length();
            showinput();
            break;
        case 190:
            break;
        // ���Ϸ�����
        default:
            showwarningbar(TEXT("Invalid input!"));
            inputChanged = 0;
            break;
        }
    }

    // ��������
    else if (keymsg.message == WM_KEYUP)
    {
        if (keymsg.vkcode == 219)
        {
            input.insert(cursorPosition, 1, '(');
            inputChanged = true;
            cursorPosition++;
        }
        else if (keymsg.vkcode == 221)
        {
            input.insert(cursorPosition, 1, ')');
            inputChanged = true;
            cursorPosition++;
        }
        else if (keymsg.vkcode == 190)
        {
            input.insert(cursorPosition, 1, '.');
            inputChanged = true;
            cursorPosition++;
        }
    }
}

void showinput()
{
    BeginBatchDraw();

    // �������
    setfillcolor(RGB(85, 90, 96));
    solidrectangle(0, 0, 800, 50);

    // ��������
    settextcolor(RGB(116, 119, 122));
    setbkmode(OPAQUE);
    settextstyle(40, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);

    // ������input��ʾ
    if (input.size())
        if (cursorPosition == 0)
        {
            outtextxy(12, 10, input.c_str());
        }

        /*      ������ʵ�ֵĵĿ��ƶ����룬���Ǿ���̫�ͣ������ã���ע�͵�
                 else if (input.length() >= 22 && cursorPosition >= 22)
                {
                     tstring front = input.substr(cursorPosition - 22, cursorPosition);
                     outtextxy(10, 10, front.c_str());
                     settextstyle(10, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);
                     outtextxy(5, 50, TEXT("..."));
                 }
        */
        else
        {
            tstring front = input.substr(0, cursorPosition);
            outtextxy(10, 10, front.c_str());
            tstring back = input.substr(cursorPosition, input.length());
            outtextxy(12 + textwidth(front.c_str()), 10, back.c_str());

#ifdef DEBUG
            std::tcout << "front: " << front << endl;
            std::tcout << "back: " << back << endl;
#endif
        }

        /*      ������ʵ�ֵĶ��������룬��������stod���Ȳ����Ͳ����ˣ��Ժ���ʱ�������ģ���

                 tstring thislineinput = input;
                // tstring stillnotinput = input;
                // inputlines = 0;
                // while (stillnotinput.size() && stillnotinput.length() > 22 && inputlines <= 2)
                //{
                //     thislineinput = stillnotinput.substr(0, 22);
                //     stillnotinput = stillnotinput.substr(22, input.length());
                //     if (cursorPosition / 22 == inputlines)
                //     {
                //         if (cursorPosition % 22 == 0)
                //         {
                //             outtextxy(12, textheight('0') * inputlines + 10, thislineinput.c_str());
                //         }
                //         else
                //         {
                //             tstring front = thislineinput.substr(0, cursorPosition);
                //             outtextxy(10, textheight('0') * inputlines + 10, front.c_str());
                //             tstring back = thislineinput.substr(cursorPosition, thislineinput.length());
                //             outtextxy(12 + textwidth(front.c_str()), textheight('0') * inputlines + 10, back.c_str());
                //         }
                //     }
                //     else
                //     {
                //         outtextxy(10, textheight('0') * inputlines + 10, thislineinput.c_str());
                //     }

                //    inputlines++;

                //}

                // thislineinput = stillnotinput;
                // if (cursorPosition / 22 == inputlines)
                //{
                //     if (cursorPosition % 22 == 0)
                //     {
                //         outtextxy(12, textheight('0') * inputlines + 10, thislineinput.c_str());
                //     }
                //     else
                //     {
                //         tstring front = thislineinput.substr(0, cursorPosition % 22);
                //         outtextxy(10, textheight('0') * inputlines + 10, front.c_str());
                //         tstring back = thislineinput.substr(cursorPosition % 22, thislineinput.length());
                //         outtextxy(12 + textwidth(front.c_str()), textheight('0') * inputlines + 10, back.c_str());
                //     }
                // }
                // else
                //{
                //     outtextxy(10, textheight('0') * inputlines + 10, thislineinput.c_str());
                // }
         */

#ifdef DEBUG
    std::tcout << "input: " << input << endl;
#endif

    EndBatchDraw();
}

void showcursor()
{
    // ��˸bling
    if (counttime < 2200)
    {
        BeginBatchDraw();
        setfillcolor(RGB(205, 200, 206));
        solidrectangle(10 + cursorPosition * textwidth(TEXT('_')), 12, 12 + (cursorPosition)*textwidth(TEXT('_')), 8 + textheight(TEXT('_')));
        EndBatchDraw();
    }
    else
    {
        setfillcolor(RGB(106, 100, 105));
        solidrectangle(10 + cursorPosition * textwidth(TEXT('_')), 12, 12 + (cursorPosition)*textwidth(TEXT('_')), 8 + textheight(TEXT('_')));
    }
#ifdef DEBUG
    // std::tcout << "cursorPosition: " << cursorPosition << endl;
#endif
}

void showresult()
{

    BeginBatchDraw();

    // ���ý����
    result = TEXT("");

    // �����׺���ʽ
    inputRPN = RPN(input);
    if (inputRPN.size() && inputRPN[0] != TEXT("need backspace"))
    {

        // ���ü����
        setfillcolor(RGB(85, 90, 96));
        solidrectangle(0, 100, 800, 200);
        settextcolor(RGB(243, 170, 76));
        
        // ��������
        setbkmode(OPAQUE);
        settextstyle(40, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);
        
        
        result = calcRPN(inputRPN);

        bool isFloat = false; // �ж���С����
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
            if (result.back() == '.') // ����С����ȥ��С����
                result.erase(result.end() - 1);
        }

        // ������
        tstring thislineresult = result;
        tstring stillnotresult = result;
        int resultlines = 0;
        while (stillnotresult.size() && stillnotresult.length() > 22 && resultlines <= 2)
        {
            thislineresult = stillnotresult.substr(0, 22);
            stillnotresult = stillnotresult.substr(22, result.length());
            outtextxy(10, textheight('0') * resultlines + 100, thislineresult.c_str());

            resultlines++;
        }
        if (resultlines > 2)
        {
            showwarningbar(TEXT("Result Too Long"));
        }
        outtextxy(10, textheight('0') * resultlines + 100, (LPCTSTR)stillnotresult.c_str());

#ifdef DEBUG
        std::tcout << "result: " << result << endl;
#endif
    }
    // ���Ϸ�����(��Ҫ�˸�)
    else if (inputRPN.size() && inputRPN[0] == TEXT("need backspace"))
    {
        showwarningbar(TEXT("Invalid Input!"));
    }

    // ����̫��
    if (input.length() >= 22)
    {
        showwarningbar(TEXT("Too Long!"));
        return;
    }

    EndBatchDraw();

#ifdef DEBUG
    std::cout << "inputRPN: ";
    for (auto i : inputRPN)
        std::tcout << i << ' ';
    std::cout << endl;
#endif
}

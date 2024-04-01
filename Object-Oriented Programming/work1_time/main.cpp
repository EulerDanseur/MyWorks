#include "time.h"

int main() {
    // 测试Time类
    cout << "Testing Time Class..." << endl;

    // 测试构造函数
    Time t1(0, 30, 45);  // 使用时分秒构造函数
    Time t2(45678);       // 使用总秒数构造函数
    Time t3(t1);          // 使用拷贝构造函数

    // 测试显示函数
    cout << "Time t1: "; t1.display();
    cout << "Time t2: "; t2.display();
    cout << "Time t3: "; t3.display();

    // 测试设置函数
    t1.set(0, 20, 10);
    cout << "Time t1 after set: "; t1.display();
 
    // 测试自增和自减运算符
    cout << "Time t1 before increment: "; t1.display();
    ++t1;
    cout << "Time t1 after increment: "; t1.display();
    --t1;
    cout << "Time t1 after decrement: "; t1.display();

    // 测试相等和小于运算符
    cout << "t1 == t2? " << (t1 == t2) << endl;
    cout << "t1 < t2? " << (t1 < t2) << endl;

    // 测试加减运算符
    Time t4 = t1 + 3600; // 加一小时
    Time t5 = t1 - 1800; // 减半小时
    cout << "Time t4 (t1 + 1 hour): "; t4.display();
    cout << "Time t5 (t1 - 30 minutes): "; t5.display();

    // 测试减法运算符
    int diff = t1 - t2;
    cout << "Difference between t1 and t2 (in seconds): " << diff << endl;

    // 测试赋值运算符
    Time t6 = t1;
    cout << "Time t6 (assigned from t1): "; t6.display();

    // 测试类型转换运算符
    int totalSeconds = static_cast<int>(t1);
    cout << "Total seconds of t1: " << totalSeconds << endl;

    // 测试ExtTime类
    cout << "\nTesting ExtTime Class..." << endl;

    // 测试构造函数
    ExtTime et1(10, 30, 45, 5, 30); // 使用时分秒和时区偏移构造函数
    ExtTime et2(et1);               // 使用拷贝构造函数
    ExtTime et3(et1 + 3600);              // 使用总秒数构造函数
    // 测试显示函数
    cout << "ExtTime et1: "; et1.display();
    cout << "ExtTime et2: "; et2.display();
    cout << "ExtTime et3: "; et3.display();

    // 测试相等和小于运算符
    cout << "et1 == et2? " << (et1 == et2) << endl;
    cout << "et1 < et2? " << (et1 < et2) << endl;
    cout << "et1 < et3? " << (et1 < et3) << endl;

    // 测试加减运算符
    ExtTime et4 = et1 + 3600; // 加一小时   
    ExtTime et5 = et1 - 1800; // 减半小时
    cout << "ExtTime et4 (et1 + 1 hour): "; et4.display();
    cout << "ExtTime et5 (et1 - 30 minutes): "; et5.display();

    // 测试赋值运算符
    ExtTime et6 = et1;
    cout << "ExtTime et6 (assigned from et1): "; et6.display();

    // 测试减法运算符
    int diffExt = et1 - et2;
    cout << "Difference between et1 and et2 (in seconds): " << diffExt << endl;

    // 测试虚函数的动态绑定
    Time* ptr1 = &t1;
    Time* ptr2 = &et1; // 将ExtTime对象的地址赋给Time指针
    ptr1->display(); // 调用Time::display()
    ptr2->display(); // 调用ExtTime::display() (动态绑定)

    return 0;
}

/* int main() {
    int h, m, s, extHour, extminute;
    int choice;

    cout << "hour for Time t1: ";
    cin >> h;
    cout << "minute for Time t1: ";
    cin >> m;
    cout << "second for Time t1: ";
    cin >> s;
    cout << "timezone extension for ExtTime t2: ";
    cin >> extHour;
    cout << "timezone minute for ExtTime t2: ";
    cin >> extminute;

    Time t1(h, m, s);
    ExtTime t2(h, m, s, extHour,extminute);

    Time *ptr;
    ptr = &t2; // Pointer of base class pointing to derived class object

    do {
        cout << "\nSelect an option:\n";
        cout << "1. Display Time t1\n";
        cout << "2. Display ExtTime t2\n";
        cout << "3. Test equal function\n";
        cout << "4. Test less_than function\n";
        cout << "5. Test operator==\n";
        cout << "6. Test operator<\n";
        cout << "7. Calculate difference between t2 and t1\n";
        cout << "8. Add seconds to t1\n";
        cout << "9. Subtract seconds from t1\n";
        cout << "10. Increment t2\n";
        cout << "11. Decrement t2\n";
        cout << "12. Test virtual function display through base class pointer\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Time t1: ";
                t1.display();
                break;
            case 2:
                cout << "ExtTime t2: ";
                t2.display();
                break;
            case 3:
                if (t1.equal(t2))
                    cout << "t1 is equal to t2\n";
                else
                    cout << "t1 is not equal to t2\n";
                break;
            case 4:
                if (t1.less_than(t2))
                    cout << "t1 is less than t2\n";
                else
                    cout << "t1 is not less than t2\n";
                break;
            case 5:
                if (t1 == t2)
                    cout << "t1 is equal to t2\n";
                else
                    cout << "t1 is not equal to t2\n";
                break;
            case 6:
                if (t1 < t2)
                    cout << "t1 is less than t2\n";
                else
                    cout << "t1 is not less than t2\n";
                break;
            case 7:
                cout << "Difference between t2 and t1: " << (t2 - t1) << " seconds\n";
                break;
            case 8:
                int n;
                cout << "Enter seconds to add to t1: ";
                cin >> n;
                t1 = t1 + n;
                cout << "New time for t1 after adding " << n << " seconds: ";
                t1.display();
                break;
            case 9:
                cout << "Enter seconds to subtract from t1: ";
                cin >> n;
                t1 = t1 - n;
                cout << "New time for t1 after subtracting " << n << " seconds: ";
                t1.display();
                break;
            case 10:
                cout << "Incrementing t2...\n";
                t2.increment();
                cout << "New time for t2 after incrementing: ";
                t2.display();
                break;
            case 11:
                cout << "Decrementing t2...\n";
                --t2;
                cout << "New time for t2 after decrementing: ";
                t2.display();
                break;
            case 12:
                cout << "Testing virtual function display through base class pointer:\n";
                ptr->display();
                break;
            case 13:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 13.\n";
                break;
        }
    } while (choice != 13);

    return 0;
} */


/*
int main()
{
    int h, m, s;
    cout << "Enter the hour, minute, and second for Time t1 (separated by spaces): ";
    cin >> h >> m >> s;
    Time t1(h, m, s);

    int totalSeconds;
    cout << "Enter the total seconds for Time t2: ";
    cin >> totalSeconds;
    Time t2(totalSeconds);

    char choice;
    do
    {
        cout << "\nSelect an operation to perform:\n";
        cout << "1. Display t1 and t2\n";
        cout << "2. Check if t1 and t2 are equal\n";
        cout << "3. Check if t1 is less than t2\n";
        cout << "4. Increment t1\n";
        cout << "5. Decrement t2\n";
        cout << "6. Add seconds to t1\n";
        cout << "7. Subtract seconds from t2\n";
        cout << "8. Calculate difference between t1 and t2 in seconds\n";
        cout << "9. Convert t1 or t2 to integer (seconds)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice (0-9): ";
        cin >> choice;
        system("cls");
        cout << "Time t1: ";
        t1.display();
        cout << "Time t2: ";
        t2.display();

        switch (choice)
        {
        case '1':
            cout << "Time t1: ";
            t1.display();
            cout << "Time t2: ";
            t2.display();
            break;
        case '2':
            if (t1 == t2)
                cout << "t1 and t2 are equal.\n";
            else
                cout << "t1 and t2 are not equal.\n";
            break;
        case '3':
            if (t1 < t2)
                cout << "t1 is less than t2.\n";
            else
                cout << "t1 is not less than t2.\n";
            break;
        case '4':
            cout << "Incrementing t1:\n";
            t1.increment();
            t1.display();
            break;
        case '5':
            cout << "Decrementing t2:\n";
            --t2;
            t2.display();
            break;
        case '6':
            int secondsToAdd;
            cout << "Enter the number of seconds to add to t1: ";
            cin >> secondsToAdd;
            t1 = t1 + secondsToAdd;
            cout << "Updated t1: ";
            t1.display();
            break;
        case '7':
            int secondsToSubtract;
            cout << "Enter the number of seconds to subtract from t2: ";
            cin >> secondsToSubtract;
            t2 = t2 - secondsToSubtract;
            cout << "Updated t2: ";
            t2.display();
            break;
        case '8':
            cout << "Difference between t1 and t2 in seconds: " << (t1 - t2) << endl;
            break;
        case '9':
            char conversionChoice;
            cout << "Convert which Time object to integer? (1 for t1, 2 for t2): ";
            cin >> conversionChoice;
            if (conversionChoice == '1')
            {
                int converted_t1 = t1;
                cout << "t1 in seconds: " << converted_t1 << endl;
            }
            else if (conversionChoice == '2')
            {
                int converted_t2 = t2;
                cout << "t2 in seconds: " << converted_t2 << endl;
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            break;
        case '0':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 0 and 9.\n";
        }
    } while (choice != '0');

    return 0;
} */
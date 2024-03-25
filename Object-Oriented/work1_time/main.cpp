#include "time.h"

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
}
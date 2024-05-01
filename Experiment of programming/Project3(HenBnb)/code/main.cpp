#include "surface.h"


int main()
{
    system("color 7F");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7 << 4));
    showMainMenu();
    return 0;
}
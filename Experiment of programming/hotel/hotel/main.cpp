#include "hotel.h"

int main() {
    BookingSystem system;
    int choice;

    while (true) {
        std::cout << "1. 用户登录\n2. 用户注册\n3. 房东登录\n4. 房东注册\n5. 退出\n选择操作: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            system.userLogin();
            break;
        case 2:
            system.userRegister();
            break;
        case 3:
            system.landlordLogin();
            break;
        case 4:
            system.landlordRegister();
            break;
        case 5:
            return 0;
        default:
            std::cout << "无效操作\n";
        }
    }

    return 0;
}

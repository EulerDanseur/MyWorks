#include "hotel.h"

int main() {
    BookingSystem system;
    int choice;

    while (true) {
        std::cout << "1. �û���¼\n2. �û�ע��\n3. ������¼\n4. ����ע��\n5. �˳�\nѡ�����: ";
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
            std::cout << "��Ч����\n";
        }
    }

    return 0;
}

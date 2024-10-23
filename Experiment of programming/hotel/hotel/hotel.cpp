#include "hotel.h"

// �û���¼ʵ��
bool User::login(const std::vector<User>& users, const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

// �����û���Ϣ
void User::loadUsers(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string username, password;
        while (file >> username >> password) {
            users.emplace_back(username, password);
        }
        file.close();
    }
}

// �����û���Ϣ
void User::saveUsers(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.username << ' ' << user.password << '\n';
        }
        file.close();
    }
}

// ���ط�����Ϣ
void Room::loadRooms(std::vector<Room>& rooms, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int roomNumber;
        std::string info;
        bool isBooked;
        while (file >> roomNumber >> isBooked) {
            file.ignore();
            std::getline(file, info);
            rooms.emplace_back(roomNumber, info);
            rooms.back().isBooked = isBooked;
        }
        file.close();
    }
}

// ���淿����Ϣ
void Room::saveRooms(const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& room : rooms) {
            file << room.roomNumber << ' ' << room.isBooked << ' ' << room.info << '\n';
        }
        file.close();
    }
}

// Ԥ��ϵͳ���캯��
BookingSystem::BookingSystem() {
    // ��ʼ���û��ͷ���
    User::loadUsers(users, "users.txt");
    User::loadUsers(landlords, "landlords.txt");

    // ���ط�����Ϣ
    Room::loadRooms(rooms, "rooms.txt");
}

// �û���¼����
void BookingSystem::userLogin() {
    std::string username, password;
    std::cout << "�������û���: ";
    std::cin >> username;
    std::cout << "����������: ";
    std::cin >> password;

    if (User::login(users, username, password)) {
        std::cout << "��¼�ɹ���\n";
        int choice;
        std::cout << "1. ��ѯ������Ϣ\n2. Ԥ������\n3. ȡ��Ԥ��\n4. ��ѯ����\nѡ�����: ";
        std::cin >> choice;
        switch (choice) {
        case 1: queryRoomInfo(); break;
        case 2: bookRoom(); break;
        case 3: cancelBooking(); break;
        case 4: queryOrders(); break;
        default: std::cout << "��Ч����\n";
        }
    }
    else {
        std::cout << "�û������������\n";
    }
}

// �û�ע�Ṧ��
void BookingSystem::userRegister() {
    std::string username, password;
    std::cout << "�������µ��û���: ";
    std::cin >> username;
    std::cout << "�������µ�����: ";
    std::cin >> password;

    users.emplace_back(username, password);
    User::saveUsers(users, "users.txt");
    std::cout << "ע��ɹ���\n";
}

// ������¼����
void BookingSystem::landlordLogin() {
    std::string username, password;
    std::cout << "�������û���: ";
    std::cin >> username;
    std::cout << "����������: ";
    std::cin >> password;

    if (User::login(landlords, username, password)) {
        std::cout << "��¼�ɹ���\n";
        int choice;
        std::cout << "1. ��ѯ������Ϣ\n2. �޸ķ�����Ϣ\nѡ�����: ";
        std::cin >> choice;
        switch (choice) {
        case 1: queryRoomInfo(); break;
        case 2: modifyRoomInfo(); break;
        default: std::cout << "��Ч����\n";
        }
    }
    else {
        std::cout << "�û������������\n";
    }
}

// ����ע�Ṧ��
void BookingSystem::landlordRegister() {
    std::string username, password;
    std::cout << "�������µ��û���: ";
    std::cin >> username;
    std::cout << "�������µ�����: ";
    std::cin >> password;

    landlords.emplace_back(username, password);
    User::saveUsers(landlords, "landlords.txt");
    std::cout << "ע��ɹ���\n";
}

// ��ѯ������Ϣ
void BookingSystem::queryRoomInfo() {
    for (const auto& room : rooms) {
        std::cout << "���� " << room.roomNumber << " ��Ϣ: " << room.info << " Ԥ��״̬: " << (room.isBooked ? "��Ԥ��" : "δԤ��") << '\n';
    }
}

// �޸ķ�����Ϣ
void BookingSystem::modifyRoomInfo() {
    int roomNumber;
    std::cout << "�����뷿���: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end()) {
        std::cout << "�������µķ�����Ϣ: ";
        std::cin.ignore();
        std::getline(std::cin, it->info);
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "������Ϣ�Ѹ���\n";
    }
    else {
        std::cout << "�������Ч\n";
    }
}

// Ԥ������
void BookingSystem::bookRoom() {
    int roomNumber;
    std::cout << "������ҪԤ���ķ����: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && !it->isBooked) {
        it->isBooked = true;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "���� " << roomNumber << " Ԥ���ɹ�\n";
    }
    else {
        std::cout << "�������Ч���ѱ�Ԥ��\n";
    }
}

// ȡ��Ԥ��
void BookingSystem::cancelBooking() {
    int roomNumber;
    std::cout << "������Ҫȡ��Ԥ���ķ����: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && it->isBooked) {
        it->isBooked = false;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "���� " << roomNumber << " Ԥ��ȡ���ɹ�\n";
    }
    else {
        std::cout << "�������Ч��δ��Ԥ��\n";
    }
}

// ��ѯ����
void BookingSystem::queryOrders() {
    std::cout << "��ѯ�ҵĶ���������δʵ��\n";
}

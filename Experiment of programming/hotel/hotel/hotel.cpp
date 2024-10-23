#include "hotel.h"

// 用户登录实现
bool User::login(const std::vector<User>& users, const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

// 加载用户信息
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

// 保存用户信息
void User::saveUsers(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.username << ' ' << user.password << '\n';
        }
        file.close();
    }
}

// 加载房间信息
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

// 保存房间信息
void Room::saveRooms(const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& room : rooms) {
            file << room.roomNumber << ' ' << room.isBooked << ' ' << room.info << '\n';
        }
        file.close();
    }
}

// 预定系统构造函数
BookingSystem::BookingSystem() {
    // 初始化用户和房东
    User::loadUsers(users, "users.txt");
    User::loadUsers(landlords, "landlords.txt");

    // 加载房间信息
    Room::loadRooms(rooms, "rooms.txt");
}

// 用户登录功能
void BookingSystem::userLogin() {
    std::string username, password;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入密码: ";
    std::cin >> password;

    if (User::login(users, username, password)) {
        std::cout << "登录成功！\n";
        int choice;
        std::cout << "1. 查询房间信息\n2. 预定房间\n3. 取消预定\n4. 查询订单\n选择操作: ";
        std::cin >> choice;
        switch (choice) {
        case 1: queryRoomInfo(); break;
        case 2: bookRoom(); break;
        case 3: cancelBooking(); break;
        case 4: queryOrders(); break;
        default: std::cout << "无效操作\n";
        }
    }
    else {
        std::cout << "用户名或密码错误\n";
    }
}

// 用户注册功能
void BookingSystem::userRegister() {
    std::string username, password;
    std::cout << "请输入新的用户名: ";
    std::cin >> username;
    std::cout << "请输入新的密码: ";
    std::cin >> password;

    users.emplace_back(username, password);
    User::saveUsers(users, "users.txt");
    std::cout << "注册成功！\n";
}

// 房东登录功能
void BookingSystem::landlordLogin() {
    std::string username, password;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入密码: ";
    std::cin >> password;

    if (User::login(landlords, username, password)) {
        std::cout << "登录成功！\n";
        int choice;
        std::cout << "1. 查询房间信息\n2. 修改房间信息\n选择操作: ";
        std::cin >> choice;
        switch (choice) {
        case 1: queryRoomInfo(); break;
        case 2: modifyRoomInfo(); break;
        default: std::cout << "无效操作\n";
        }
    }
    else {
        std::cout << "用户名或密码错误\n";
    }
}

// 房东注册功能
void BookingSystem::landlordRegister() {
    std::string username, password;
    std::cout << "请输入新的用户名: ";
    std::cin >> username;
    std::cout << "请输入新的密码: ";
    std::cin >> password;

    landlords.emplace_back(username, password);
    User::saveUsers(landlords, "landlords.txt");
    std::cout << "注册成功！\n";
}

// 查询房间信息
void BookingSystem::queryRoomInfo() {
    for (const auto& room : rooms) {
        std::cout << "房间 " << room.roomNumber << " 信息: " << room.info << " 预定状态: " << (room.isBooked ? "已预定" : "未预定") << '\n';
    }
}

// 修改房间信息
void BookingSystem::modifyRoomInfo() {
    int roomNumber;
    std::cout << "请输入房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end()) {
        std::cout << "请输入新的房间信息: ";
        std::cin.ignore();
        std::getline(std::cin, it->info);
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间信息已更新\n";
    }
    else {
        std::cout << "房间号无效\n";
    }
}

// 预定房间
void BookingSystem::bookRoom() {
    int roomNumber;
    std::cout << "请输入要预定的房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && !it->isBooked) {
        it->isBooked = true;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间 " << roomNumber << " 预定成功\n";
    }
    else {
        std::cout << "房间号无效或已被预定\n";
    }
}

// 取消预定
void BookingSystem::cancelBooking() {
    int roomNumber;
    std::cout << "请输入要取消预定的房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && it->isBooked) {
        it->isBooked = false;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间 " << roomNumber << " 预定取消成功\n";
    }
    else {
        std::cout << "房间号无效或未被预定\n";
    }
}

// 查询订单
void BookingSystem::queryOrders() {
    std::cout << "查询我的订单功能尚未实现\n";
}

## 代码报告

### 项目概述

该项目是一个简单的民宿预定系统，主要功能包括用户注册和登录、房东注册和登录、查询房间信息、预定和取消预定等。用户信息和房间信息存储在文件中，以便在不同的运行期间保持一致性。整个系统使用C++面向对象的编程思想进行设计和实现。

### 文件结构

- `hotel.h`：声明类及其成员函数。
- `hotel.cpp`：实现类的成员函数。
- `main.cpp`：程序入口，实现主菜单及用户交互。

### 类及成员函数

#### `User`类

##### 属性
- `std::string username`：用户名。
- `std::string password`：密码。

##### 方法
- `User()`：默认构造函数。
- `User(const std::string &user, const std::string &pass)`：带参构造函数。
- `static bool login(const std::vector<User> &users, const std::string &username, const std::string &password)`：用户登录函数。
- `static void loadUsers(std::vector<User> &users, const std::string &filename)`：从文件加载用户信息。
- `static void saveUsers(const std::vector<User> &users, const std::string &filename)`：将用户信息保存到文件。

#### `Room`类

##### 属性
- `int roomNumber`：房间号。
- `std::string info`：房间信息。
- `bool isBooked`：预定状态。

##### 方法
- `Room()`：默认构造函数。
- `Room(int num, const std::string &info)`：带参构造函数。
- `static void loadRooms(std::vector<Room> &rooms, const std::string &filename)`：从文件加载房间信息。
- `static void saveRooms(const std::vector<Room> &rooms, const std::string &filename)`：将房间信息保存到文件。

#### `BookingSystem`类

##### 属性
- `std::vector<User> users`：用户列表。
- `std::vector<User> landlords`：房东列表。
- `std::vector<Room> rooms`：房间列表。

##### 方法
- `BookingSystem()`：构造函数，初始化系统。
- `void userLogin()`：用户登录功能。
- `void userRegister()`：用户注册功能。
- `void landlordLogin()`：房东登录功能。
- `void landlordRegister()`：房东注册功能。
- `void queryRoomInfo()`：查询房间信息。
- `void modifyRoomInfo()`：修改房间信息。
- `void bookRoom()`：预定房间。
- `void cancelBooking()`：取消预定。
- `void queryOrders()`：查询订单（尚未实现）。

### 功能实现

#### 用户注册

用户可以通过选择菜单中的“用户注册”选项进行注册，输入用户名和密码后，系统会将新用户的信息保存到`users.txt`文件中。相应的代码如下：

```cpp
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
```

#### 用户登录

用户可以通过选择菜单中的“用户登录”选项进行登录，输入用户名和密码后，系统会验证用户信息。登录成功后，用户可以选择查询房间信息、预定房间、取消预定或查询订单。相应的代码如下：

```cpp
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
    } else {
        std::cout << "用户名或密码错误\n";
    }
}
```

#### 房东注册与登录

房东的注册和登录与用户类似，通过选择菜单中的“房东注册”和“房东登录”选项进行相应操作。房东登录后，可以选择查询房间信息或修改房间信息。

```cpp
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
    } else {
        std::cout << "用户名或密码错误\n";
    }
}
```

#### 查询房间信息

无论是用户还是房东，都可以查询房间信息。该功能将显示所有房间的详细信息，包括房间号、房间描述和预定状态。

```cpp
void BookingSystem::queryRoomInfo() {
    for (const auto &room : rooms) {
        std::cout << "房间 " << room.roomNumber << " 信息: " << room.info << " 预定状态: " << (room.isBooked ? "已预定" : "未预定") << '\n';
    }
}
```

#### 修改房间信息

房东可以通过输入房间号来修改相应房间的信息，新的房间信息将被保存到文件中。

```cpp
void BookingSystem::modifyRoomInfo() {
    int roomNumber;
    std::cout << "请输入房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room &room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end()) {
        std::cout << "请输入新的房间信息: ";
        std::cin.ignore();
        std::getline(std::cin, it->info);
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间信息已更新\n";
    } else {
        std::cout << "房间号无效\n";
    }
}
```

#### 预定和取消预定

用户可以通过输入房间号来预定或取消预定相应房间。预定状态将被保存到文件中。

```cpp
void BookingSystem::bookRoom() {
    int roomNumber;
    std::cout << "请输入要预定的房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room &room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && !it->isBooked) {
        it->isBooked = true;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间 " << roomNumber << " 预定成功\n";
    } else {
        std::cout << "房间号无效或已被预定\n";
    }
}

void BookingSystem::cancelBooking() {
    int roomNumber;
    std::cout << "请输入要取消预定的房间号: ";
    std::cin >> roomNumber;
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room &room) { return room.roomNumber == roomNumber; });
    if (it != rooms.end() && it->isBooked) {
        it->isBooked = false;
        Room::saveRooms(rooms, "rooms.txt");
        std::cout << "房间 " << roomNumber << " 预定取消成功\n";
    } else {
        std::cout << "房间号无效或未被预定\n";
    }
}
```
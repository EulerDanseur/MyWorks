#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class User {
public:
    std::string username;
    std::string password;

    User() = default;
    User(const std::string& user, const std::string& pass) : username(user), password(pass) {}

    static bool login(const std::vector<User>& users, const std::string& username, const std::string& password);
    static void loadUsers(std::vector<User>& users, const std::string& filename);
    static void saveUsers(const std::vector<User>& users, const std::string& filename);
};

class Room {
public:
    int roomNumber;
    std::string info;
    bool isBooked;

    Room() = default;
    Room(int num, const std::string& info) : roomNumber(num), info(info), isBooked(false) {}

    static void loadRooms(std::vector<Room>& rooms, const std::string& filename);
    static void saveRooms(const std::vector<Room>& rooms, const std::string& filename);
};

class BookingSystem {
private:
    std::vector<User> users;
    std::vector<User> landlords;
    std::vector<Room> rooms;

public:
    BookingSystem();

    void userLogin();
    void userRegister();
    void landlordLogin();
    void landlordRegister();
    void queryRoomInfo();
    void modifyRoomInfo();
    void bookRoom();
    void cancelBooking();
    void queryOrders();
};

#endif // HOTEL_H

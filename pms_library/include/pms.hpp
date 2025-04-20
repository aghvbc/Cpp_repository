// property management system
#pragma once
#include <string>
#include <cstdint>

class Guest {
private: //модификатор доступа
    uint64_t id;
    std::string firstName; //свойство/поле
    std::string secondName;
    std::string phoneNumber;
    std::string email;
    uint64_t passNumber;
    std::string date;
    uint loyaltyPoints;
public:
    Guest(uint64_t id, std::string fName, std::string sName, std::string email, std::string PhoneNumber, uint64_t passNumber, std::string date, uint loyaltyPoints);
    //сеттеры
    void showInfo();
    //геттеры
    uint64_t getId();
    std::string getFirstName();
    std::string getSecondName();
    std::string getPhoneNumber();
    std::string getEmail();
    uint64_t getPassNumber();
    std::string getDate();
    uint64_t getLoyaltyPoints();
    
};
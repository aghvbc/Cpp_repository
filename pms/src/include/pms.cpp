#include <iostream>
#include "pms.hpp"
#include <cstdint>


Guest::Guest(uint64_t id, std::string fName, std::string sName, std::string email, std::string phoneNumber, uint64_t passNumber, std::string date, uint loyaltyPoints)
{   
    this->id = id;
    this->firstName = fName;
    this->secondName = sName;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->passNumber = passNumber; 
    this->date = date;
    this->loyaltyPoints = loyaltyPoints; 
};



void Guest::showInfo(){
    std::cout << "Номер паспотра: " << this->passNumber << std::endl;
    std::cout << "Имя: " << this->firstName << std::endl;
    std::cout << "Фамилия: " << this->secondName << std::endl;
}

// Реализация геттеров
uint64_t Guest::getId() {
    return this->id;
}

std::string Guest::getFirstName() {
    return this->firstName;
}

std::string Guest::getSecondName() {
    return this->secondName;
}

std::string Guest::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Guest::getEmail(){
    return this->email;
}

uint64_t Guest::getPassNumber() {
    return this->passNumber;
}


std::string Guest::getDate() {
    return this->date;
}


uint64_t Guest::getLoyaltyPoints() {
    return this->loyaltyPoints;
}


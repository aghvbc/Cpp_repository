#include <iostream>
#include <cstdint>
#include <vector>
#include "Guest.hpp"



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


// по идее реализация сеттеров
void Guest::showInfo(){
    std::cout << "Номер паспотра: " << this->passNumber << std::endl;
    std::cout << "Имя: " << this->firstName << std::endl;
    std::cout << "Фамилия: " << this->secondName << std::endl;
}

void Guest::addVisit(/*DateInterval from DateTime*/){
    
};

void Guest::addLoyaltyPoints(int points){
    loyaltyPoints += points;
};


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
};

GuestRegistry::GuestRegistry(const std::vector<Guest>& guests):guests(guests) {};

Guest* GuestRegistry::getGuest(int id){
    for (auto& guest : guests){
        if (guest.getId() == id){
            return &guest;
        };
    };
    return nullptr;
};

int GuestRegistry::registerGuest(const Guest& guest){
    guests.push_back(guest);
    return 0;
};
#include <iostream>
#include <fstream> //для считывания
#include <vector>
#include <sstream>
#include "include/pms.hpp"

std::vector<Guest> loadGuests(const std::string& filename) {
    std::vector<Guest> guests; //массив гостей
    std::ifstream file(filename); //создаём файловый поток на чтение
    std::string line; //создаём строку для построчного считавания из файла

    // Пропускаем заголовок
    std::getline(file,line);

    while (std::getline(file,line)){
        std::stringstream ss(line);
        char delim;
        uint64_t id;
        std::string firstName;
        std::string secondName;
        std::string phone;
        std::string email;
        uint64_t passport;
        std::string date;
        uint loyaltyPoints;


        ss >> id >> delim;
        std::getline(ss, firstName, ',');
        std::getline(ss, secondName, ',');
        std::getline(ss, email, ',');
        std::getline(ss, phone, ',');
        ss >> passport >> delim;
        std::getline(ss, date, ',');

        ss >>  loyaltyPoints;
        Guest g(
            id,
            firstName,
            secondName, 
            email, 
            phone, 
            passport, 
            date,
            loyaltyPoints
        );
        guests.push_back(g);

    }
}

int main(){
    auto guests = loadGuests("guests.txt");
    if (!guests.empty()) {
        // //1. классический вариант с индексами
        // for (int i = 0; i <guests.size(); i++){
        //     guests[i].showInfo();
        // };

        //2. Вариант с элементами (через итератор)
        for (auto guest : guests) {
            guest.showInfo();
        }

        // //3. через итератор
        // for (auto iter = guests.begin(); iter != guests.end(); iter++){
        //     iter->showInfo();
        // }
    }
    else {
        std::cerr << "Файл не загрузился" << std::endl;
    }
    
    for (auto guest: guests) {
        guest.showInfo();
    };


    return 0;
}
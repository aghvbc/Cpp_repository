#include <iostream>
#include <fstream> //для считывания
#include <vector>
#include <sstream>
#include "../include/Guest.hpp"

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

    };
    return guests;
}

int main(){
    auto guests = loadGuests("guests.txt");

    if (!guests.empty()) {
        for (auto guest : guests) {
            guest.showInfo();
        }
    }
    else {
        std::cerr << "Файл не загрузился" << std::endl;
    }

    GuestRegistry registry(guests);
    // auto* guest1 = registry.getGuest(8);
    // if (guest1) {
    //     std::cout << "Найден гость с ID=8:\n";
    //     guest1->showInfo();
    // } else {
    //     std::cout << "Гость с ID=8 не найден.\n";
    // }

    // 2. Добавляем нового гостя
    Guest newGuest(
        11, // id
        "Тест", // firstName
        "Пользователь", // secondName
        "test@example.com", // email
        "+79998887766", // phone
        1231231231, // паспорт
        "01.01.2000", // дата
        10 // баллы
    );
    
    registry.registerGuest(newGuest);

    // 3. Получаем гостя по id и выводим инфу
    Guest* guestPtr = registry.getGuest(11);
    if (guestPtr != nullptr) {
        std::cout << "\nИнформация о добавленном госте:\n";
        guestPtr->showInfo();
    } else {
        std::cout << "Гость с таким ID не найден." << std::endl;
    }
    return 0;
}
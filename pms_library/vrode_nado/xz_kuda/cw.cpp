#include<iostream>
#include <vector>

class TimeRange {
public:
private:
    int start_sec;
    int end_sec;
}; 

// class MiniBar {
// public:
//     int chocko_count;
//     double chocko_price;
// private:

// };

class BookingableEntity {
public:
    BookingableEntity(double val): id(rand() % 100), tariff(val) {
        std::cout << "Конструктор BookingableEntity" << std::endl;
    }

    int getId() { return id; }
private:
    int id; // Уникальный индификатор
protected:
double tariff;
std::vector<TimeRange> booking;

};

// class TennisCourte {
// public:
    
// private:
//     int number;
//     int id;
//     double tariff; 
// };

class ConferenceHall : public BookingableEntity { // public - модифиатор наследование (public, private, protected)
public:
    
private:
    std::string name;
    int capacity;
};


class Room : public BookingableEntity  {
public:
        Room(int n, double t) :  BookingableEntity(t), number(n) {
            tariff = t;
            std::cout << "Конструктор Room" << std::endl;
        }
private:
    int capacity;
    int number;
};

int main() {
    Room room101(101, 2500.00);
    std::cout << room101.getId();
    return 0;
}

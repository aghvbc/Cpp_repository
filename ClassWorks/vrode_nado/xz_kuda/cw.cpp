#include<iostream>
#include <vector>

class TimeRange {
public:
private:
    int start_sec;
    int end_sec;
}; 

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
    std::cout << std::endl;
    
    return 0;
}

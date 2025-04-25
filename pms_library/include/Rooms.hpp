#include <iostream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <DateTime.hpp>

class Room{
private:
    int roomNumber;
    bool isAvailable; //Free, Booked, Dirty, Repair
    std::vector<Date> cleaningSchedule;

public:
    bool isAvailable(DateInterval);
    bool markBooked();
    bool markDirty();
    bool markCleaned();
};

class RoomService{
private:
    std::vector<Room> rooms;

public:
    std::vector<Room> findAvailable(DateInterval);

};
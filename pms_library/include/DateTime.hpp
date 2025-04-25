#include <iostream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <string>


class Date{
private:
    int seconds;
public:
    Date fromString();
    std::string toString();
    bool operator<(const Date& other);
    Date operator+();
};

class DateInterval{
public:
    DateInterval(Date start, Date end){};
    bool overlaps(const DateInterval other);
};
#include <string>
#include <stdio.h>
#include <cstdio>
#include <iostream>


typedef unsigned long long int64;

class DateTime {
private:
    int64 seconds;
public:
    DateTime(int64 sec=0) : seconds(sec) {};
    DateTime(int d, int m, int y, int hh=0, int mm=0, int ss=0):
        seconds(
            (y-1970) * 31556926 + 
            (m-1) * 2629743 + 
            (d-1) * 86400 + 
            hh * 3600 + 
            mm * 60 + 
            ss) {};
    
    std::string toString() {
        int64 tmpSeconds = seconds;
        int year = tmpSeconds / 31556926 + 1970;
        tmpSeconds %= 31556926;
        int month = tmpSeconds / 2629743 + 1;
        tmpSeconds %= 2629743;
        int day = tmpSeconds / 86400 + 1;
        tmpSeconds %= 86400;
        int hours = tmpSeconds / 3600;
        tmpSeconds %= 3600;
        int minutes = tmpSeconds / 60;
        tmpSeconds %= 60;
        int seconds = tmpSeconds;
        
        char str[60];
        snprintf(str, 60, "%02d-%02d-%04d %02d:%02d", day, month, year, hours, minutes);
        return std::string(str);
    };
    
};

int main() {
    DateTime date1(1745493295);

    std::cout << date1.toString() << std::endl;


}
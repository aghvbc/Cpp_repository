// //пример использования функции ctime
// #include <iostream>
// #include <ctime>
 
// int main ()
// {
//   time_t rawtime;
 
//   time ( &rawtime ); // текущая дата в секундах
//   std::cout << "Текущее локальное время и дата: "
//             <<  ctime (&rawtime); // текущая дата в понятной для человека форме
 
//   return 0;
// }


#include <iostream>
#include <ctime>

int main() {
    time_t seconds = time(NULL); // Получить текущее время в секундах с 1.01.1970
    std::cout << "Секунд с 1 января 1970 года: " << seconds << std::endl;

    // Преобразуем time_t в структуру tm с локальным временем
    struct tm * timeinfo = localtime(&seconds);

    // Преобразуем структуру tm в строку с датой и временем
    char * dt_str = ctime(&seconds);
    
    std::cout << "Дата и время: " << dt_str; // выводит что-то вроде: Thu Apr 24 19:12:00 2025
    return 0;
}

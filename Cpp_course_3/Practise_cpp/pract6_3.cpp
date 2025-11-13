// Описание: Создайте простой шаблонный класс "Контейнер-пара" (аналог std::pair).

// Требования:

//     Создайте шаблон класса Pair с двумя параметрами типа: template<typename T, typename U> class Pair { ... }.
//     Добавьте два публичных поля: T first; U second;.
//     Добавьте конструктор, который принимает значения для first и second.
//     Добавьте метод void print() const, который выводит first и second.
//     В main:
//         Создайте несколько объектов Pair с разными комбинациями типов (например, Pair<int, std::string>, Pair<double, int>).
//         Инициализируйте их значениями.
//         Вызовите print() для каждого объекта.
//     Бонус: Добавьте оператор operator== для сравнения двух Pair.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>

template <typename T, typename U> 
class Pair{
public:
    T first;
    U second;
    Pair(T f, U s): first(f), second(s) {};

    void print() const{
        std::cout << "first: " << first <<  " second: " << second << std::endl;
    };

    bool operator==(const Pair& other) const {
    return first == other.first && second == other.second;
    };
};


int main(){
    Pair <int, std::string> p_is = {5, "hello"};
    Pair <int, std::string> p_is2 = {-5, "ne hello"};
    Pair <int, std::string> p_is1 = {5, "hello"};
    Pair <double, int> p_di = {3.14, 4};
    Pair <double, int> p_di2 = {3.14, 4};

    p_is.print();
    p_di.print();

    bool check_f = p_is == p_is2;
    bool check_t = p_is == p_is1;
    std::cout << check_f << std::endl; // 0 - False
    std::cout << check_t << std::endl; // 1 - True

    bool check = p_di == p_di2;
    std::cout << check << std::endl; // 1 - True

    std::cout << std::endl;
    return 0;
}
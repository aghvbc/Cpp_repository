#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>

int main(){
    auto sum = 5 + 3.14; // тип будет double, при сложении int + double, int преобразуется в double
    auto it = std::vector<int>().begin(); // it имеет тип std::vector<int>::iterator, это итератор по элементам вектора типа int.
    auto ptr = std::make_unique<int>(42);  // ptr будет типа std::unique_ptr<int>, это умный указатель, владеющий объектом int со значением 42.

    int* p = nullptr; // Объявление указателя на nullptr

    if (p == nullptr) { // Проверка что указатель действительно nullptr
        std::cout << "rawPtr инициализирован как nullptr" << std::endl;
    }

    std::vector<int> vec1; //создание первого вектора без значений
    std::vector<int> vec2 = {1,2,3}; //создание второго вектора со значениями

    std::cout << "До перемещения:\n";
    std::cout << "  vec1 размер: " << vec1.size() << std::endl;
    std::cout << "  vec2 размер: " << vec2.size() << std::endl;

    vec1 = std::move(vec2); //Перемещение содержимого второго вектора в первый

    std::cout << "После перемещения:\n";
    std::cout << "  vec1 размер: " << vec1.size() << std::endl;
    std::cout << "  vec2 размер: " << vec2.size() << std::endl; 

    // До перемещения:
    // vec1 размер: 0
    // vec2 размер: 3
    // После перемещения:
    // vec1 размер: 3
    // vec2 размер: 0
    
    return 0;
}
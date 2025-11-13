#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>

class Data{
public:
    int value;
    Data(int val) : value(val){
        std::cout << "Конструктор" << std::endl;
    };

    ~Data(){
        std::cout << "Деструктор" << std::endl;
    };
};


int main(){
    std::unique_ptr<Data> ptr1  = std::make_unique<Data>(42);
    std::cout << "ptr1 value = " << ptr1->value << std::endl;

    //std::unique_ptr<Data> ptr2 = std::make_unique<Data>(); 
    //auto ptr2 = ptr1; // ошибка компиляции

    auto ptr2 = std::move(ptr1); //Перемещение владения  

    if (!ptr1){ // теперь prt1 пустой
        std::cout << "Пустой" << std::endl;
    }
    else{
        std::cout << ptr1->value << std::endl;
    }

    std::cout << "ptr2 value = " << ptr2->value << std::endl;

    std::vector<std::unique_ptr<Data>> u_vector;
    u_vector.push_back(std::make_unique<Data>(5));
    u_vector.push_back(std::make_unique<Data>(10));
    u_vector.push_back(std::make_unique<Data>(20));

    std::cout << "Вывод значений из вектора:" << std::endl;
    for (const auto& el : u_vector) {
        std::cout << "value = " << el->value << std::endl;
    }
    std::cout<<std::endl;
    return 0;
}



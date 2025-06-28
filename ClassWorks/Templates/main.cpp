#include <string>
#include <iostream>
#include <vector>

template <class T>
void print(T val){
    std::cout << "Value is " << val << std::endl;
};

//перегрузка шаблонной функции
template<>
void print(std::vector<int> vec){
    for (const auto& el : vec){
        std::cout << el << " ";
    };
    std::cout << std::endl;
};

int main(){
    std::vector<int> vvv = {1,2,3,4};
    print(vvv);
};

///------------------
// void print(int val){
//     std::cout << "Value is" << val << std::endl;
// }

// void print(char val){
//     std::cout << "Value is" << val << std::endl;
// }

// void print(double val){
//     std::cout << "Value is" << val << std::endl;
// }


/// в зависимости от типа будет создавать то же что и написано сверху, только пишем одну функцию с template

// template <class T>
// void print(T val){
//     std::cout << "Value is " << val << std::endl;
// };

    //template(одна функция а не три)
    // print(2);
    // print('f');
    // print(2.3123);

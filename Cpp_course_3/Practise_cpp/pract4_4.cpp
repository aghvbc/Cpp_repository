#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>

int main(){
    std::vector<int> v {1, -2, 3, -4, 5, 6, -7, 8};
    auto it = std::find_if(v.begin(), v.end(), [](int x){return x < 0;});
    if (it != v.end()){
        std::cout << "First negative number at index: " << std::distance(v.begin(), it) << std::endl;
    }
    else{
        std::cout << "No negative numbers" << std::endl;
    }

    auto it_c = std::count_if(v.begin(), v.end(), [](int x){return x < 0;});
    std::cout << "Number of negatives numbers: " << it_c << std::endl; 

    auto it_f3 = std::find_if(v.begin(), v.end(), [](int x){return x%3 == 0;});
    auto it_c3 = std::count_if(v.begin(), v.end(), [](int x){return x%3 == 0;});

    if (it_f3 != v.end()){
        std::cout << "First 3 number at index: " << std::distance(v.begin(), it_f3) << std::endl;
    }
    else{
        std::cout << "No negative numbers" << std::endl;
    }

    std::cout << "Number of 3 numbers: " << it_c3 << std::endl; 


    std::cout << std::endl;
    return 0;
}


    // Используйте std::find_if с лямбдой, чтобы найти первое отрицательное число.
    // Используйте std::count_if с лямбдой, чтобы подсчитать все отрицательные числа.
    // Выведите найденное отрицательное число (если есть) и общее количество отрицательных чисел.
    // Бонус: Попробуйте использовать std::find_if и std::count_if для поиска/подсчета чисел, кратных 3.
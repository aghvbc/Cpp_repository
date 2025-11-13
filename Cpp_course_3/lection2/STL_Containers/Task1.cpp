#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

int main(){
    std::vector<int> vec{4,2,5,2,1,4,3,5};
    std::cout << "Исходный вектор: ";
    for (int n : vec){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::set<int> unique_elements(vec.begin(), vec.end());
    std::vector<int> unique_vec(unique_elements.begin(), unique_elements.end());

    std::cout << "Вектор без дубликатов (std::set) и отсортированный: ";
    for (int n : unique_vec){
        std::cout << n << " ";
    } 
    std::cout << std::endl;

    std::unordered_set<int> unordered_unique_elements(vec.begin(), vec.end());
    std::vector<int> unordered_unique_vec(unordered_unique_elements.begin(), unordered_unique_elements.end());


    std::cout << "Вектор без дубликатов (std::unordered_set) - порядок не гарантирован: ";
    for (int n : unordered_unique_vec){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
};
#include <vector>
#include <iostream>

int main(){
std::vector<int> v = {1, 2, 3}; // Инициализация списком

v.push_back(4); // Добавление в конец

std::cout << "Size: " << v.size() << ", Element [0]: " << v[0] << "\n";

v.pop_back(); // Удаление из конца

for(size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " "; // По индексу
    std::cout << "\n";

for(const auto& elem : v) std::cout << elem << " "; // Range-based for (итераторы внутри)
    std::cout << "\n";
};

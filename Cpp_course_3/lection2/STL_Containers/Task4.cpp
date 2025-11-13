#include <iostream>
#include <vector>
#include <chrono>
#include <list>

int main(){
    size_t size = 100000;

    std::vector<int> vec(size, 1);
    std::list<int> lst(size, 1);

    auto vec_it = std::next(vec.begin(), vec.size() / 2);
    auto lst_it = std::next(lst.begin(), lst.size() / 2);


    auto start_vec = std::chrono::high_resolution_clock::now();
    vec.insert(vec_it, 999); 
    auto end_vec = std::chrono::high_resolution_clock::now();
    auto duration_vec = std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec);
    std::cout << "Vector insert time: " << duration_vec.count() << " microseconds\n";

    auto start_lst = std::chrono::high_resolution_clock::now();
    lst.insert(lst_it, 999); 
    auto end_lst = std::chrono::high_resolution_clock::now();
    auto duration_lst = std::chrono::duration_cast<std::chrono::microseconds>(end_lst - start_lst);
    std::cout << "List insert time: " << duration_lst.count() << " microseconds\n";

    // Вставка в середину у std::list — просто изменение пары указателей.
    // У std::vector нужно сдвинуть половину или больше элементов, чтобы освободить место.

    return 0;
};
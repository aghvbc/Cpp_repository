// Описание: Напишите шаблонную функцию для нахождения минимального элемента в массиве.

// Требования:

//     Создайте шаблонную функцию T findMin(const T* arr, size_t size).
//     Функция должна принимать указатель на начало массива и его размер.
//     В теле функции реализуйте поиск минимального элемента, используя operator<.
//     В main:
//         Создайте массивы int и double с произвольными значениями.
//         Вызовите findMin для каждого массива, передав ему имя массива (которое автоматически преобразуется в указатель) и его размер.
//         Выведите найденные минимальные значения.
//     Бонус: Используйте std::vector и std::begin/std::end (или .data() и .size()) вместо C-массива и size_t.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono> 

// template <typename T>
// T findMin(const T* arr, size_t size) {
//     T min = arr[0];
//     for (size_t i = 1; i < size; ++i) {
//         if (arr[i] < min) {
//             min = arr[i];
//         }
//     }
//     return min;
// };

template <typename T>
T findMin(const T* arr, size_t size) {
    T min = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
};

template <typename T>
T findMin(const std::vector<T>& vec) { //отдельная  функция для векторов
    return findMin(vec.data(), vec.size()); // vec.data() возвращает указатель на начало массива(вектора)
}


int main(){

    int arr1[] = {1, 3, 5, -2, 6};
    double arr2[] = {1.43, 4, 1, -5.61, 3.14};

    std::cout << "Min int (arr): " << findMin(arr1, 5) << std::endl;
    std::cout << "Min double (arr): " << findMin(arr2, 5) << std::endl;

    std::vector<int> vec1 {1, -3, 5, 2, 6};
    std::vector<double> vec2 {1.43, 4, 1, 5.61, -3.14};

    std::cout << "Min int (vector): " << findMin(vec1) << std::endl;
    std::cout << "Min double (vector): " << findMin(vec2) << std::endl;

    std::cout << std::endl;
    return 0;
}
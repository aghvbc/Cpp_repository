/*Описание: Создайте шаблонный класс-контейнер, напоминающий std::vector, но с базовой функциональностью и RAII.

Требования (упрощённо):

    Создайте шаблон класса SimpleVector<T>.
    Используйте std::unique_ptr<T[]> data; для хранения данных (RAII!).
    Добавьте конструктор, принимающий начальный размер. Выделите память через std::make_unique<T[]>(size).
    Добавьте operator[] для доступа к элементам.
    Добавьте метод size_t size() const.
    Деструктор не нужен! unique_ptr сам освободит память.
    В main:
        Создайте SimpleVector<int> размером 5.
        Заполните его значениями (например, через operator[]).
        Выведите значения.
        Позвольте объекту выйти из области видимости. Наблюдайте автоматическое освобождение памяти.*/

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

template <typename T>
class SimpleVector{
public:
    std::unique_ptr<T[]> data;
    size_t size_;

    SimpleVector(size_t n): size_(n), data(std::make_unique<T[]>(n)){};

    size_t size() const {
        return size_;
    };

   T& operator[](int index){
        return data[index];
   };

   const T& operator[](int index) const{
        return data[index];
   };

};


int main(){
    std::vector<int> vec{1,5,-10,5,8};
    SimpleVector<int> s_vec(5);
    int cnt = 0;
    for (auto el : vec){
        s_vec[cnt] = el;
        cnt ++;
    }
    for (int i = 0; i < s_vec.size(); ++i){
        std::cout << s_vec[i] << std::endl;
    };

    std::cout << std::endl;
    return 0;
}
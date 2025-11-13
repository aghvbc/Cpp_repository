/*Создайте класс SafeArray, который будет управлять динамическим массивом элементов типа T (шаблон). Используйте RAII и умные указатели (std::unique_ptr) для автоматического управления памятью.

Требования:

Шаблон класса: template<typename T> class SafeArray { ... }.

Поля класса:

    std::unique_ptr<T[]> data; - умный указатель на массив элементов типа T.
    size_t size; - текущий размер массива.

Конструктор: SafeArray(size_t n) - выделяет память для n элементов типа T. Используйте std::make_unique<T[]>(n).

Оператор доступа по индексу: T& operator[](size_t index) и const T& operator[](size_t index) const - позволяет получить доступ к элементу по индексу. Проверку границ реализовывать не обязательно.

Методы:

    size_t getSize() const - возвращает размер массива.

Move-семантика (опционально, но рекомендуется):

    Реализуйте move-конструктор SafeArray(SafeArray&& other).
    Реализуйте move-оператор присваивания SafeArray& operator=(SafeArray&& other).
    Используйте std::move при перемещении data из other.

Деструктор: Не нужен! std::unique_ptr автоматически освободит память при уничтожении объекта SafeArray.

Демонстрация в main:

    Создайте объект SafeArray<int> размером 5.
    Заполните его значениями (например, через operator[]).
    Выведите значения.
    Создайте другой SafeArray и переместите первый в него.
    Выведите значения из нового объекта.
    Позвольте обоим объектам выйти из области видимости. Убедитесь, что память освобождается автоматически (можно добавить вывод в деструктор T, если T - пользовательский класс, но для int это не нужно).*/


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

template<typename T> 
class SafeArray{
public:
    std::unique_ptr<T[]> data;
    size_t size;

    SafeArray(size_t n): size(n), data(std::make_unique<T[]>(n)){};

    size_t getSize() const {return size;};

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const{
        return data[index];
    };

    SafeArray(SafeArray&& other)noexcept : data(std::move(other.data)), size(other.size) {
        other.size = 0;
    }

    SafeArray& operator=(SafeArray&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);  // "забираем" данные
            size = other.size;
            other.size = 0;
        };
        return *this;
    };
};


int main(){
    std::vector<int> vec = {1,-4,5,8,20};
    SafeArray<int> arr(5);

    int cnt = 0;

    for (auto el : vec){
        arr[cnt] = el;
        ++cnt;
    };

    for (int i = 0; i < arr.getSize(); ++i){
        std::cout << arr[i] << std::endl;
    };

    std::cout << "\n";

    // Перемещение массива
    SafeArray<int> movedArr = std::move(arr);

    std::cout << "Moved array contents:\n";
    for (size_t i = 0; i < movedArr.getSize(); ++i) {
        std::cout << movedArr[i] << " ";
    }
    std::cout << "\n";

    // Проверка, что "arr" теперь пуст
    std::cout << "Original (moved-from) array size: " << arr.getSize() << "\n";
        
    // for (int i = 0; i < arr.getSize(); ++i){ // попытка вывести приведёт к ошибке
    //     std::cout << arr[i] << std::endl;
    // };

    std::cout << std::endl;
    return 0;
}

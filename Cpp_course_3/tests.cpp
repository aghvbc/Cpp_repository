#include <iostream>
#include <memory> // Для std::unique_ptr и std::make_unique

// Шаблонный класс SafeArray
template<typename T>
class SafeArray {
private:
    std::unique_ptr<T[]> data; // Умный указатель на массив
    size_t size;               // Размер массива

public:
    // Конструктор: выделение памяти под массив
    SafeArray(size_t n) : data(std::make_unique<T[]>(n)), size(n) {
    }

    // Оператор доступа к элементу массива (небезопасный — без проверки границ)
    T& operator[](size_t index) {
        return data[index];
    }

    // Константный оператор для доступа из const-контекста
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Метод для получения размера массива
    size_t getSize() const {
        return size;
    }

    // Move-конструктор
    SafeArray(SafeArray&& other) noexcept
        : data(std::move(other.data)), size(other.size) {
        other.size = 0;
    }

    // Move-оператор присваивания
    SafeArray& operator=(SafeArray&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);  // "забираем" данные
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

};

// Демонстрация в main
int main() {
    // Создание массива
    SafeArray<int> arr(5);

    // Заполнение значениями
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i * 10); // Например: 0, 10, 20, 30, 40
    }

    // Вывод значений
    std::cout << "Original array contents:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
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

    return 0;
}
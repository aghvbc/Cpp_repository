/*Описание: Реализуйте класс StringBuffer, который управляет динамическим буфером символов. Это упражнение демонстрирует важность правильного управления ресурсами.

Требования:

    Приватные поля: char* data (указатель на динамически выделенную память), size_t size (размер буфера).
    Конструктор по умолчанию.
    Конструктор, принимающий const char* str (копирует строку в динамическую память).
    Деструктор - освобождает память, выделенную под data.
    Конструктор копирования - создает глубокую копию другого объекта StringBuffer. (Подсказка: выделите новую память и скопируйте данные).
    Оператор присваивания копированием (operator=) - присваивает содержимое одного StringBuffer другому, также выполняя глубокое копирование. Обработайте самоприсваивание (buf1 = buf1).
    Метод const char* c_str() const - возвращает указатель на внутренний буфер (для вывода/сравнения).
    Метод size_t length() const - возвращает длину строки в буфере.

Демонстрация в main():

    Создайте объект StringBuffer buf1("Hello");.
    Создайте объект StringBuffer buf2(buf1); (конструктор копирования).
    Создайте объект StringBuffer buf3; buf3 = buf1; (оператор присваивания).
    Выведите содержимое всех трех буферов.
    Объявите блок { StringBuffer buf4("World"); StringBuffer buf5 = buf4; } - продемонстрируйте вызов деструкторов.
    Протестируйте самоприсваивание: buf1 = buf1;.*/

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
#include <cmath>
#include <numeric> 
#include <cstring>

class StringBuffer{
private:
    char* data;
    size_t size;
public:
    StringBuffer(): data(nullptr), size(0){
        data = new char[1];
        data[0] = '\0';
    };

    StringBuffer(const char* str){
        if (str){
            size = std::strlen(str);
            data = new char[size+1];
            std::strcpy(data, str);
        }
        else{
            size = 0;
            data = new char[0];
            data[0] = '\0';
        }
    };

    ~StringBuffer(){
        delete[] data;
    }

    StringBuffer(const StringBuffer& other){
        size = other.size;
        data = new char[size+1];
        std::strcpy(data, other.data);
    };

    StringBuffer& operator=(const StringBuffer& other){
        if (this == &other ){
            return *this;
        }

        delete[] data;

        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
        return *this;
    };

    const char* c_str() const {
        return data;
    };

    size_t length() const {
        return size;
    };

};


int main() {
    std::cout << "Создание buf1" << std::endl;
    StringBuffer buf1("Hello");

    std::cout << "Копирование buf1 -> buf2 (конструктор копирования)" << std::endl;
    StringBuffer buf2(buf1);

    std::cout << "Присваивание buf1 -> buf3 (оператор присваивания)" << std::endl;;
    StringBuffer buf3;
    buf3 = buf1;

    std::cout << "Вывод содержимого всех 3 буферов" << std::endl;;
    std::cout << "buf1: " << buf1.c_str() << " (length = " << buf1.length() << ")\n";
    std::cout << "buf2: " << buf2.c_str() << " (length = " << buf2.length() << ")\n";
    std::cout << "buf3: " << buf3.c_str() << " (length = " << buf3.length() << ")\n";

    std::cout << "Блок с buf4 и buf5" << std::endl;
    {
        StringBuffer buf4("World");
        StringBuffer buf5 = buf4;
    }  // Деструкторы вызываются здесь 

    std::cout << "Самоприсваивание: buf1 = buf1" << std::endl;
    buf1 = buf1;

    std::cout << "Конец main";

    std::cout << std::endl;
    return 0;
};
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


/*Создайте шаблонный класс ThreadSafeStack, который реализует стек (LIFO - Last In, First Out). Добавьте базовую синхронизацию для операций push и pop.

Требования:

    Шаблон класса: template<typename T> class ThreadSafeStack { ... }.
    Поля класса:
        std::vector<T> data; - для хранения элементов. Или используйте std::deque<T>.
        std::mutex mtx; - мьютекс для синхронизации.
    Методы:
        void push(const T& item) - добавляет элемент в стек. Должен использовать std::lock_guard для защиты операции.
        bool pop(T& item) - удаляет и возвращает последний элемент из стека. Возвращает true, если элемент успешно извлечён, false, если стек пуст. Также должен использовать std::lock_guard. Совет: Проверьте empty() внутри защищённой области.
        bool empty() const - проверяет, пуст ли стек. Важно: Подумайте, нужно ли защищать этот метод мьютексом? (Да, чтобы избежать race condition между empty() и pop() в разных потоках).
        size_t size() const - возвращает количество элементов в стеке. Аналогично empty(), его стоит защитить.
    Демонстрация в main:
        Создайте объект ThreadSafeStack<int>.
        Создайте два потока:
            Один поток должен в цикле (например, 1000 итераций) добавлять числа (например, индекс цикла) в стек.
            Второй поток должен в цикле (например, 1000 итераций) пытаться извлекать числа из стека и выводить их (или просто считать количество успешных извлечений).
        Дождитесь завершения обоих потоков в main.
        Выведите итоговый размер стека (должен быть 0, если потоки корректно взаимодействовали).*/


template<typename T> 
class ThreadSafeStack{
public:
    std::vector<T> data;
    mutable std::mutex mtx;

    void push(const T& item){
        std::lock_guard<std::mutex> lock(mtx);
        data.push_back(item);
    };

    bool pop(T& item){
        std::lock_guard<std::mutex> lock(mtx);
        
        if (data.empty()){    
            return false;
        };
        item = data.back();
        data.pop_back();
        return true;
    };

    bool empty() const{
        std::lock_guard<std::mutex> lock(mtx);
        return data.empty();
    };

    size_t size() const{
        std::lock_guard<std::mutex> lock(mtx);
        return data.size();
    }
};

int main(){
    ThreadSafeStack<int> stack;


    constexpr int COUNT = 1000;
    int pop_success_count = 0;

    // Добавляем элементы
    std::thread producer([&stack]() {
        for (int i = 0; i < COUNT; ++i) {
            stack.push(i);
        }
    });

    //Извлекаем элементы
    std::thread consumer([&stack, &pop_success_count]() {
        for (int i = 0; i < COUNT; ++i) {
            int value;
            if (stack.pop(value)) {
                ++pop_success_count;
                std::cout << "Извлечено: " << value << std::endl;
            };
        }
    });

    producer.join();
    consumer.join();

    // Результаты
    std::cout << "Успешно извлечено: " << pop_success_count << std::endl;
    std::cout << "Итоговый размер стека: " << stack.size() << std::endl;
    
    std::cout << std::endl;
    return 0;
}
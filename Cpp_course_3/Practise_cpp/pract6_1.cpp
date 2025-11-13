// Описание: Создайте общую переменную, к которой будут обращаться несколько потоков, и синхронизируйте доступ с помощью std::mutex.

// Требования:

//     Объявите глобальную переменную int shared_counter = 0; и std::mutex counter_mutex;.
//     Создайте функцию void increment_counter(int times), которая в цикле for(int i = 0; i < times; ++i):
//         Блокирует мьютекс с помощью std::lock_guard<std::mutex> lock(counter_mutex);.
//         Увеличивает shared_counter.
//         lock_guard автоматически разблокирует мьютекс при выходе из области видимости.
//     В main:
//         Создайте, например, 2 потока, каждый из которых вызывает increment_counter с аргументом, например, 1000.
//         Вызовите join() для потоков. 
//         Выведите итоговое значение shared_counter.
//     Повторите эксперимент без использования mutex и lock_guard. Сравните результаты.

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


int shared_counter = 0;
std::mutex counter_mutex;

void increment_counter(int times){
    for (int i=0; i < times; ++i){
        //std::lock_guard<std::mutex> lock(counter_mutex);
        shared_counter++;
    }
}

int main(){
    std::thread t1(increment_counter, 1000);
    std::thread t2(increment_counter, 1000);

    t1.join();
    t2.join();

    std::cout << "Total counter: " << shared_counter << std::endl; // с lock_guard - всегда 2000; без lock_guard как получится (1000, 1048, 2000),
    //это происходит потому что два потока могут работать с одной и той же ячейкой памяти и в итоге один поток закончит раньше другого и произойдёт затирание памяти
    
    std::cout << std::endl;
    return 0;
}
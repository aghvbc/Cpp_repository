// Описание: Создайте несколько потоков, выполняющих одну и ту же функцию, но с разными аргументами.

// Требования:

//     Создайте функцию void printID(int id), которая выводит строку, например, "Thread ID: <id>". Используйте std::this_thread::get_id() для получения ID потока (опционально).
//     В main:
//         Создайте вектор std::vector<std::thread> для хранения объектов потоков.
//         В цикле (например, for(int i = 0; i < 5; ++i)) создавайте std::thread, передавая ему функцию printID и текущее значение i.
//         Добавляйте созданный thread в вектор.
//         После цикла, в другом цикле, вызовите join() для каждого потока в векторе.
//     Запустите программу. Обратите внимание на порядок вывода.
//     Бонус: Передавайте в функцию printID не только id, но и, например, строку "Hello" и выводите "Thread ID: <id>, Message: Hello".


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

std::mutex mutx; 

void PrintID(int id, std::string message){
    std::lock_guard<std::mutex> lock(mutx); //можно использовать mutex чтобы не было одновременно доступа (чтобы такого не произошло -> Thread ID: Thread ID: 10)
    std::cout<<"Thread ID: " << id <<  " Message: " << message << std::endl;
}

int main(){
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i){
        // std::this_thread::sleep_for(std::chrono::seconds(1)); -- можно использовать sleep чтобы все потоки выполнились последовательно
        // std::cout << "Slept for 1 seconds." << std::endl;
        std::thread t(PrintID, i, "Hello");
        threads.push_back(std::move(t));
    };
    for (auto &thread : threads){
        thread.join();
    };

    //Порядок вывода не постоянен так как один поток(напр. 4) может выполниться раньше другого(напр. 2)


    std::cout << std::endl;
    return 0;
}
/*Описание: Обработайте набор данных (например, список оценок студентов или координат точек) с использованием STL.

Требования:

    Создайте std::vector<int> (например, оценки: {85, 92, 78, 96, 88, 75, 90, 82}).
    Найдите и выведите все оценки выше 85, используя std::copy_if и std::back_inserter в новый вектор. Используйте лямбду для условия.
    Отсортируйте оригинальный вектор в порядке убывания (используйте лямбду в std::sort).
    Подсчитайте количество четных оценок, используя std::count_if и лямбду.
    Найдите итератор на первый элемент, значение которого больше среднего арифметического всех элементов (подсчитайте среднее с помощью std::accumulate).*/


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

int main() {
    std::vector<int> grades = {85, 92, 78, 96, 88, 75, 90, 82};

    std::vector<int> above85;
    std::copy_if(
        grades.begin(), grades.end(),
        std::back_inserter(above85),
        [](int grade) {
            return grade > 85;
        }
    );

    std::cout << "Оценки выше 85: ";
    for (int g : above85) {
        std::cout << g << " ";
    }
    std::cout << "\n";

    std::sort(grades.begin(), grades.end(),[](int a, int b) {return a > b;}
    );

    std::cout << "Оценки (по убыванию): ";
    for (int g : grades) {
        std::cout << g << " ";
    }
    std::cout << "\n";

    int evenCount = std::count_if(
        grades.begin(), grades.end(),
        [](int grade) {
            return grade % 2 == 0;
        }
    );

    std::cout << "Количество чётных оценок: " << evenCount << "\n";

    double avg = std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();

    std::cout << "Среднее значение: " << avg << "\n";

    auto it = std::find_if(
        grades.begin(), grades.end(),
        [avg](int grade) {
            return grade > avg;
        }
    );

    if (it != grades.end()) {
        std::cout << "Первая оценка, превышающая среднее: " << *it << "\n";
    } else {
        std::cout << "Нет оценок выше среднего.\n";
    }

    return 0;
}
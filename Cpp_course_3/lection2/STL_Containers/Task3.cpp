#include <iostream>
#include <vector>

int main() {
    std::vector<int> grades = {85,92,78,96,88};

    std::cout << "Оценки студентов: ";
    for (const auto& grade: grades){
        std::cout << grade << " ";
    };
    std::cout << std::endl;

    grades.push_back(100);
    
    // Доступ к элементу вне границ через operator[]
    try {
        // Это не вызовет исключение, но результат — неопределённое поведение
        std::cout << "grades[100] = " << grades[100] << std::endl;  //значение должно быть неопределенно но из-за моего компилятора вообще выпадает ошибка.
    } catch (...) {
        std::cout << "Исключение при использовании grades[100]" << std::endl;
    }

    std::cout << "\nПопытка доступа к элементу at(100) (через метод at()):" << std::endl;
    try {
        // исключение std::out_of_range
        std::cout << "grades.at(100) = " << grades.at(100) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }
    // Попытка доступа к элементу at(100) (через метод at()):
    // grades.at(100) = Исключение: vector::_M_range_check: __n (which is 100) >= this->size() (which is 6)


    //Разница должна быть в этом:
    // grades[100]:
    // Не проверяет границы. (мой компилятор проверяет)
    // Не вызывает исключения.
    // Может вернуть мусор, 0 или привести к сбою программы.

    //grades.at(100):

    // Проверяет границы.
    // Если индекс выходит за пределы, выбрасывает исключение std::out_of_range.
    // Безопаснее

    return 0;
}


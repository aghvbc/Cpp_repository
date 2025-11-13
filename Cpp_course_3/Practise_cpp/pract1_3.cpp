/*Описание: Рассмотрим два подхода к моделированию "Студента Университета".

Сценарий 1 (Наследование):

    class Person { ... }; // Имя, возраст
    class Student : public Person { ... }; // Наследует имя, возраст. Добавляет student_id, major.

Сценарий 2 (Композиция):

    class Person { ... }; // Имя, возраст
    class Student { Person p; std::string student_id; std::string major; ... }; // Содержит объект Person.*/

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

//Сценарий 1
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name_, int age_) : name(name_), age(age_) {}

    void printPerson() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student: public Person{
private:
    std::string student_id;
    std::string major;
public:
    Student(const std::string& name_, int age_, const std::string& id, const std::string& major_)
        : Person(name_, age_), student_id(id), major(major_) {}

    void printStudent() const {
        printPerson(); // вызываем метод базового класса
        std::cout << "Student ID: " << student_id << ", Major: " << major << std::endl;
    }
};

//Сценарий 2
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name_, int age_) : name(name_), age(age_) {}

    void printPerson() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student {
private:
    Person person;
    std::string student_id;
    std::string major;

public:
    Student(const std::string& name_, int age_, const std::string& id, const std::string& major_)
        : person(name_, age_), student_id(id), major(major_) {}

    void printStudent() const {
        person.printPerson(); // передаём выполнение задачи другой функции
        std::cout << "Student ID: " << student_id << ", Major: " << major << std::endl;
    }
};

int main() {
    Student s("Alice", 20, "S123456", "Computer Science");
    s.printStudent();

    //Вывод:
    /*
    Name: Alice, Age: 20
    Student ID: S123456, Major: Computer Science
    */

    
    Student s("Bob", 22, "S987654", "Mathematics");
    s.printStudent();

    //Вывод:
    /*
    Name: Bob, Age: 22
    Student ID: S987654, Major: Mathematics
    */

    //Если мы не хотим зависеть от родительского класса то используем композиция, иначе наследование

    std::cout << std::endl;
    return 0;
};
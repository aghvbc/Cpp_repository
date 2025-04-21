#include <iostream>
#include <string>
#include <vector>

// Эффект,  когда используется тип данных ОДИН (как будто)
// При реальном использовании разных типов
class Pet{ // абстрактный класс (потому что есть хотя бы одна виртуальная фукнция)
protected:
    std::string name;
    int age;
public:
    Pet(std::string name, int age): name(name), age(age) {};
    void info(){
        std::cout << "Name: " << name << std::endl;
    };

    // virtual void say(){
    //     std::cout<< "some_pet " << name << " says: SOMETHING!" << std::endl;
    // };

    virtual void say() = 0; // чистая виртульная функция
};

class Dog: public Pet {
private:
    int commandCounts;
public:
    Dog(std::string name, int age): Pet(name, age) {};
    Dog(std::string name): Dog(name, 0) {};//базовый конструктор если не указан возраст
    void say() override {
        std::cout<< "Dog " << name << " says: Woof" << std::endl;
    };
    ~Dog() = default;
};

class Cat: public Pet {
private:
    int numLives = 9;
public:
    Cat(std::string name, int age): Pet(name, age){}
    void say() override {
        std::cout<< "Cat " << name << " says: Meow" << std::endl;
    };
    ~Cat() = default;
};

class Chesyrsky : public Cat {
public:
    Chesyrsky(): Cat("Chesyrskiy", 1000){};
    void say() override {
        Cat::say();
        std::cout<< "Hello, Alice!" << std::endl;
    };
};



int main()
{
    // Dog dog("Barboskin",1);
    // Cat cat("Gav",0);
    // dog.say();
    // cat.say();

    // std::vector <Pet> zoo; // тоже что Pet zoo[20];

    

    // for (Pet pet : zoo){ // for el in some_list
    //     pet.say(); 
    // };

    std::vector <Pet*> zoo;
    // Pet pet("Barboskin", 1); // ошибка - абстрактный тип
    // Pet* pet = new Pet("Barboskin", 1); //так тоже не получится 

    //for vector
    Pet *dog = new Dog("Barboskin", 1);
    Pet *cat = new Cat("Gav", 0);
    Pet* feryCat = new Chesyrsky;
    zoo.push_back(dog);
    zoo.push_back(cat);
    zoo.push_back(feryCat);


    for (Pet* pet : zoo){ // for el in some_list
        pet->say(); // (*pet).say();
    };

    return 0;
}
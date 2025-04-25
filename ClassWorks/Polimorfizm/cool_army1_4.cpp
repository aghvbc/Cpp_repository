/*
1.4. Классная армия - 4
Условие
Добавьте в каждый класс виртуальный метод draw(), который будет печатать на экран специальный символ воина.
● Пехотинец – !
● Лучник – *
● Рыцарь – &
● Конный рыцарь – %
Создайте такую же армию, как и в предыдущей задаче, и выведите в строку символы каждого воина, как будто все они
стоят в одну шеренгу.
Формат входных данных
С клавиатуры вводится число n – количество каждого типа солдат в армии.
Формат выходных данных
Выведите персональный символ для каждого из 4n солдатов в том порядке, в котором они стоят в своей "шеренге".
*/

#include <iostream>
#include <vector>
#include <string>


class FootSoldier {
protected:
    int speed;
    int damage;
    int armor;
    int distance;
    FootSoldier(int s, int d, int a, int di) : speed(s), damage(d), armor(a), distance(di) {};
public:
    FootSoldier() : speed(2), damage(1), armor(0), distance(0) {};
    void info() {
        std::cout << "Speed: " << speed << std::endl
        << "Damage: " << damage << std::endl
        << "Armor: " << armor << std::endl
        << "Distance: " << distance << std::endl
        << std::endl;
    };
    virtual char draw(){
        return '!';
    };
};

class Archer: public FootSoldier{
public:
    Archer(): FootSoldier(2,2,0,3) {};

    char draw() override{
        return '*';
    };

};

class Knight: public FootSoldier{
public:
    Knight() : FootSoldier(1,3,1,1) {};

    char draw() override{
        return  '&' ;
    };


};

class HorseKnight: public Knight{
public:
    HorseKnight(): Knight()  {
        speed = 3;
        damage = 3;
        armor = 1;
        distance = 1;
    };

    char draw() override{
        return '%';
    };

};

int main(){

    std::vector <FootSoldier*> army;

    int N;
    std::cin >> N;

    std::vector <std::string> army_s;

    for (int i = 0; i<N; i++){
        army.push_back(new FootSoldier());
        army.push_back(new Archer());
        army.push_back(new Knight());
        army.push_back(new HorseKnight());
    };

    for (auto soldier : army) {
        std::cout << soldier->draw();  
    }
    std::cout << std::endl;

    for (auto del : army){
        delete del;
    };

    return 0;
};
/*
1.3. Классная армия - 3 (стр 1 из 2)
Условие
Подобно тому, что вы делали в первой задаче, создайте армию, в которой будет n пехотинцев, n лучников, n рыцарей и n
конных рыцарей. Для каждого из них вызовите метод info().
Внутри массива солдаты должны идти партиями по четыре: пехотинец, лучник, рыцарь, конный рыцарь, снова пехотинец и
так далее.
Формат входных данных
С клавиатуры вводится число n – количество каждого типа солдат в армии.
Формат выходных данных
Выведите информацию о 4n солдатах в том порядке, в котором они стоят в своей "шеренге".
Примечания
Не забудьте очистить выделенную динамическую память
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
    }
};

class Archer: public FootSoldier{
public:
    Archer(): FootSoldier(2,2,0,3) {};

};

class Knight: public FootSoldier{
public:
    Knight() : FootSoldier(1,3,1,1) {};


};

class HorseKnight: public Knight{
public:
    HorseKnight(): Knight()  {
        speed = 3;
        damage = 3;
        armor = 1;
        distance = 1;
    };

};

int main(){

    std::vector <FootSoldier*> army;

    int N;
    std::cin >> N;

    for (int i = 0; i<N; i++){
        army.push_back(new FootSoldier());
        army.push_back(new Archer());
        army.push_back(new Knight());
        army.push_back(new HorseKnight());
    };

    for (auto soldier : army){
        soldier->info();
    };

    for (auto del : army){
        delete del;
    };

    return 0;
};
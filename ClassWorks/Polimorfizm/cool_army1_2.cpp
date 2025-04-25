/*
1.2. Классная армия - 2 (стр 1 из 3)
Усовершенствуйте пехотинцев. Создайте несколько классов-наследников:
● Лучник (Archer);
● Рыцарь (Knight);
● Конный рыцарь (HorseKnight), который будет в свою очередь наследоваться от рыцаря (Knight)
В каждом из классов создайте конструкторы без параметров, которые будут инициализировать объекты в соответствии
с таблицей:
            speed damage armor distance
FootSoldier 2 1 0 0
Archer 2 2 0 3
Knight 1 3 1 1
HorseKnight 3 3 1 1

Примечание
Возможно, вам понадобится создать еще один конструктор в классе Knight (по аналогии с FootSoldier).

*/

#include <iostream>
#include <vector>


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
    // std::vector <FootSoldier*> army;

    // FootSoldier* fs1 = new FootSoldier();
    // // fs1->info();
    // Archer* ar1 = new Archer();
    // // ar1->info();
    // Knight* kn1 = new Knight();
    // // kn1->info();
    // HorseKnight* hkn1 = new  HorseKnight();
    // // hkn1->info();

    // army.push_back(fs1);
    // army.push_back(ar1);
    // army.push_back(kn1);
    // army.push_back(hkn1);

    // for (FootSoldier* soldier : army){
    //     soldier->info();
    // };

    // for (auto del : army){
    //     delete del;
    // }

    //1.2. Классная армия - 2 (стр 3 из 3)
    FootSoldier* foot_soldier = new FootSoldier;
    FootSoldier* archer = new Archer;
    FootSoldier* knight = new Knight;
    FootSoldier* horse_knight = new HorseKnight;
    foot_soldier->info();
    archer->info();
    knight->info();
    horse_knight->info();
    delete foot_soldier;
    delete archer;
    delete knight;
    delete horse_knight;
    



    return 0;
};
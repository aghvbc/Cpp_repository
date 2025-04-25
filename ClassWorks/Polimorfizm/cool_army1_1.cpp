// 1.1. Классная армия - 0
// Вам дан класс FootSoldier - пехотинец. Создайте трёх пехотинцев, используя динамическую память и указатели.
// Выведите информацию о трёх пехотинцах и не забудьте очистить выделенную динамическую память.

// 1.1. Классная армия - 1
// Теперь ваша задача - создать N пехотинцев и вывести информацию о каждом из них. Армия должна представлять из
// себя массив (вектор) указателей на пехотинцев. Не забудьте очистить выделенную динамическую память
// Формат входных данных
// С клавиатуры вводится число n – численность армии пехотинцев.
// Формат выходных данных
// Выведите информацию о каждом пехотинце армии.

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
int main(){
    //1.1-0
    // FootSoldier* fs1 = new FootSoldier();
    // FootSoldier* fs2 = new FootSoldier();
    // FootSoldier* fs3 = new FootSoldier();

    // fs1->info();
    // fs2->info();
    // fs3->info();


    
    // delete fs1;
    // delete fs2;
    // delete fs3;

    // fs3->info();

    //1.1-1

    std::vector<FootSoldier*> army;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        army.push_back(new FootSoldier());
    };

    for (FootSoldier* soldier : army){
        soldier->info();
    };

    return 0;
};
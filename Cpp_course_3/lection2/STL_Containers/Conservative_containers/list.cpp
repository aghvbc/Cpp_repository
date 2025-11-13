//двусвязный список
#include <list>
#include <iostream>

int main(){
std::list<int> l = {1, 2, 3};

l.push_front(0); // Вставка в начало

l.push_back(4); // Вставка в конец

// l[2]; // ОШИБКА! Нет оператора []

for(const auto& elem : l) std::cout << elem << " "; // Только итераторы

std::cout << "\n";

auto it = l.begin();

std::advance(it, 2); // Перемещаем итератор на 2 позиции

l.insert(it, 99); // Вставка перед элементом, на который указывает it

for(const auto& elem : l) std::cout << elem << " ";

std::cout << "\n";
};
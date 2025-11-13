#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

int main(){
    //Создание данных: Заполните std::vector<double> или std::vector<int> произвольными значениями (например, 10-20 элементов).
    std::vector<int> v {5, 1, -10, 20, -5, 2, 8, 3, 20, 0, -1};
    //Сортировка: Отсортируйте вектор по возрастанию.
    for (auto e0 : v){
        std::cout << e0 << std::endl;
    };


    std::sort(v.begin(), v.end());

    std::cout << " " << std::endl;

    //Фильтрация: Создайте новый вектор, содержащий только элементы, строго большие среднего арифметического всех элементов исходного вектора. 
    //Используйте std::copy_if (включить <algorithm>) и лямбду. Подсказка: сначала вычислите среднее значение.
   
    int av = 0; 
    for (auto e2 : v){
        av += e2;
    };
    av = av / v.size();

    std::vector<int> v2;
    std::copy_if(v.begin(), v.end(), std::back_inserter(v2), [av](int x){return x > av;});


    //Анализ: Найдите минимальное и максимальное значение в исходном векторе с помощью std::min_element и std::max_element. 
    //Выведите их и их индексы (используйте std::distance).

    std::cout << std::endl;
    auto it_min = std::min_element(v.begin(), v.end());
    std::cout << "Минимальный элемент: " <<*it_min << " " << "Индекс:  " << std::distance(v.begin(), it_min) << std::endl;

    auto it_max = std::max_element(v.begin(), v.end());
    std::cout << "Максимальный элемент: " << *it_max << " " << "Индекс: " << std::distance(v.begin(), it_max) << std::endl;

    std::cout << std::endl;

    //Трансформация: Создайте третий вектор, содержащий абсолютные значения элементов из исходного вектора (если использовали int). 
    //Используйте std::transform и лямбду [](int x) { return x < 0 ? -x : x; } или std::abs.


    std::vector<int> v3;
    std::transform(v.begin(), v.end(), std::back_inserter(v3), [](int x){return x < 0 ? -x : x;});

   

    //Вывод: Выведите исходный, отсортированный, отфильтрованный и трансформированный векторы.
    for (auto e : v){
        std::cout << e << std::endl;
    };

    std::cout << std::endl;

    for (auto e2 : v2){
        std::cout << e2 << std::endl;
    };
        std::cout << std::endl;


    for (auto e3 : v3){
        std::cout << e3 << std::endl;
    };

    std::cout << std::endl;

    //Дополнительно (на подумать/реализовать): Найдите и выведите все индексы элементов, равных максимальному значению.

    std::cout << "Доп: " << std::endl;
    int last = 0;
    std::cout << "Доп: " << std::endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it == *it_max) {
            std::cout << std::distance(v.begin(), it) << std::endl;
        }
    }


    return 0;
}

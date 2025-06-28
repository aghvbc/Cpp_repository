/*## 1. Тестовый print!

**C++ specific**  
**Шаблоны и обобщенное программирование**  
*Проверяется автоматически*  
**Ограничения:** 1 секунда, 64 МБ  

### Условие:
Вы молодой программист, владеющий языком С++, решили помочь community языка Python, а именно сделать свои тестовые функции для данного инструмента. Гвидо Ван Россум (создатель Python) дал вам тестовое задание: написать функцию `print`, которая должна принимать аргумент любого типа и возвращать его значение. Используйте обобщенные функции!

### Формат входных данных:
- В первой строке вводится тип переменной: `INT`, `DOUBLE`, `CHAR`, `STRING`
- Во второй строке – значение для вывода

### Формат выходных данных:
Строка в формате:  
`Value is <введенное_значение>`

### Примеры:
| Входные данные | Выходные данные |
|----------------|-----------------|
| `INT`<br>`4` | `Value is 4` |
| `CHAR`<br>`&` | `Value is &` |
| `DOUBLE`<br>`3.1415` | `Value is 3.1415` |
*/

#include <string>
#include <iostream>
#include <vector>

template <class T>
void print(T val){
    std::cout << "Value is " << val << std::endl;
};

template<>
void print(std::vector<int> vec){
    std::cout << "Values are: ";
    for (const auto& el : vec){
        std::cout << el << " ";
    };
    std::cout << std::endl;
};

template <class C>
void custom_max(C val1, C val2){
    C greater_value;
    
    std::cout << greater_value;
}


int main(){
    std::cout << "Chto hotim (1,2)" << std::endl;
    int choice = 0;
    std::cin >> choice;
    std::string one;
    std::cin >> one;
    if (choice = 1){ 
        if (one == "INT"){
            int two;
            std::cin >> two;
            print(two);
        } 
        else if (one == "CHAR") {
            char two;
            std::cin >> two;
            print(two);
        }
        else if (one == "DOUBLE") {
            double two;
            std::cin >> two;
            print(two);
        }
        else if (one == "STRING") {
            std::string two;
            std::cin >> two;
            print(two);
        }
        else if (one == "VECTOR") {
            int v_size = 0;
            std::cin >> v_size;
            std::vector<int> vec(v_size);
            for(int i = 0; i < v_size; ++i){
                std::cin >> vec[i];
            };

            print(vec);
        }
        else {
            std::cout << "F" << std::endl; 
        };
    };
    if (choice = 2){
        if (one == "INT"){
            int two1,two2;
            std::cin >> two1 >> two2;
            custom_max(two1,two2);
        } 
        else if (one == "DOUBLE") {
            double two1,two2;
            std::cin >> two1 >> two2;
            custom_max(two1,two2);
        }
        else if (one == "STRING") {
            std::string two1,two2;
            std::cin >> two1 >> two2;
            custom_max(two1,two2);
        }
    };

    return 0;

}
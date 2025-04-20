/*### **Задача 2: Классный таймер**

**Условие:**  
Отнаследуйте от класса `Clock` новый класс – `Timer`, позволяющий работать с таймером. Принципиальное отличие таймера от обычных часов заключается в том, что он не увеличивает время, а уменьшает.

Переопределите для этого класса метод `tick()` так, что если время обнулилось, то нужно вывести строку `"Done!"`, а само время больше не уменьшать.

**Формат входных данных:**  
В первой строке входных данных вводятся 3 целых числа `H`, `M` и `S` – часы, минуты и секунды соответственно. Гарантируется, что данные верные.  
Во второй строке вводится натуральное число `T` – количество секунд, в течение которых время должно изменяться.

**Формат выходных данных:**  
Выведите `T` строк в формате `hh:mm:ss` – время на таймере после каждой новой секунды.

**Примеры:**

**Входные данные:**
```
1 5 51
7
```

**Выходные данные:**
```
01:05:50
01:05:49
01:05:48
01:05:47
01:05:46
01:05:45
01:05:44
```

---
*/


#include <iostream>
#include <cstdio>

class Clock{
protected:
    int seconds;


public:
    Clock(int h = 0,int m = 0,int s = 0){
        seconds = h * 3600 + m * 60 + s;
    };

    void tick(){
        seconds++;
    };

    void print(){
        printf("%02d:%02d:%02d\n", getH(), getM(), getS());
    };

    int getH() {
        return seconds / 3600;
    };
    int getM() {
        return seconds % 3600 / 60;
    };
    int getS() {
        return seconds % 3600 % 60;
    };


};

class Timer: public Clock{
public:
    Timer(int h = 0,int m = 0,int s = 0): Clock( h, m, s){};

    void tick(){
        if (seconds > 0){
            seconds --;
        }
        else{
            std::cout << "Done!" << std::endl;
            exit(0);
        }
    };
};



int main(){
    int h,m,s,t;
    std::cin >> h >> m >> s >> t;

    Clock clock(h,m,s);
    Timer timer(h,m,s);

    // for (int i = 0; i < t; i++){
    //     clock.tick();
    //     clock.print();
    // };

    for (int i = 0; i < t; i++){
        timer.tick();
        timer.print();
    };

    return 0;
}
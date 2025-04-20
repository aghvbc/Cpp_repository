/*### **Задача 3: Классный секундомер**

**Условие:**  
Все мы знаем, что секундомер – это тоже в некотором смысле часы, но в отличие от обычных часов 
секундомер можно останавливать, 
а начинается он всегда с нулевой отметки.

Отнаследуйте от класса часов новый класс: `Stopwatch`, который будет реализовывать работу с секундомером. 
Добавьте в этот класс метод `void stop()`, который будет выводить на экран итоговое время, прошедшее 
от запуска секундомера в формате `"Total time: hh:mm:ss"`.

**Формат входных данных:**  
В единственной строке входных данных вводится натуральное число `T` – кол-во секунд, 
в течение которых должен работать секундомер.

**Формат выходных данных:**  
Выведите `T` строк с текущим временем на секундомере, после чего выведите строку 
с итоговым временем в формате, указанном в условии.

**Примеры:**

**Входные данные:**

```
2
```

**Выходные данные:**

```
00:00:01
00:00:02
Total time: 00:00:02
```

---
*/

#include <iostream>
#include <cstdio>

class Clock{
protected:
    int seconds;
public:
    Clock(){
        seconds = 0;
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

class Stopwatch: public Clock{
public:
    Stopwatch(){
        Clock();
    }; 

    
    void stop(){
        printf("Total time: %02d:%02d:%02d\n", getH(), getM(), getS());
    };
};

int main(){
    int h,m,s,t;
    std::cin >> t;

    Stopwatch stopwatch;

    for (int i = 0; i < t; i++){
        stopwatch.tick();
        stopwatch.print();
        
    }
    stopwatch.stop();

    return 0;
}
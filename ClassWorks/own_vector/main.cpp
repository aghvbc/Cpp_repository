#include <iostream>
#include <string>
#include <vector>

class MyVector {
private:
    int size;
    int * arr; // адрес начала массива

public:
    MyVector(int s=0, int val = 0) : size(s), arr(new int [s]) {
        for (int i = 0; i < size; i++){
            arr[i] = val;
        }
    };
    ~MyVector() {
        delete[] arr;
    };
    MyVector(const MyVector& other) { // конструктор копирования
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++){
            arr[i] = other.arr[i];
        }
    };
    
    // vec2 = vec1;
    MyVector& operator=(const MyVector& other){
        // Проверка на vec1=vec1 есть 
        //MyVector * this
        if (&other != this) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; i++){
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void print(){

        for (int i = 0; i < size; i++){
            std::cout << arr[i] << ' ';
        }
    };
    void read(){
        std::cout << "Введите " << size << "Значений." << std::endl;
        for (int i = 0; i < size; i++){
            std::cout << i+1 << ":";
            std::cin >> arr[i];
        }
    };
};
    // insert(что, куда);
    // push_back();
    // pop();

int main(){
    MyVector vec1(5);
    MyVector vec2(3);
    MyVector vec(5,-10);
    vec.print();
    vec.read();
    vec.print();

    // MyVector vvv(vec); // создание нового на базе существующего 
    // vvv.print();

    // vec = vec1 = vec2; // присваивание одного объекта другому (vec2.operator=(vec1);)
    //последовательность присваивания справа на лево (vec2 = vec1 -> результат = vec)
    //vec.operator=(vec1.operator=(vec2));

    //vec1.push_back(100).push_back(300);

    //std::cout << vvv + vec; // MyVector + MyVector 


    return 0;

}
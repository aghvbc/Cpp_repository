#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyVector {
private:
    int size; // количество элементов
    int capacity; // реальный объём выделенной памяти
    int * arr; // сырой указатель - это адрес на начало массива

public:
    // Если size=0, то в памяти будет место на 2 элемента 
    MyVector(int s=0, int val = 0) : size(s), capacity(size ? size*2 : 2), arr(new int [capacity]) {
        for (int i = 0; i < size; i++){
            arr[i] = val;
        }
    };

    ~MyVector() {
        delete[] arr;
    };

    MyVector(const MyVector& other) { // конструктор копирования
        size = other.size;
        capacity = other.capacity;
        arr = new int[capacity];
        for (int i = 0; i < size; i++){
            arr[i] = other.arr[i];
        }
    };
    
    // vec2 = vec1;
    MyVector& operator=(const MyVector& other){
        // Проверка на vec1=vec1 - есть 
        //MyVector * this
        if (&other != this) {
            delete[] this->arr;
            this->size = other.size;
            this->capacity = other.capacity;
            this->arr = new int[size];
            for (int i = 0; i < this->size; i++){
                this->arr[i] = other.arr[i];
            };
        };
        return *this; //для цепочки вызовов
    };
    
    MyVector& operator+(){

    };

   const MyVector& print() const {
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        };
        return *this;
    };

    MyVector& read(){
        if (this->size == 0){
            std::cout << "Введите размер массива -->" ;
            std::cin >> this->size;
            this->capacity = this->size*2;
            this->arr = new int [this->capacity];
        };
        std::cout << "Введите " << this->size << "значений: ";
        for (int i = 0; i < size; i++){
            std::cout << i+1 << ":";
            std::cin >> arr[i];
        };
        return *this;
    };

    void push_back(int val){
        arr[size] = val;
        size++;
        if (size == capacity){
            capacity *= 2;
            int * new_arr = new int [capacity];
            for (int i = 0; i < size; i++){
                new_arr[i] = arr[i];
            };
            delete[] arr; // освобождаем память
            arr = new_arr;
        }
    };

    void pop_back(){
        size = size ? size-1 : 0;
    };

    int size() const {
        return size;
    };

    // void insert(int val, int pos){
    //     if (pos <= size){
    //         arr[pos] = val;
    //     }
    // }

    int& operator[](int idx){
        return arr[idx];
    };

    int operator()(int start, int end){
        int sum = 0;
        for (int i = start; i < end; i++){
            sum += arr[i];
        };
        return sum;
    }

    operator std::vector<int>(){
        return std::vector(arr , arr + size);
    };


    friend std::istream& operator>>(std::istream&, MyVector&);
    friend std::ostream& operator<<(std::ostream& , const MyVector&);

};


std::istream& operator>>(std::istream& in, MyVector& v){
    if (v.size == 0){
        std::cout << "Введите количество элементов ->";
        in >> v.size;
        v.capacity = v.size * 2;
        v.arr = new int [v.capacity];
    };
    std::cout << "Введите " << v.size << " элементов ->";
    for (int i = 0; i < v.size; i++){
        in >> v.arr[i];
    };
    return in;
};

std::ostream& operator<<(std::ostream& out, const MyVector& v){
    for (int i = 0; i < v.size; i++){
        out << v.arr[i] << " ";
    };
};





    // insert(что, куда);
    // void reverse
    // void sort
    // int size() cosnt {}

int main(){
    MyVector v(100);
    // int pos = 4;
    // for (int i = pos; i < v.size(); i++){ // вроде должно работать 
    //     std::cout << v[i] << ' ';
    // };

    std::cout << v(3,24);



    // MyVector empty_vec;
    // std::cin >> empty_vec;
    // empty_vec.push_back(10000);
    // empty_vec.print();
    // std::cout << empty_vec;

    // MyVector empty_vec; //создать пустой вектор
    // empty_vec.read();  // реализовать метод считывания данных с консоли
    // MyVector vec(10); // создать вектор нужного объёма
    // vec.read();
    // vec.read().print(); // реализовать цепочку вызовов
    // vec.push_back(100); // метод добавления элемента в конец массива
    // vec.print();
    // MyVector vec2(vec); //конструктор копирования
    // vec2.pop_back(); // метод удаления последнего элемента из массива
    // vec2.print();
    // MyVector vec3(3);
    // vec.read();
    // vec3 = vec; // перегрузить операцию присваивания
    // vec3 = vec + vec2; // перегрузить операцию сложения
    
    // //вместо vec.read();
    // std::cin >> vec; // cin.operator>(MyVector & vec); -> так нельзя 
    // // void operator>>(istream)

    return 0;

}
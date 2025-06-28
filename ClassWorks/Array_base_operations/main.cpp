#include <iostream>
#include <algorithm>

using namespace std;


class Array{
    int len; // длина массива
    int* data = nullptr; // Дин.массив с числами
public:
    Array(int len) : len(len), data(new int[len]){}; // data = nullptr;
    Array(): len(0), data(nullptr){};
    ~Array() { delete[] data; };

    int length() const { return len; }; //метод для получения длины массива
    void reverse(){ // Перевернуть массив задом-наперёд   [1{0},2,3,4,5] -> [5,4,3,2,1{5}]
        int* new_data = new int[length()];

        for (int i = 0; i < length(); ++i){
            new_data[i] = data[length()-i-1];
        }; 

        delete[] data;
        data = new_data;
    };

    int max(){
        return *std::max_element(data,data+len);
    }

    friend ostream& operator<<(ostream&, const Array&);

    friend istream& operator>>(istream&, Array&);
};

std::istream& operator>>(std::istream& in, Array& ar){
    for (int i = 0; i < ar.length(); ++i){
        in >> ar.data[i];
    };
    return in;
};

std::ostream& operator<<(std::ostream& out, const Array& ar){
    for (int i = 0; i < ar.length(); ++i){
        out << ar.data[i] << " ";   
    };
    return out;
};



int main(){
    Array ar(5);
    cin >> ar;
    ar.reverse();
    cout << ar;
    std::cout << std::endl;
    std::cout << ar.max();
    std::cout << std::endl;

    return 0;
};
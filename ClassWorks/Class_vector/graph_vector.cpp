#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Vector{
public:
    int x;
    int y;
public:
    Vector(int a=0, int b=0): x(a), y(b){};

    Vector operator+(const Vector& other){
        return Vector(x+other.x, y+other.y);
    };

    Vector operator-(){
        return Vector(-x, -y);
    };

    Vector operator*(int num){
        return Vector(x * num, y * num);
    };
    
    int operator*(const Vector& other){
        return (x*other.x + y*other.y);
    };
};

ostream& operator <<(ostream& out, const Vector& other){
    out << "Вектор (" << other.x << ";" << other.y << ")" << endl;
    return out;

}

class Fraction{
private:
    int x;
    int y;
public:
    Fraction(int a=0, int b=1) : x(a), y(b){};

    void read(){ // 1/4
    char ch;
        cin >> x >> ch >> y;
    }

    void print(){
        cout << x << "/" << y << endl;
    };

    Fraction operator+(const Fraction& other){
        return Fraction(x*other.x, y*other.y);
    };

    Fraction operator-(const Fraction& other){
        auto a = lcm(y, other.y);
        return Fraction(y/a+other.y/a, a);
    };

    Fraction operator*(const Fraction& other){
        
        return Fraction();
    };
    Fraction operator/(const Fraction& other){
        
        return Fraction();
    };
    Fraction operator-(){
        
        return Fraction();
    };


};

int lcm(int a, int b) {
    return a * b / std::gcd(a, b);
};

int main(){
    Vector a(6,7);
    Vector b(-2, 4);

    std::cout << a + b << std::endl; // a.operator+(b);
    std::cout << -a << std::endl;
    cout << b*12 << endl;
    cout << a*b << endl;

    Fraction c;
    c.read(); // 5/8
    c.print(); // 5/8
    
    Fraction c1(1/4);
    Fraction c2(3/5);
    // 1/4 + 3/5 =  y/a+other.y/a /20 
    (c1+c2).print();
    (c1-c2).print();
    (c1*c2).print();
    (c1/c2).print();
    (-c2).print();

    (c1+5).print();

    (5+c1).print();

    return 0;
};
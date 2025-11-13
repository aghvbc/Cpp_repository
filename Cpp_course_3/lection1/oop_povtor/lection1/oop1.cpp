#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Shape{
public:
    virtual double area() const = 0;
    virtual void info() const = 0;
    virtual ~Shape() = default;
};

class Rectangle: public Shape{
public:
    Rectangle(int height, int width){
        if (height <= 0 || width <= 0){
            std::cout << "Error" << std::endl;
        };
        height_ = height;
        width_ = width;
    };
private:
    int width_;
    int height_;
public:
    double area() const override{
        if (width_ > 0 && height_ > 0){
            return width_ * height_;
        }
        return 0;
    };
    void info() const override{
        std::cout << "Rectangle" << std::endl;
    };

    
};

class Circle: public Shape{
public:
    Circle(int radius){

        radius_ = radius;

        if (radius <= 0){
            std::cout << "Error" << std::endl;
        };
    };
private:
    int radius_;
public:
    double area() const override{
        if (radius_ > 0){
            return M_PI * radius_ * radius_;
        };
        return 0;
    };
    void info() const override{
        std::cout << "Circle" << std::endl;
    };
};


int main(){
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5, 5));
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(3, 7));

    for (auto shape: shapes){
        shape->info();
        std::cout << "Area: " << shape->area() << std::endl;
    };

    for (auto shape: shapes){
        delete shape;
    };
    
    
    return 0;
}
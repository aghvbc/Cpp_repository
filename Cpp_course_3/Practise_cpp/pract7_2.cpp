/*Описание: Создайте иерархию классов для "фигур" (например, Shape, Circle, Rectangle), используя виртуальные функции. Храните коллекцию этих фигур в std::vector с использованием std::unique_ptr.

Требования:

    Абстрактный базовый класс Shape с виртуальным деструктором и чисто виртуальными методами double getArea() const и void draw() const.
    Производные классы Circle и Rectangle, реализующие getArea() и draw(). Каждый должен хранить свои данные (радиус, ширина/высота).
    В main:
        Создайте std::vector<std::unique_ptr<Shape>> shapes.
        Создайте несколько объектов Circle и Rectangle, упакуйте их в std::unique_ptr и добавьте в вектор (используйте std::make_unique).
        Пройдитесь по вектору и вызовите draw() и getArea() для каждого элемента (демонстрация полиморфизма).
        Обратите внимание, что std::unique_ptr автоматически управляет памятью (RAII). Нет необходимости вручную вызывать delete.*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono> 
#include <cmath>

class Shape {
public:

    virtual double getArea() const = 0;  
    virtual void draw() const = 0;       
};

// Класс Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing Circle with radius " << radius << ":\n";
        const float aspectRatio = 2.0f;
        for (int i = -radius; i <= radius; ++i) {
            for (int j = -radius * aspectRatio; j <= radius * aspectRatio; ++j) {
                float dist = std::sqrt(i * i + (j / aspectRatio) * (j / aspectRatio));
                if (std::abs(dist - radius) < 0.5)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Класс Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing Rectangle " << width << " x " << height << ":\n";
        for (int i = 0; i < static_cast<int>(height); ++i) {
            for (int j = 0; j < static_cast<int>(width); ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(10.0, 4.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Rectangle>(6.0, 3.0));

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area = " << shape->getArea() << "\n\n";
    }

    return 0;
}
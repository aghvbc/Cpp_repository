/*Описание: Создайте систему обработки документов. Используйте абстрактные классы для определения интерфейса.

Требования:

    Абстрактный базовый класс DocumentProcessor:
        Чисто виртуальный метод virtual void process(const std::string& filename) const = 0;.
        Чисто виртуальный метод virtual std::string getDescription() const = 0;.
        Виртуальный деструктор.
    Производные классы TextProcessor и ImageProcessor:
        Реализуют метод process (например, просто выводят "Processing text file: <filename>" или "Processing image file: <filename>").
        Реализуют метод getDescription (например, возвращают "Text File Processor" или "Image File Processor").

Демонстрация в main():

    Попробуйте создать объект DocumentProcessor dp; - покажите, что это невозможно, так как класс абстрактный.
    Создайте указатели DocumentProcessor* processors[2];.
    Создайте объекты TextProcessor и ImageProcessor и сохраните их адреса в массив processors.
    Пройдитесь по массиву и вызовите process("file.txt") и getDescription() для каждого процессора.*/

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
#include <numeric> 

class DocumentProcessor{
public:
    virtual void process(const std::string& filename) const = 0;
    virtual std::string getDescription() const = 0;

    virtual ~DocumentProcessor(){};

};

class TextProcessor: public DocumentProcessor{
public: 
    void process(const std::string& filename) const override {
        std::cout << "Processing text file: " << filename << std::endl;
    }
    
    std::string getDescription() const override{
        return "Text File Processor";
    }

    ~TextProcessor(){}
};

class ImageProcessor: public DocumentProcessor{
public:
    void process(const std::string& filename) const override {
        std::cout << "Processing text file: " << filename << std::endl;
    }

    std::string getDescription() const override{
        return "Text File Processor";
    }

    ~ImageProcessor(){}
};

int main() {
    //DocumentProcessor dp; //// Невозможно декларировать переменную «dp» с абстрактным типом

    DocumentProcessor* processors[2];
    processors[0] = new TextProcessor();
    processors[1] = new ImageProcessor();
    

    for (int i = 0; i < 2; ++i) {
        std::cout << "Описание: " << processors[i]->getDescription() << "\n";
        processors[i]->process("file.txt");
        std::cout << std::endl;
    };

    for (int i = 0; i < 2; ++i) {
        delete processors[i];
    };
    
    std::cout << std::endl;
    return 0;
};
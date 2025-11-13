#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>

class Data{
public:
    int value;
    Data(int val) : value(val){
        std::cout << "Конструктор" << std::endl;
    };


    ~Data(){
        std::cout << "Деструктор" << std::endl;
    };
};

void func(std::shared_ptr<Data> ptr){
    std::cout << "Внутри func: use_count = " << ptr.use_count() << std::endl;
}



int main(){
    std::shared_ptr<Data> sp1 = std::make_shared<Data>(100);
    std::cout << "После создания sp1: use_count = " << sp1.use_count() << std::endl; // 1

    auto sp2 = sp1;
    std::cout << "После присвоения sp2 = sp1:" << std::endl;

    std::cout << "sp1.use_count() = " << sp1.use_count() << std::endl; //2
    std::cout << "sp2.use_count() = " << sp2.use_count() << std::endl; //2
    // sp2 и sp1 ссылаются на один и тот же объект

    func(sp1); // 3

    std::cout << "После вызова func(sp1): use_count = " << sp1.use_count() << std::endl; // 2
    //стало два потому что одна ссылка уничтожилась
    
    // sp1 и sp2 выйдут из области видимости здесь,
    // вызовется деструктор Data, когда счетчик ссылок станет 0
    return 0;
};
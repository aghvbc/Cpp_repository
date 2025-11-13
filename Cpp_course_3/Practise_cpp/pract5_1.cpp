#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>

class ResourceGuard{
private:
    int resource_id;

public:
    ResourceGuard(int id) : resource_id(id){
        std::cout << "Acquiring resource " << id << std::endl;
    };

    ~ResourceGuard(){
        std::cout << "Releasing resource " << resource_id << std::endl;
    }
};


int main()
{
    try {
        {
            ResourceGuard rg(1);
            std::cout << "Inside block" << std::endl;

            throw std::runtime_error("Exception inside block");
        }
        std::cout << "Outside block" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }    return 0;

// При выбросе исключения после создания объекта rg управление перейдет к ближайшему обработчику исключений.
// При этом локальные объекты в блоке (rg) будут корректно уничтожены, т.е. вызовется деструктор ResourceGuard, который выведет сообщение об освобождении ресурса.
// То есть ресурс автоматически освобождается даже в случае ошибок или исключений это один из главных плюсов RAII.
}



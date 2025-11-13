#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <list>

int main(){
    std::vector<int> v{10,20,30,40,50};
    auto it = std::find(v.begin(),v.end(), 30);
    if (it != v.end()){
        std::cout << "Found 30 at index: " << std::distance(v.begin(), it) << "\n";
    }
    else{
        std::cout << "30 not found" << std::endl;
    }

    it = std::find(v.begin(),v.end(), 99);
    if (it == v.end()){
        std::cout << "99 not found" << std::endl;
    }
    else{
        std::cout << "Found 99 at index: " << std::distance(v.begin(), it) << "\n";
    }

    std::list<int> lst{10,20,30,40,50};

    auto it_list = std::find(lst.begin(),lst.end(), 30);

    if (it_list != lst.end()){
        std::cout << "Found 30 at index: " << std::distance(lst.begin(), it_list) << "\n";
    }
    else{
        std::cout << "30 not found" << std::endl;
    }

    it_list = std::find(lst.begin(),lst.end(), 99);
        if (it_list == lst.end()){
        std::cout << "99 not found" << std::endl;
    }
    else{
        std::cout << "Found 99 at index: " << std::distance(lst.begin(), it_list) << "\n";
    }
    

    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>

int main(){
    std::vector<int> v{5,2,8,1,9,3};
    std::sort(v.begin(), v.end());
    for (auto e:v){
        std::cout << e << std::endl;
    };
    std::cout << std::endl;


    std::reverse(v.begin(), v.end());
    for (auto e:v){
        std::cout << e << std::endl;
    };
    std::cout << std::endl;


    std::sort(v.begin(), v.end(), [](int a, int b){return a>b;});
    for (auto e:v){
        std::cout << e << std::endl;
    };

    std::cout << std::endl;
    return 0;
}

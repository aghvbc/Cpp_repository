#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>

int main(){
    std::vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<double> v_res(v.size());
    std::transform(v.begin(), v.end(), v_res.begin(), [](double x){return x*x;});
    for (auto e:v){
        std::cout<< e << std::endl;
    }

    std::cout << std::endl;

    for (auto e:v_res)
    {
        std::cout<< e << std::endl;
    }
    
    std::cout << std::endl;

    std::vector<double> v_back_res;

    std::transform(v.begin(), v.end(), std::back_inserter(v_back_res), [](double x){return x*x;});


    for (auto e:v_back_res)
    {
        std::cout<< e << std::endl;
    }

    std::cout << std::endl;

    return 0;
}


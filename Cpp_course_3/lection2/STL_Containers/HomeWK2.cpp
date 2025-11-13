#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>


bool isAllDigits(const std::string& str){
    for (auto ch : str){
        if (!std::isdigit(ch)){
            return false;
        }
    }
    return true;
};

int main(){
    std::string word;
    std::vector<std::string> words;
    std::map<std::string, int> freq_word;
    
    while(std::cin >> word){
        words.push_back(word);

        freq_word[word]++;
    };

    std::cout << "Total words: " << words.size() << std::endl;

    //_____

    std::set<std::string>unique_words(words.begin(), words.end());

    std::cout << "Unique words: " << unique_words.size() << std::endl;

    //_____

    std::string f_word;
    int max_count = 0;

    for (auto [e,l]: freq_word){
        if (l > max_count){
            max_count = l;
            f_word = e;
        };
    };

    std::cout << "Most frequent word: " << f_word << ", " << max_count << " " << "times" << std::endl;

    //_____

    std::vector<std::string> num_wrd;

    int cnt = words.size();
    for (int i = 0; i < cnt; ++i){
        if (isAllDigits(words[i])){
            num_wrd.push_back(words[i]);
        };
    };

    std::set<std::string> tmp(num_wrd.begin(), num_wrd.end());
    std::vector<std::string> num_wrd2(tmp.begin(), tmp.end());
    
    cnt = num_wrd2.size() - 1;
    int cnt2 = 0;
    std::cout << "Words with only digits: ";

    for (auto e : num_wrd2){
        cnt2 += 1;
        if ((e == num_wrd2[cnt]) and (cnt2 + 1 > num_wrd2.size())){
            std::cout << e;
        }
        else{
            std::cout << e << ", ";
        }
    }
    std::cout << std::endl;
    return 0;
}
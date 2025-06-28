#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
    char* string;
    int s; // число видимых символов

public:
    MyString(): s(0), string(nullptr) {};
    MyString(const char* str) {
        int s = strlen(str);
        string = new char[s + 1]; // +1 потому что в конец добавим '\0'
        strcpy(string, str); // strncpy(string, str,s);
        string[s] = '\0'; 

    };
    MyString(const MyString& str){
        s = str.s;
        string = new char[s+1];
        for (int i = 0; i < s; i++){
            string[i] = str.string[i];
        }
        string[s] = '\0';
    };

    //str1 = str2
    MyString& operator=(const MyString& other){
        if (this != &other){
            delete[] string;
            s = other.s;
            string = new char[s+1];
            for (int i = 0; i < s; i++){
                string[i] = other.string[i];
            }
            string[s] = '\0';

        };
        return *this;
    };

    char& operator[](int idx) {
        return string[idx];
    }

    int size(){
        return s;
    }

    friend istream& operator>>(istream&, MyString&);
};

istream& operator>>(istream& in, MyString& obj){
    char buffer[10000];
    in >> buffer;
    obj.s = strlen(buffer);
    delete[] obj.string;
    obj.string = new char[obj.s+1];
    strcpy(obj.string, buffer);
    obj.string[obj.s] = '\0';

    return in;
}

int main(){
    MyString str0;
    MyString str1("Hello, World!");
    MyString str2(str1); // конструктор копирования
    str0 = str1 = str2;
    str2[7] = 'w'; // и для записи и для чтения
    MyString str3 = str2;
//     cout << str2;
//     str1 = "";
//     cin >> str1;
//     cout << str1;
//     if (str2 == str1){};
// }
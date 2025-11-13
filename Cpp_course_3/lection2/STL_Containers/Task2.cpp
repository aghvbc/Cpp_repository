#include<iostream>
#include<vector>
#include<map>

void addContact(std::map<std::string, std::string>& phonebook, const std::string& name, const std::string& number){
    phonebook[name] = number;
};

bool findContact(const std::map<std::string, std::string>& phonebook, const std::string& name, std::string& number){
    auto it = phonebook.find(name);
    if (it != phonebook.end()){
        number = it->second;
        return true;
    }
    return false;
};


void printPhonebook(const std::map<std::string, std::string>& phonebook){
    std::cout << "Телефонная книга:" << std::endl;
    for (const auto& pair: phonebook){
        std::cout << pair.first << ": " << pair.second << std::endl;
    };
};


int main(){
    std::map<std::string, std::string> phonebook;
    
    addContact(phonebook, "Alice", "123-456");
    addContact(phonebook, "Bob", "789-012");
    addContact(phonebook, "Charlie", "345-678");

    std::string number;

    if (findContact(phonebook, "Bob", number)) {
        std::cout << "Найден контакт 'Bob' с номером: " << number << std::endl;
    } else {
        std::cout << "Контакт 'Bob' не найден." << std::endl;
    }

    printPhonebook(phonebook);

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>

class Book{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailble;
public:
    Book(std::string t, std::string a, std::string i): title(t), author(a), isbn(i), isAvailble(true){}

    std::string getTitle() {return title;}
    std::string getAuthor() {return author;}
    std::string getISBN() {return isbn;}
    bool getisAvaible() {return isAvailble;}

    void borrow(){ isAvailble = false;}
    void returnBook() { isAvailble = true;}
    void displayInfo(){
        std::cout << "Title: " << title << ", Author: " << author << ", Isbn: " << isbn << ", isAvaible: " << (isAvailble ? "Yes":"No") << std::endl;
    }
};

class Library{
private:
    std::vector<Book*> books;

public:
    void addBook(Book* book) {books.push_back(book);};
    void listAllBooks() const{
        for (auto el : books){
            el->displayInfo();
        };
    };
    Book *findBookByISBN(const std::string& isbn){
        for (auto book : books){
            if (book->getISBN() == isbn){
                return book;
            };
        }
        return nullptr;
    };

    bool borrowBook(const std::string& isbn){
        for (auto book : books){
            if (book->getISBN() == isbn){
                book->borrow();
                return true;
            };
        }
        return false;
    };

    bool returnBook(const std::string& isbn){
        for (auto book : books){
            if (book->getISBN() == isbn){
                book->returnBook();
                return true;
            };
        };
        return false;
    };

    ~Library(){
        for (auto book : books){
            delete book;
        }
        books.clear();
    };


    
};



int main(){
    Library lib;
    Book* b1 = new Book("1984", "George Orwell", "1234567890");
    Book* b2 = new Book("Brave New World", "Aldous Huxley", "0987654321");
    Book* b3 = new Book("Fahrenheit 451", "Ray Bradbury", "1122334455");
        
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.listAllBooks();
    std::cout << std::endl;

    lib.borrowBook("1234567890");

    lib.listAllBooks();
    std::cout << std::endl;


    lib.returnBook("1234567890");

    lib.listAllBooks();


    
    std::cout << std::endl;
    return 0;
}
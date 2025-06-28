#include <iostream>
#include <string>

// template<class T>
// class Node {
//     T val;
//     Node * next;
//     // Node * prev;
// public:
//     Node(T val): val(val), next(nullptr) {};
// };

template <class T>
class LinkedList {
private:
    struct Node { // class Node где по умолчанию всё public
        T val;
        Node * next;
        // Node * prev;
        Node(T val): val(val), next(nullptr) {};
    };

    Node * head;
    Node * tail;
public:
    LinkedList() : head(nullptr), tail(head) {};
    ~LinkedList(){
        clear();
    }
    void push_back(T val){
        Node * newNode = new Node(val);
        if (tail){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            head = tail = newNode;
        };
    };
    void clear(){
        while(head){ // 1 -- 2 -- 3; 2 -- 3; 3;
            Node * tmp = head->next;
            delete head;
            head = tmp;
        }
        head = tail = nullptr;
    };

    void print(){
        if (!head){
            std::cout << "Список пуст" << std::endl;
        }
        Node * curNode = head;
        while(curNode){
            std::cout << curNode->val << " ";
            curNode = curNode->next;
        };
        std::cout << std::endl;
    };

    void erase(int start, int count=1){
        Node * firstNode = head;
        for (int i = 0; i < start; i++){
            firstNode = firstNode->next;
        }
        Node * lastNode = firstNode;
        for (int i = 0; i < count; i++){
            lastNode = lastNode->next;
        }
        //beforeNode->next = lastNode->next;
    }

    void insert(int idx, T val){
        if (!head){
            push_back(val);
            return;
        }
        if (idx == 0){
            Node * newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node * curNode = head;
        for (int i = 0; i < idx-1; i++) curNode = curNode->next;
        
        Node * newNode = new Node(val);
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
    template <class A>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<A>& lst);
};

template<class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& lst){
    if (!lst.head){
        out << "Список пуст" << std::endl;
    }
    typename LinkedList<T>::Node * curNode = lst.head;
    while(curNode){
        out << curNode->val << " ";
        curNode = curNode->next;
    };
    out << std::endl;

    return out;
};

int main(){

    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.print(); // Выводить все элементы через пробел
    // list.erase(0,2); // индекс с которого начинается удаление и сколько удалить
    list.insert(2, 3); 
    list.print();
    list.clear();
    list.print(); // список пуст


    return 0;
}
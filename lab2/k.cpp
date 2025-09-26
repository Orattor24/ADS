#include <iostream>
using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(string data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;
    
    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(string data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(string data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                front = NULL;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front) 
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    Node* find_node(string data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }
    //Новая функция для опредления есть ли определенная дата в списке
    bool contains(string data) {
        return find_node(data) != NULL;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        LinkedList list; //выяви тут первое появление символа
        LinkedList duplicates;       // выяви есть ли дубликаты
        
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            
            // Если он впервые появился
            if (!list.contains(str) && !duplicates.contains(str)) {
                list.push_back(str);
            } 
            // если все таки появился в списке
            else if (list.contains(str)) {
                Node *toRemove = list.find_node(str);
                list.del_node(toRemove);
                // добавить дубликат в дубликат 
                if (!duplicates.contains(str)) {
                    duplicates.push_back(str);
                }
            }
            if (list.front != NULL) {
                cout << list.front->data << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }
}
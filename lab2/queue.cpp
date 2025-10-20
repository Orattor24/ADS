#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
public:
    Node *front, *tail;
    int sz;

    Queue() {
        front = tail = nullptr;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (tail == nullptr) {
            front = tail = node;
        } else {
            tail->next = node; 
            tail = node;
        }
        sz++;
    }

    void pop() {
        if (front == nullptr) {
            return; 
        }
        front = front->next;
        if (front == nullptr) {
            tail = nullptr;
        }
        sz--;
    }

    int Front() { 
        if (front != nullptr) {
            return front->data;
        }
    }

    int Tail(){
        if (front != nullptr){
            return tail->data;
        }
    }

    int size() {
        return sz;
    }

    bool empty() {
        return (sz == 0);
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();

    cout << "вперед: " << q.Front() << endl;
    cout << "Хвост: " << q.Tail();

}

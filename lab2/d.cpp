#include <iostream>
#include <utility>
#include <set>
using namespace std;

class Node {
    public:
    pair <int, int> data;
    Node *next, *prev;

    Node(pair <int, int> data) {
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

    void push_back(pair <int, int> data) {
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

    void push_front(pair <int, int> data) {
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

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data.first << " " << node->data.second << "\n";
            node = node->next;
        }
        cout << endl;
    }

    Node* find_node(pair <int, int> data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }

    void insert_node(Node *node1, pair <int, int> data) {
        Node *node = new Node(data);
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
};

int main() {
    LinkedList list;
   
    int n;
    cin >> n;
    int temp;
    int arr[n];
    set <int, greater<int>> mode;

    for(int i =0; i <n; i++){
        cin >> temp;
        arr[i] = temp;
    }
     int createst = 0;
    for(int i =0; i < n; i++){
        int kol = 0;
        for(int j =0; j<n; j++){
            if(arr[i] == arr[j]){
                kol++;
            }
        }
        list.push_back({arr[i],kol});
    }
    for(int i = 0; i < n;i++){
        if(list.front->data.second > createst){
            createst = list.front->data.second;
        }
        list.push_back(list.front->data);
        list.pop_front();
    }
    for(int i=0; i < n; i++){
        if(list.front->data.second == createst){
            mode.insert(list.front->data.first);
        }
        list.pop_front();
    }
    for (const int& s : mode) {
        cout << s << " ";
    }
    return 0;
}
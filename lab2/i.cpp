#include <bits/stdc++.h>
  
using namespace std;

class Node{
	public:
	Node * prev;
	Node * next;
	string val;
	Node(string val){
		this->prev = NULL;
		this->next = NULL;
		this->val = val;
	}	
};
class LinkedList{
	public:
	Node *head, *tail;
	
	LinkedList(){
		tail = NULL;
		head = NULL;
	}
	
	void add_back(string s){
		Node *node = new Node(s);
        if (tail == NULL) {
            tail = node;
            head = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

	}
	void add_front(string s){
		Node *node = new Node(s);
        if (head == NULL) {
            tail = node;
            head = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
	}
	bool empty(){
		return head == NULL;  
	}
	void erase_front(){
        if (head != NULL) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
        }
	}
	void erase_back(){
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                head = NULL;
        }
	}
	string front(){
		if (head != NULL) {
			return head->val;
		}
		return "";

	}
	string back(){
		if (tail != NULL) {
        return tail->val;
    	}
    	return "";
	}
	void clear(){
		Node* current = head;
    	while (current != NULL) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
		}
		head = NULL;
		tail = NULL;
	}
};
  
int main()
{
	LinkedList a;
	string s;
	while (cin >>s){


		if(s=="add_front"){
			string t;
			cin >>t;
			a.add_front(t);
			cout <<"ok"<<endl;
		}
		if(s == "add_back"){
   			string t;
   			cin >> t;
   			a.add_back(t);
   			cout << "ok" << endl;
   		}


		if(s == "erase_front"){
   			if(a.empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << a.front() << endl;
   				a.erase_front();
   			}
   		}
		if(s == "erase_back"){
   			if(a.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << a.back() << endl;
   				a.erase_back();
   			}
   		}


		if(s == "front"){
   			if(a.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << a.front() << endl;
   			}
   		}
		if(s == "back"){
   			if(a.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << a.back() << endl;
   			}
   		}


		if(s == "clear"){
   			a.clear();
   			cout << "ok" << endl;
   		}

		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
	}
    return 0;
}
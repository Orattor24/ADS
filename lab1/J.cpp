#include <iostream>
#include <deque>
using namespace std;

int main() {
    char op;
    int val;
    deque<int> dq;

    while (cin >> op && op != '!') {
        if (op == '+') {
            cin >> val;
            dq.push_front(val);
        } 
        else if (op == '-') {
            cin >> val;
            dq.push_back(val);
        } 
        else if (op == '*') {
            if (!dq.empty()) {
                if (dq.size() == 1) {
                    cout << dq.front() + dq.back() << endl;
                    dq.pop_front(); 
                } else {
                    cout << dq.front() + dq.back() << endl;
                    dq.pop_front();
                    dq.pop_back();
                }
            } else {
                cout << "error" << endl;
            }
        }
    }
}

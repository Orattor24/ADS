#include <iostream>
#include <queue>
using namespace std;


int help(queue<int> &q) {
    int num = 1;
    int val;
    while (!q.empty()){
        num ++;

        for(num; num>=0; num--){
            q.push(q.front());
            q.pop();

            // сохранить новый первый элемент
            int val = q.front();
            q.pop();

        }
    }
    
    return val;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int size;
        cin >> size;

        queue<int> q;

        // заполнить числами от 1 до size
        for (int i = 1; i <= size; i++) {
            q.push(i);
        }

        // пока очередь не пуста — применяем help и выводим
        while (!q.empty()) {
            cout << help(q) << " ";
        }
        cout << "\n";
    }

    return 0;
}

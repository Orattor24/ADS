#include <iostream>
#include <stack>
using namespace std;

int main() {
    int queue;
    cin >> queue;

    while (queue--) {
        int l, n;
        cin >> n; // количество чисел для текущей "очереди"

        stack<int> st;

        // читаем числа и кладем в стек
        for (int i = 0; i < n; i++) {
            cin >> l;
            st.push(l);
        }

        // выводим все элементы стека (в порядке сверху вниз)
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}

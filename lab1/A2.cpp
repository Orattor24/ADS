#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int num_of_tests;
    cin >> num_of_tests;
    vector<int> sizes(num_of_tests);

    while(num_of_tests--) {
        int size;
        cin >> size;
        queue<int> cards;
        vector<int> result(size); 
        int del = 1;

        for (int i = 1; i <= size; i++) {
            cards.push(i);
        }

        while (!cards.empty()) {
            for (int j = 0; j < del; j++) {
                cards.push(cards.front());
                cards.pop();
            }
            result[cards.front() - 1] = del;
            del++; 
            cards.pop();
        }

        for (int i = 0; i < size; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
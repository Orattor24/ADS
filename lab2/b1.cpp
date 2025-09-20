#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int s, b;
    cin >> s >> b;
    vector<string> con(s);
    for (int i = 0; i < s; i++) {
        cin >> con[i];
    }

    b %= s; 
    rotate(con.begin(), con.begin() + b, con.end());

    for (int i = 0; i < s; i++) {
        cout << con[i] << " ";
    }
}

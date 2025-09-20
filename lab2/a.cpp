#include <iostream>
#include <vector>
#include <cstdlib>  
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int k;
    cin >> k;

    int ind = 0;
    int distist = abs(s[0] - k);

    for (int i = 1; i < n; i++) {
        int dist = abs(s[i] - k);
        if (dist < distist) {
            distist = dist;
            ind = i;
        }
    }
    cout << ind;

}

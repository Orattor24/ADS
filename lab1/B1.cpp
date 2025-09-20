#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }
        if (st.empty()){
            res[i] = -1;
        } 
        else {
            res[i] = st.top();
        }
        st.push(a[i]);
    }

    for (int i = 0; i < n; i++) 
        {  
            cout << res[i] << " ";
        }
}

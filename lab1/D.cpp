#include <iostream>
#include <vector>

using namespace std;

bool pustoy(const string &s) {
    vector<char> st;
    for (char ch : s) {
        if (!st.empty() && st.back() == ch) {
            st.pop_back();
        } else {
            st.push_back(ch);
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if(pustoy(s)){
        cout <<"YES";
    }
    else{
        cout <<"NO";
    }
    return 0;
}
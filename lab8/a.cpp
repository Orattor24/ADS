#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

long long get_hash(string &s) {
    long long mod = 1000000007;
    long long base = 11;
    long long h = 0;
    long long p = 1;
    for (int i =0; i < s.size(); i++) {
        h = (h + (s[i] - 47) * p) % mod;
        p = (p * base) % mod;
    }
    return h;
}

int main() {
    long long n;
    cin >> n;

    vector<string> help;
    vector<long long> chisla;
    unordered_set<string> st;

    for (long long i = 0; i < n * 2; i++) {
        string str;
        cin >> str;

        long long num = 0;
        for (char c : str) {
            num = num * 10 + (c - '0');
        }
        chisla.push_back(num);
        
        help.push_back(str);
        st.insert(str);
    }

    long long count = 0;
    for (long long i = 0; i < n * 2; i++) {
        if (count == n) {
            break;
        }
        long long h = get_hash(help[i]);
        string hs = to_string(h);

        if (st.find(hs) != st.end()) {
            cout << "Hash of string \"" << help[i] << "\" is " << hs << endl;
            count++;
        }
    }
}
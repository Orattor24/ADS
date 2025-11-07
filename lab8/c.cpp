#include <iostream>
#include <vector>

using namespace std;

int get_hash(string s){
    int p = 29;
    int p_pow = 1;
    int h = 0;

    for(int i =0; i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *=p;
    }

    return h;
}

vector <int> get_h(string s){
    int n = s.size();
    vector <int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;

    for(int i = 1 ; i < n; i++){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *=p;
    }
    return h;
}

int main(){
    string s1;
    cin >> s1;

    string copye;
    for(char c : s1){
        copye.push_back('#');
    }

    int q;
    cin >> q;

    vector <string> words;

    for(int i = 0 ; i < q; i++){
        string text;
        cin >> text;
        words.push_back(text);
    }

    vector <int> p(s1.size());
    p[0] = 1;

    for(int i = 1; i < s1.size(); i++){
        p[i] = p[i-1] * 29;
    }

    for(int k =0; k < words.size(); k++){
        string help = words[k];
        int hash_2 = get_hash(help);

        vector <int> h = get_h(s1);

        int n = s1.size();
        int m = words[k].size();

        for(int i = 0; i < n-m + 1; i++){
            int j = i+m-1;

            int hash = h[j];
            if(i > 0){
                hash = hash - h [i-1];
            }

            if(hash == hash_2*p[i]){
                copye.replace(i, help.size(), help);
            }
        }
    }
    if(copye == s1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
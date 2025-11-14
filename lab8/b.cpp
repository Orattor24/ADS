#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_hash(string s) {
    int p = 29;
    int p_pow = 1;  
    int h = 0;

    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
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
    vector <int> res;
    map <int,int> result;
    string s1, s12, s2;

    cin >> s1>> s12>> s2;

    vector <int> p(s1.size());
    p[0] = 1;
    
    vector <int> p1(s12.size());
    p1[0] = 1;

    for(int i = 1; i < s1.size(); i++){
        p[i] = p[i-1] * 29;
    }
    for(int i = 1; i < s12.size(); i++){
        p1[i] = p1[i-1] * 29;
    }
    int h_s2 = get_hash(s2);

    vector <int> h = get_h(s1);
    vector <int> h1 = get_h(s12);

    int n = s1.size();
    int n1 = s12.size();
    int m = s2.size();

    for(int i = 0; i < n-m + 1; i++){
        int j = i+m-1;

        int hash = h[j];
        if(i > 0){
            hash = hash - h [i-1];
        }

        if(hash == h_s2*p[i]){
            result[i]++;
        }
    }
    for(int i = 0; i < n1-m + 1; i++){
        int j = i+m-1;

        int hash = h1[j];
        if(i > 0){
            hash = hash - h1 [i-1];
        }

        if(hash == h_s2*p1[i]){            
            result[i]++;
        }
    }

    for(auto i : result){
        if(i.second %2 ==0){
            res.push_back(i.second);
        }
    }
    cout << res.size();
}
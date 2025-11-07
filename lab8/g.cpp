#include <iostream>
#include <string>
#include <vector>


using namespace std;

//вычисли хэш всей строки
int has(string &s){
    int p = 29;
    int p_pow = 1; 
    int h = 0;

    for(int i = 0; i < s.size(); i++){
        h += s[i] * p_pow;
        //переводит строку в систему чисел. а п после увеличивается каждый раз
        p_pow *= p;
    }

    return h;
}

// вычисли префикс хэша массива
vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main(){
    //Основная фигня 
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector<int> p(s.size());
    p[0] = 1;
    for(int i = 1; i < s.size(); i++){
        p[i] = p[i-1]*29;
    }

    // ищем какие буквы хотим найти
    for(int i =0; i < q; i++){
        int l, r;
        cin >> l >> r;
        string sub = s.substr(l-1, r-l+1);
        int q_hash = has(sub);
        vector<int> h = get_h(s);
        int n = s.size();
        int m = sub.size();
        vector <int> res;

        for(int j = 0; j < n-m+1; j++){
            int k = j + m -1;

            int hash = h[k];

            if(j > 0){
                hash = hash - h[j-1];
            }

            if(hash == q_hash * p[j]){
                res.push_back(i);
            }
        }
        cout << res.size() << endl;
    }
}
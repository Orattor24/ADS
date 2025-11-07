#include <iostream>
#include <string>
#include <vector>

using namespace std;

int has(string &s){
    int p = 29;
    int p_pow = 1;
    int h = 0 ;

    for(int i = 0 ; i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}
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
    int n;
    while(cin >> n and n !=0){
        vector <string> sub;
        vector <int> sub_hash;

        for(int i = 0; i < n; i++){
            string str_sub;
            cin >> str_sub;

            int ha = has(str_sub);
            sub_hash.push_back(ha);
            sub.push_back(str_sub);
        }

        string text;
        cin >> text;

        vector <int> p(text.size());
        p[0] = 1;
        for(int i = 1; i < text.size(); i++){
            p[i] = p[i-1] *29;
        }

        vector <int> text_hash = get_h(text);
        int text_size = text.size();

        vector <int> tekuchiy_schot(n, 0);
        int maximum = 0;

        for(int i =0; i < n; i++){
            int m = sub[i].size();
            int count  = 0;

            for(int j = 0; j < text_size - m +1; j++){
                int k = j+m-1;

                int hash = text_hash[k];

                if(j > 0){
                    hash = hash - text_hash[j-1];
                }

                if(hash == sub_hash[i] * p[j]){
                    count ++;
                }

            }

            tekuchiy_schot[i] = count;
            if(count > maximum){
                maximum = count;
            }
        }

        cout << maximum << endl;
        for(int i = 0; i < n; i++){
            if(tekuchiy_schot[i] == maximum){
                cout << sub[i] << endl;
            }
        }
    }
}
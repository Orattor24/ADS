#include <iostream>
#include <vector>

using namespace std;

vector <int> help(string text, string pattern){
    vector <int> pos;

    int n = text.length();
    int m = pattern.length();

    if(n < m){
        return pos;
    }

    
    int text_h = 0;
    int pattern_h = 0;
    int p = 29;
    int p_pow = 1;

    for(int i =0; i < m; i++){
        pattern_h = pattern_h * p + (pattern[i] - 'a' +1);
        text_h = text_h * p + (text[i] - 'a' +1);

        if(i < m-1){
            p_pow *= p;
        }
    }

    if(text_h == pattern_h){
        pos.push_back(0);
    }

    for(int i = m; i < n; i++){
        text_h -= (text[i-m] - 'a' +1) * p_pow;

        text_h = text_h * p + (text[i] - 'a' +1);

        if(text_h == pattern_h){
            pos.push_back(i-m+1);
        }
    }
    return pos;
}

int main(){
    string n1, n2, chort;

    cin >> n1 >> n2 >> chort;

    vector <int> pos1 = help(n1, chort);
    vector <int> pos2 = help(n2, chort);

    int count = 0;
    int i= 0;
    int j = 0;

    while(i < pos1.size() and j < pos2.size()){
        if(pos1[i] == pos2[j]){
            count++;
            i++;
            j++;
        }
        else if(pos1[i] < pos2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    cout << count;
}
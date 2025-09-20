#include <iostream>
#include <vector>

using namespace std;

int main(){
    int s, b;
    cin >> s >> b;
    vector <string> con (s);
    for(int i = 0; i < s; i++){
        cin >> con[i];
    }
    for (int i = 0; i < b; i++) {
        string first = con.front();   
        con.erase(con.begin());     
        con.push_back(first);      
    }
    for(int i = 0; i < s; i++){
        cout << con[i] << " ";
    }
}
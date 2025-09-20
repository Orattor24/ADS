#include <iostream>
#include <stack>

using namespace std;
string help(string &s){
    string heeeelp;
    for(char ch : s){
        if(ch =='#'){
            if(!heeeelp.empty()){
                heeeelp.pop_back();
            }
        } 
        else{
            heeeelp.push_back(ch);
        }
    }
    return heeeelp;
}

int main(){
    string a;
    string b;

    cin >> a >> b;

    if (help(a) == help(b)){
        cout <<"Yes"<< endl;
    }
    else{
        cout <<"No"<< endl;
    }
}
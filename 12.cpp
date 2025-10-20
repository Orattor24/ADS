#include <iostream>
#include <vector>

using namespace std;

vector <int> sieve(int n){
    vector <bool> prime(n+1, true);
    for(int i=2; i*i <=n; i++){
        if(prime[i]){
            for(int p = i*i; p <= n; p+=i){
                prime[p] = false;
            }
        }
    } 
    vector<int> res;

    for(int p = 2; p <=n; p++){
        if(prime[p]){
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    vector<int> res = sieve(10000);

    for(int c : res){
        cout << c << " ";
    }
}
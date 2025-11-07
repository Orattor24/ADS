#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long hash(string& s) {
    long long hash_val = 0;
    long long power_of_2 = 1;
    
    for (int i = 0; i < s.length(); i++) {
        hash_val += (s[i] - 97) * power_of_2;
        power_of_2 *= 2;  
    }
    return hash_val;
}

int main() {
    int n;
    cin  >>n;
    vector <long long> hashes(n);

    for(int i = 0; i < n; i++){
        cin >> hashes[i];
    }

    string result = "";
    
    for(int i =0; i < n; i++){
        if(i  ==0){
            long long code = hashes[0];
            result += char(code + 97);
        }

        else{
            long long raznitsa = hashes[i] - hashes[i-1];
            long long p_2 = pow(2, i);
            
            long long code = raznitsa/p_2;
            result += char(code +97);
        }
    }
            cout << result;
}
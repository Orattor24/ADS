#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;   
    int num = 2;          

    while ((int)primes.size() < 1000) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }
    vector <int> super_prime;
    for(int i = 0; i< (int)primes.size(); i++){
        int index = i+1;
        if(isPrime(index)){
            super_prime.push_back(primes[i]);
        }
    }
    cout << super_prime[n-1] << endl;  
    return 0;
}

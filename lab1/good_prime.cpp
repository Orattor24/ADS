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

    while ((int)primes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }

    cout << primes.back() << endl;  
    return 0;
}

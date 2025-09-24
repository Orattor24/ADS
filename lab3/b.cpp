#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


bool canSplit(const vector<long long>& a, long long maxSum, long long k) {
    long long sector = 1; 
    long long currentSum = 0;
    
    for (long long x : a) {
       
        if (currentSum + x > maxSum) {
            sector++;
            currentSum = x;
            if (sector > k) {
                return false;
            }
        } else {
            currentSum += x;
        }
    }
    return sector <= k;
}

long long findMinMaxsum(const vector<long long>&a, long long k){
   long long left = *max_element(a.begin(), a.end());
    //long long left =0;
    long long right = accumulate(a.begin(),a.end(), 0LL);
    
    while(left <right){
        long long mid = left +(right-left)/2;

        if(canSplit(a, mid, k)){
            right =mid;
        } else{
            left = mid+1;
        }
    }
    return left;
}

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for(long long i=0; i<n; i++){
        cin >> a[i];
    }

    long long result = findMinMaxsum(a,k);

    cout << result;

}



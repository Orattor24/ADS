#include <iostream>
#include <vector>
using namespace std;

long long which_block(const vector<long long>& prefix_sum, long long mistake) {
    long long current = 1;
    int l=1;
    int r = prefix_sum.size()-1;

    while(l<=r){
        int mid = (r+l)/2;

        if(mistake<=prefix_sum[mid]){
            if(mid ==0 or mistake > prefix_sum[mid-1]){
                return mid+1;
            }
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    return l; 
}

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<long long> blocks(N);
    vector<long long> prefix_sum(N);
    for (long long i = 0; i < N; i++) {
        cin >> blocks[i];
        if(i==0){
            prefix_sum[i]=blocks[i];
        } else{
            prefix_sum[i]=prefix_sum[i-1]+blocks[i];
        }
    }
    
    for (long long i = 0; i < M; i++) {
        long long mistake;
        cin >> mistake;
        cout << which_block(prefix_sum, mistake) << endl;
    }

}
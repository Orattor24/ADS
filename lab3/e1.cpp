#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_max_kolvo_dereva(vector<int> a, int k){
    int left = 0;
    int right = a.size()-1;
    while(left < right){
        int mid = (right+left)/2;
        if (mid == k){
            return a[mid-1];
            left = mid +1;
        } 
        else{
            right = mid -1;
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> max_cordinaty(N); 
    
    for(int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        max_cordinaty[i] = max(x2, y2); 
    }

    sort(max_cordinaty.begin(), max_cordinaty.end());
    
    cout << min_max_kolvo_dereva(max_cordinaty, K) << endl;
}
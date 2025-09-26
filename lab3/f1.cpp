#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& fight, int target) {
    int left = 0;
    int right = fight.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = (right + left) / 2;
        
        if (fight[mid] <= target) {
            result = mid; 
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }
    
    return result; 
};

int main() {
    
    int N;
    cin >> N;
    
    vector<int> sila_vraga(N);
    for (int i = 0; i < N; i++) {
        cin >> sila_vraga[i];
    }
    

    sort(sila_vraga.begin(), sila_vraga.end());
    
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + sila_vraga[i];
    }
    
    int P;
    cin >> P;
    
    for (int i = 0; i < P; i++) {
        int sila_marl;
        cin >> sila_marl;
        
        int last_index = binarySearch(sila_vraga, sila_marl);
        
        int count = last_index + 1; 
        long long sum = prefix_sum[count];
        
        cout << count << " " << sum << endl;
    }
}
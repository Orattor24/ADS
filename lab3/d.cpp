#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_in_range_binary(const vector<int>& arr, int l, int r) {
    int left = 0, right = arr.size() - 1;
    
    int first_index = arr.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= l) {
            first_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    left = 0, right = arr.size() - 1;
    int last_index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= r) {
            last_index = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (first_index > last_index) return 0;
    return last_index - first_index + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int count1 = count_in_range_binary(a, l1, r1);
        int count2 = count_in_range_binary(a, l2, r2);
        
        int intersection_l = max(l1, l2);
        int intersection_r = min(r1, r2);
        
        if (intersection_l <= intersection_r) {
            int intersection_count = count_in_range_binary(a, intersection_l, intersection_r);
            cout << count1 + count2 - intersection_count << "\n";
        } else {
            cout << count1 + count2 << "\n";
        }
    }
}
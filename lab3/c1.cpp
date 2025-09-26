#include <iostream>
#include <vector>
using namespace std;


bool binary_search(int l, int r, int x) {
    int left = l, right = r;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == x) return true;
        else if (mid < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
int main() {

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    vector<int> num_of_indeces(q);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        for (int j = 0; j <= n; j++) {
            if (binary_search(l1, r1, nums[j])){
                num_of_indeces[i] += 1;
                continue;
            }
            if (binary_search(l2, r2, nums[j])){
                num_of_indeces[i] += 1;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << num_of_indeces[i] << endl;
    }
}
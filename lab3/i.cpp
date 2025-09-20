#include <iostream>
#include <vector>
using namespace std;

int binary_search_exact(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;  
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0;i <n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int x;
    cin >> x;
    int idx = binary_search_exact(a, x);
    cout << (idx != -1 ? "Yes" : "No");
    return 0;
}
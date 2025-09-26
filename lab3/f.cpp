#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int binary_search(vector<int> nums, int x) {
    int left = 0, right = nums.size();
    int sum = 0;

    while (left < right) {
        int mid = (right - left) / 2;
        if (nums[mid] == x) right = mid;
        else if (nums[mid] > x) right = mid - 1;
        else left = mid + 1;
        //cout << left << " " << right << " " << nums[mid] << endl;
    }

    for(int i = 0; i < right; i++) {
        sum += nums[i];
    }
    return sum;
}
int main() {

    int n, p; // p - round number
    int temp;
    cin >> n;

    vector<int> opponents_power(n);
    
    map<int, int> wins;
    for (int i = 0; i < n; i++) {
        cin >> opponents_power[i];
    }

    sort(opponents_power.begin(), opponents_power.end());

    cin >> p;
    vector<int> mark_power(p);

    for (int i = 0; i < p; i++) {
        cin >> temp;
        mark_power[i] = temp;
    }

    for (int i = 0; i < p; i++) {
        cout << binary_search(opponents_power, mark_power[i]) << endl;
        // if (binary_search(0, p - 1, opponents_power[i])) {
        //     wins[opponents_power[i]] += 1;
        // }
    }
}
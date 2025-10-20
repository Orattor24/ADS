#include <iostream>
#include <vector>

using namespace std;

int BS(vector<int> a, int x){
    int l = 0; int r = a.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            l = mid+1;
        }
        else if(a[mid] > x){
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0; i < n; i++){
        int s;
        cin >> s;
        a.push_back(s);
    }

    int search;
    cin >> search;

    cout << BS(a, search);
}
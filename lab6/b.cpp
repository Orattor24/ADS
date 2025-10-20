#include <iostream>
#include <vector>

using namespace std;

int a[1000];
int b[1000];

void quick_sort(int arr[], int l, int r){
    int p = arr[ (l + r) / 2 ];
    int i = l;
    int j = r;

    while(i<=j){


        while(arr[i] < p){
            i++;
        }
        while(arr[j] > p ){
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if(l < j){
        quick_sort(arr, l, j);
    }
    if(i<r){
        quick_sort(arr, i, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i< n; i++){
        cin >> a[i];
    }

    for(int i = 0; i< m; i++){
        cin >> b[i];
    }
    if(n > 0){
        quick_sort(a, 0, n-1);
    }
    if(m > 0){
        quick_sort(b, 0, m-1);
    }
    
    vector<int> result;
    int i =0, j = 0;
    
    while (i < n and j < m){
        if(a[i] == b[j]){
            result.push_back(a[i]);
            j++;
            i++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for(int ja = 0; ja < result.size(); ja++){
        cout << result[ja] << " ";
    }
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
void quick_sort(int l, int r){
    int p = a[ (l + r) / 2 ];
    int i = l;
    int j = r;

    while(i<j){


        while(a[i] < p){
            i++;
        }
        while(a[j] > p ){
            j--;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(l < j){
        quick_sort(l, j);
    }
    if(i<r){
        quick_sort(i, r);
    }
}

int main(){
    int shir, dlin;
    cin >> shir >> dlin;
    int n = shir * dlin;


    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    quick_sort(0, n-1);

    for(int i=0; i < shir; i++){
        for(int j = 0; j <  dlin; j++){
            cout << a[j] << " ";
        }
        cout << endl;
        
    }
}
#include <iostream>
#include <vector>

using namespace std;

int a[1000][1000];
int temp[1000];

void quick_sort(int l, int r){
    int p = temp[ (l + r) / 2 ];
    int i = l;
    int j = r;

    while(i<=j){


        while(temp[i] < p){
            i++;
        }
        while(temp[j] > p ){
            j--;
        }

        if (i <= j) {
            swap(temp[i], temp[j]);

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

    for(int i=0; i < shir; i++){
        for(int j = 0; j < dlin ; j++){
            cin >> a[i][j];
        }
    }

   for(int col = 0; col < dlin; col++){
    for(int row = 0; row < shir; row++){
        temp[row] = a[row][col];
    }

    quick_sort(0, shir - 1);

    for(int row = 0; row < shir; row++){
        a[row][col] = temp[shir - 1 - row];
    }
}



    for(int i=0; i < shir; i++){
        for(int j = 0; j <  dlin; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
        
    }
}
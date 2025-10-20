#include <iostream>
#include <vector>

using namespace std;

int a[1000];

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

void printArray(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        char pr;
        cin >> pr;
        int asci = static_cast<int>(pr);
        a[i] = asci;
    }

    quick_sort(0, n-1);

    char pr;
    cin >> pr;
    int asci = static_cast<int>(pr);
    int res;
    for(int i=0; i < n; i++){
        if(asci < a[i] and asci != a[n-1]){
            res = a[i];
            break;
        }
        else{
            res = a[0];
        }
        
    }

    char ascci = static_cast<char>(res);
    cout << ascci << " ";

    /*vector<int> abc;
    for(int i; i < n; i++){
        char pr;
        cin >> pr;
        int asci = static_cast<int>(pr);
        abc.push_back(asci);
    }

    for(int i=0; i < abc.size() -1; i++){
        a[i] = abc[i];
    }
    quick_sort(0, n-1);

    printArray(abc);
    vector <char> abc_abc;
    for(char c : abc){
            int asci = static_cast<char>(c);
            abc_abc.push_back(asci);
    }

    //printArray(abc);
    for(char c : abc_abc){
        cout << c;
    }*/
}
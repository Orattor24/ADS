#include <iostream>
#include <vector>

using namespace std;

string new_password[1000];
string new_login[1000];
string login[1000];
string password[1000];
string cur[1000];
string orig[1000];
int arr[1000];

void quick_sort(int arr[], int l, int r){
    int p = arr[(l + r) / 2 ];
    int i = l;
    int j = r;

    while(i <= j){

        while(new_login[arr[i]] < new_login[p]) {

        i++;

    }
        while(new_login[arr[j]] > new_login[p]) 

        {
            j--;
        }

        if(i <= j){
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
    int n;
    cin >> n;

    int hack =0;

    for(int i=0; i< n; i++){
        cin >> login[i] >> password[i];

    }

    for(int i=0; i< n;i ++){
        string a = login[i];
        string b = password[i];
        int found = -1;
        for(int j=0;j<hack;j++){
            if(cur[j] == a){
                found = j;
                break;
            }
        }
        if(found != -1){
            cur[found] = b;
            new_password[found] = b;
        }else{
            orig[hack] = a;
            cur[hack] = b;
            new_login[hack] = a;
            new_password[hack] = b;
            hack++;
        }
    }
    for(int i=0;i<hack;i++) {
        arr[i] = i;
    }

    quick_sort(arr, 0, hack-1);

    cout << hack << endl;
    for(int i=0;i<hack;i++){
        cout << new_login[arr[i]] << " " << new_password[arr[i]] << endl;
    }
}
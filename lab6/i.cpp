#include <iostream>
#include <vector>

using namespace std;

int a[1000];

void quick_sort(int l, int r) {
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) {
        quick_sort(l, j);
    }
    if (i < r) {
        quick_sort(i, r);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


int main(){
    string pr;
    cin >> pr;
    vector<int> abc;
   
    for(char c : pr){
        int asci = static_cast<int>(c);
        abc.push_back(asci);
    }

    for(int i = 0; i < abc.size(); i++){
        a[i] = abc[i];
    }

    quick_sort(0 , abc.size()-1);
    vector<char> res(pr.size());
    for(int i = 0; i < pr.size(); i++){
        res[i] = static_cast<char>(a[i]);
    }

    for(char c : res){
        cout << c;
    }
}
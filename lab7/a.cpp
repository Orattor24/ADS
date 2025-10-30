#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;      

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;    
    int j = 0;     
    int k = left;  

    while (i < n1 && j < n2) {
        if (L[i].length() <= R[j].length()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(vector<string>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if(i != arr.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for(int i =0; i < n; i ++){
        string text;
        getline(cin, text);

        vector <string> help;
        stringstream ss(text);
        string x="";

        while(ss >> x) {
            help.push_back(x);
        }

        if(!help.empty()) {
            mergeSort(help, 0, help.size() - 1);
        }

        for(int j = 0; j < help.size(); j++) {
            cout << help[j] << " ";
        }
        cout << endl;
    }
}
    
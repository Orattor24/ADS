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
    int n;
    cin >> n;

    string pr;

    cin >> pr;
    vector<int> vowel;
    vector<int> consonants;
    if(pr.size() == n){
        for(char c : pr){
            int asci = static_cast<int>(c);
            if(asci == 97 or asci == 101 or asci == 105 or asci == 111 or asci == 117){
                vowel.push_back(asci);
            }
            else{
                consonants.push_back(asci);
            }

        }
    }
    else{
        cout << "none";
    }

    for(int i =0; i < vowel.size(); i++){
        a[i] = (vowel[i]);
    }
    quick_sort(0, vowel.size()-1);
    for(int i = 0; i < vowel.size(); i++){
        vowel[i] = a[i];
    }


    for(int i=0; i < consonants.size(); i++){
        a[i] = consonants[i];
    }
    quick_sort(0, consonants.size()-1);
    for(int i = 0; i < consonants.size(); i++){
        consonants[i] = a[i];
    }



     vector<int> abc;
    for (int i = 0; i < vowel.size(); i++) {
        abc.push_back(vowel[i]);
    }
    for (int i = 0; i < consonants.size(); i++) {
        abc.push_back(consonants[i]);
    }

    for (int num : abc) {
        cout << static_cast<char>(num);
    }
}
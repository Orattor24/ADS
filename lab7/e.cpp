#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;

void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        int sumL = 0, sumR = 0;
        for (int num : L[i]) {
            sumL += num;
        }
        for (int num : R[j]) {
            sumR += num;
        }
        
        bool zachem = false;
        
        if (sumL < sumR) {
            zachem = true;
        } else if (sumL == sumR) {
            for (int ja = 0; ja < L[i].size(); ja++) {
                if (L[i][ja] > R[j][ja]) {
                    zachem = true;
                    break;
                } else if (L[i][ja] < R[j][ja]) {
                    break;
                }
            }
        }
        
        if (zachem) {
            a[k] = R[j];
            j++;
        } else {
            a[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    a.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    mergeSort(0, n - 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays arr[left...mid] and arr[mid+1...right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;      // Size of right subarray

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = left;  // Initial index of merged array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);

    for(int i = 0; i< n; i++){
        cin >> a[i];
    }

    for(int i = 0; i< m; i++){
        cin >> b[i];
    }
    if(n > 0){
        mergeSort(a, 0, n-1);
    }
    if(m > 0){
        mergeSort(b, 0, m-1);
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
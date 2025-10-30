#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double a[1000005];
string second_name[1000005];
string first_name[1000005];

// Merge two sorted subarrays arr[left...mid] and arr[mid+1...right]
void merge(int l, int mid, int r) {
    int n1 = mid - l + 1;  // Size of left subarray
    int n2 = r - mid;      // Size of right subarray

    // Create temporary arrays
    vector<double> L_a(a + l, a + mid + 1);
    vector<double> R_a(a + mid + 1, a + r + 1);
    vector<string> L_second(second_name + l, second_name + mid + 1);
    vector<string> R_second(second_name + mid + 1, second_name + r + 1);
    vector<string> L_first(first_name + l, first_name + mid + 1);
    vector<string> R_first(first_name + mid + 1, first_name + r + 1);

    // Merge the temporary arrays back
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = l;  // Initial index of merged array

      while (i < n1 && j < n2) {
        if (L_a[i] < R_a[j] || 
            (L_a[i] == R_a[j] && (L_second[i] < R_second[j] || 
            (L_second[i] == R_second[j] && L_first[i] < R_first[j])))) {
            a[k] = L_a[i];
            second_name[k] = L_second[i];
            first_name[k] = L_first[i];
            i++;
        } else {
            a[k] = R_a[j];
            second_name[k] = R_second[j];
            first_name[k] = R_first[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = L_a[i];
        second_name[k] = L_second[i];
        first_name[k] = L_first[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = R_a[j];
        second_name[k] = R_second[j];
        first_name[k] = R_first[j];
        j++;
        k++;
    }
}

// Main merge sort function
void mergeSort(int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

void printArray(vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> second_name[i] >> first_name[i];

        int m;
        cin >> m;

        double sum = 0;
        int pomogite = 0;

        for(int j = 0; j < m; j++){
            string ball;
            int chislo;
            cin >> ball >> chislo;  
            pomogite += chislo;

            if(ball == "A+"){
                sum += 4 * chislo;
            }
            else if(ball == "A"){
                sum += 3.75 * chislo;
            }
            else if(ball == "B+"){
                sum += 3.50 * chislo;
            }
            else if(ball == "B"){
                sum += 3.00 * chislo;
            }
            else if(ball == "C+"){
                sum += 2.50 * chislo;
            }
            else if(ball == "C"){
                sum += 2.00 * chislo;
            }
            else if(ball == "D+"){
                sum += 1.5 * chislo;
            }
            else if(ball == "D"){
                sum += 1.00 * chislo;
            }
            else if(ball == "F"){
                sum += 0 * chislo;
            }
        }

        a[i] = sum / pomogite;
    }

    mergeSort(0, n-1);

    for(int i = 0; i < n; i++){
        cout << second_name[i] << " " << first_name[i] << " ";
        cout << fixed << setprecision(3) << a[i] << endl;
    }
}
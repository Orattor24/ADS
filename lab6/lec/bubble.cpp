#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();

    for(int i=0; i < n-1; i++){
        bool swapped = false;

        for (int j=0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        //283 1 8 4 7 26 9 5 73
        /*i = 0; j=0 arr[0] = 283 > arr[1+1] = 1
        j[1] =283 > j[2] = 8 
        */
        if(!swapped){
            break;
        }
    }
}


void printArray(vector<int>& arr){
    for(int num:arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {64,34,25,12,22,11,90};

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    cout <<"Sorted array: ";
    printArray(arr);

    return 0;
}
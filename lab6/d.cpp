#include <iostream>
#include <vector>

using namespace std;

int day[10000];
int month[10000];
int year[10000];

void quick_sort(int l, int r){
    int p = (l + r) / 2;
    int year_same = year[p];
    int month_same = month[p];
    int day_same = day[p];

    int i = l;
    int j = r;

    while(i<=j){
        while (year[i] < year_same or (year[i] == year_same and month[i] < month_same) or (year[i] == year_same and month[i] == month_same and day[i] < day_same)) {
            i++;
        }
        
    
        while (year[j] > year_same or (year[j] == year_same and month[j] > month_same) or (year[j] == year_same and month[j] == month_same and day[j] > day_same)) {
            j--;
        }

        if (i <= j) {
            swap(year[i], year[j]);
            swap(month[i], month[j]);
            swap(day[i], day[j]);
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
    int n;
    cin >> n;
    string data;

    for(int i =0; i < n; i++){
        cin >> data;
        day[i] = stoi(data.substr(0,2));
        month[i] = stoi(data.substr(3 , 2));
        year[i] = stoi(data.substr(6, 4));    
    }
    quick_sort(0, n-1);
    for(int i = 0; i < n; i++) {
        if (day[i] < 10) cout << '0';
        cout << day[i] << '-';
        if (month[i] < 10) cout << '0';
        cout << month[i] << '-' << year[i] << endl;
    }
}
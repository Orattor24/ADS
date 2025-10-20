#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double a[1000005];
string second_name[1000005];
string first_name[1000005];

int gpa(){
    int sum = 0;
    int offset =0;
};
void quick_sort(int l, int r){


    int i = l;
    int j = r;
    double p = a[(l + r) / 2];
    string p_second = second_name[(l + r) / 2];
    string p_first = first_name[(l + r) / 2];


    while (i <= j){
        while (a[i] < p || (a[i] == p && (second_name[i] < p_second || (second_name[i] == p_second && first_name[i] < p_first)))) {
            i++;
        }
        while (a[j] > p || (a[j] == p && (second_name[j] > p_second || (second_name[j] == p_second && first_name[j] > p_first)))) {
            j--;
        }
        if (i <= j){
            swap(a[i], a[j]);
            swap(second_name[i], second_name[j]);
            swap(first_name[i], first_name[j]);
            i++;
            j--;
        }
    }

    if (j - l < r - i) {
        if(l < j) quick_sort(l, j);
        if(i < r) quick_sort(i, r);
    } else {
        if(i < r) quick_sort(i, r);
        if(l < j) quick_sort(l, j);
    }
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

    quick_sort(0, n-1);

    for(int i = 0; i < n; i++){
        cout << second_name[i] << " " << first_name[i] << " ";
        cout << fixed << setprecision(3) << a[i] << endl;
    }
}
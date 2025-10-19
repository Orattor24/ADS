#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float a[100000];
string second_name[100000];
string first_name[100000];

int gpa(){
    int sum = 0;
    int offset =0;
};

void quick_sort(int l, int r){
    float p = a[ (l + r) / 2 ];
    string p_second = second_name[(l+r)/2];
    string p_first = first_name[(l+r)/2];

    int i = l;
    int j = r;

    while(i<=j){


        while(a[i] < p or (a[i] == p and second_name[i] < p_second) or (a[i] == p and second_name[i] == p_second and first_name[i] < p_first)) {
            i++;
        }
         while(a[j] > p or (a[j] == p and second_name[j] > p_second) or (a[j] == p and second_name[j] == p_second and first_name[j] > p_first)) {
            j--;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            swap(second_name[i], second_name[j]);
            swap(first_name[i], first_name[j]);
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

    for(int i = 0; i < n; i++){
        cin >> second_name[i] >> first_name[i];

        int m;
        cin >> m;

        float sum = 0;
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
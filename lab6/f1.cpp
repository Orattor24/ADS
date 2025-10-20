#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float a[1000];
string second_name[1000];
string first_name[1000];

void quick_sort(int l, int r){
    float p = a[(l + r) / 2];
    int i = l;
    int j = r;

    while(i <= j){
        while(a[i] < p){
            i++;
        }
        while(a[j] > p){
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
    if(i < r){
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
        int total_credits = 0;

        cout << "DEBUG: Student " << second_name[i] << " " << first_name[i] << " has " << m << " subjects" << endl;

        for(int j = 0; j < m; j++){
            string ball;
            int chislo;
            cin >> ball >> chislo;
            
            cout << "DEBUG: " << ball << " " << chislo << endl;

            total_credits += chislo;

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

        cout << "DEBUG: total_credits=" << total_credits << ", sum=" << sum << endl;
        
        if(total_credits > 0) {
            a[i] = sum / total_credits;
        } else {
            a[i] = 0;
        }
        
        cout << "DEBUG: GPA=" << a[i] << endl;
    }

    quick_sort(0, n-1);

    for(int i = 0; i < n; i++){
        cout << second_name[i] << " " << first_name[i] << " ";
        cout << fixed << setprecision(3) << a[i] << endl;
    }
}
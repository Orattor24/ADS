#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> ages(n) ;
    vector <int> result(n);
    stack <int> st;

    for (int i = 0; i < n; i++){
        cin >> ages[i];
    }

    for(int i =0; i < n; i++){
        while (!st.empty() && st.top() > ages[i]){
            st.pop();

        }

        if (st.empty()){
            result[i] = -1;
        }
        else{
            result[i] = st.top();
        }

        st.push(ages[i]);
    }
    for(int i =0; i <n ; i++){
        cout << result[i] << ' ';
    }
}
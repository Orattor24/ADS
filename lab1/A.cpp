#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main(){
    int test;
    cin >> test;
    int del = 1;
    while(test--){
        int size;
        cin >> size;
        queue <int> cards;
        vector <int> result(size);


        for(int i = 1; i <= size; i++){
            cards.push(i);
            cout << cards.back()<< " ";
            
        }
        cout << endl;

        

        for(int i = 1; i <= size; i++){
            for(int j = 0; j <= del; j++){
                cards.push(cards.front());
            }
            cout << cards.front() << " ";
            del++;
            /*int n = cards.front();
            result[n] = del;
            cout << result[i] <<" ";
            cards.pop();
            del ++;
            cout << del<< " ";*/

            
        }
        

    }
    //cout << del;
}
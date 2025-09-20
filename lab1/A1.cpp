#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int size;
        cin >> size;
        queue <int> cards;
        int arr[n];
        int i = 1;

        for(int  i = 1; i <= size; i++){
            cards.push(i);
        }

        while(!cards.empty()){
            for(int j = 0; j < i; j++){
                cards.push(cards.front());
                cards.pop();
            }
            arr[cards.front()-1] =i;
            i++;
            cards.pop();
        }
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }

    }
        
}
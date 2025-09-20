#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        int i = 2;
        int chislo = 0;
        for(i; i >0; i--){
            for(int j = i; j > 0; j--){

                if(i%j ==0){
                    chislo++;
                }
            }
            
        }
        int la = 0;
        int result = 0;
        if(chislo == 2){
            la++;
            result = i;
        }
        i++;
        
    }
}
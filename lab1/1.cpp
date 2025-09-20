#include <iostream>

#include <queue>
using namespace std;

int main(){
    int test_case = 0;
    queue <int> stack;
    cin >> test_case;
    
    for (int i {1}; i <10; i++)
    {
        stack.push(i);
        cout << stack.back() << " ";
    }
    
    
}
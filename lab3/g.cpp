#include <iostream>
#include <vector>   
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

bool canDeliver(const vector<long long>& kolvo_podarkov,  long long flights, long long capacity){
    long long totalFlights = 0;
    for (long long c : kolvo_podarkov) {
        totalFlights += (c+capacity - 1) / capacity;
        if (totalFlights > flights) 
        {
            return false;
        }
    }
    return totalFlights <= flights;
}

    

long long least_posible_capacity(const vector<long long>&kolvo_podarkov, long long flights){
    long long left =1;
    long long max_childre  = *max_element(kolvo_podarkov.begin(), kolvo_podarkov.end());
    long long right = max_childre;
    if (flights > kolvo_podarkov.size()) {
        right = max((long long)max_childre, (long long)1000000); 
    }
    
    while(left < right){
        long long mid = (right+left)/2;

        if (canDeliver(kolvo_podarkov, flights, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
};
int main(){
    long long number_of_islands, number_of_flights;
    cin >> number_of_islands >> number_of_flights;

    vector <long long> number_of_children(number_of_islands);

    for(long long i=0; i<number_of_islands; i++){
        cin >> number_of_children[i];
    }
    cout << least_posible_capacity(number_of_children, number_of_flights) << endl;  
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
    public:
    vector<long long> a;
    vector<long long> des;
    long long densities =-1;

    long long parent(long long i) {
        return (i - 1) / 2;
    }

    long long left(long long i) {
        return 2 * i + 1;
    }

    long long right(long long i) {
        return 2 * i + 2;
    }

    long long getMin() {
        return a[0];
    }
    
    long long getMax(){
        if(a.empty()){
            return 0;
        }
        return a[a.size()-1];
    }


    void insert(long long k) {
        a.push_back(k);
        long long ind = a.size() - 1;
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(long long i) {
        if (left(i) > a.size() - 1)
            return;
        long long j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    /*long long extractMax() {
        long long maxIndex = 0;
        for (long long i = 1; i < a.size(); i++) {
            if (a[i] > a[maxIndex]) {
                maxIndex = i;
            }
        }
        long long maxVal = a[maxIndex];
        a.erase(a.begin() + maxIndex);
        for (long long i = (a.size() / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
        return maxVal;
    }*/


    long long extractMax(){
        if(a.empty()) {
            return 0;
        }
        long long maxVal = getMax();
        a.pop_back();
        return maxVal;
    }

    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }

    long long rock(){
        while(a.size() >1){
            long long stones = 0;
            long long y = extractMax();
            long long x = extractMax();

            if(y == x){
                insert(y-x);
            }

            if(y > x){
                stones = y-x;
                insert(stones);
            }
            
        }
        
        return a[0];
    }



    long long sum(){
        long long totalCost = 0;
        while(a.size() >1){
            long long first = extractMin();
            long long  second = extractMin();
            long long cost = first+second;

            totalCost += cost;

            insert(cost);
        }
        
        return totalCost;
    }

    long long massa(long long mass){
        long long operations = 0;

        while (a.size() > 1 && a[0] < mass) {
            long long least = extractMin();
            long long second = extractMin();
            long long newMixture = least + 2 * second;
            insert(newMixture);
            operations++;
        }

        if (a[0] < mass) {
            return -1;
        }
        return operations;
    }
};

int main() {
    MinHeap *heap = new MinHeap();
    long long n, x, mass;
    cin >> n >> mass;
    
    for (long long i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    //heap->massa(mass);
    long long res = heap->massa(mass);
    cout << res;
}
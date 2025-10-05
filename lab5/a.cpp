#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
    public:
    vector<long long> a;

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

    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
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
};

int main() {
    MinHeap *heap = new MinHeap();
    long long n, x;
    cin >> n;
    
    for (long long i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    long long res = heap->sum();

    cout << res;
}
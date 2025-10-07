#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
    public:
    vector<long long> a;
    long long sum =0;

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


    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }

    int size(){
        return a.size();
    }

};

int main() {
    MinHeap *heap = new MinHeap();
    long long n, k;
    cin >> n >> k;
   
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        string x;
        cin >> x;
        if(x == "insert"){
            int chis;
            cin >> chis;
            if(heap->size() < k){
                heap->insert(chis);
                sum += chis;
            }
            else{
                if(chis > heap->getMin()){
                    long long remove = heap->extractMin();
                    heap->insert(chis);
                    sum = sum-remove+chis;
                }
            }
        }
        else if (x == "print")
        {
            cout << sum << " ";
        }
        
    }
}
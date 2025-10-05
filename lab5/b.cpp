#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return a[0];
    }
    
    int getMax(){
        if(a.empty()){
            return 0;
        }
        return a[a.size()-1];
    }


    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
        sort(a.begin(), a.end());
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    /*int extractMax() {
        int maxIndex = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] > a[maxIndex]) {
                maxIndex = i;
            }
        }
        int maxVal = a[maxIndex];
        a.erase(a.begin() + maxIndex);
        for (int i = (a.size() / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
        return maxVal;
    }*/


    int extractMax(){
        if(a.empty()) {
            return 0;
        }
        int maxVal = getMax();
        a.pop_back();
        return maxVal;
    }

    int extractMin() {
        int root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }

    int rock(){
        while(a.size() >1){
            int stones = 0;
            int y = extractMax();
            int x = extractMax();

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

    int sum(){
        int totalCost = 0;
        while(a.size() >1){
            int first = extractMin();
            int  second = extractMin();
            int cost = first+second;

            totalCost += cost;

            insert(cost);
        }
        
        return totalCost;
    }
};

int main() {
    MinHeap *heap = new MinHeap();
    int n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    int res = heap->rock();
    cout << res;
}
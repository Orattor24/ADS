#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> a;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < a.size() && a[l] > a[largest])
            largest = l;
        if (r < a.size() && a[r] > a[largest])
            largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }

    int extractMax() {
        if (a.empty()) return 0;
        int root = a[0];
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) heapify(0);
        return root;
    }

    long long sellTickets(int x) {
        long long total = 0;
        while (x-- > 0 && !a.empty()) {
            int seats = extractMax(); 
            total += seats;           
            if (seats - 1 > 0)
                insert(seats - 1);   
        }
        return total;
    }
};

int main() {
    MaxHeap heap;
    int n, x;
    cin >> n >> x;
    while (n--) {
        int seats;
        cin >> seats;
        heap.insert(seats);
    }
    cout << heap.sellTickets(x) << "\n";
}
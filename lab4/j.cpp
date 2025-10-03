#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() { 
        root = NULL;
    }

    // Insert operation - O(log n) average, O(n) worst case
    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal
    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void buildOrder(vector<int> &arr, int l, int r, vector<int> &order) {
    
        if (l > r) {
        return;
        }
        int mid = (r+l) / 2;

        order.push_back(arr[mid]);

        buildOrder(arr, l, mid - 1, order);

        buildOrder(arr, mid + 1, r, order);
        }   
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); 
    vector<int> order;
   

    BST *bst = new BST();
    bst->buildOrder(arr, 0, n - 1, order); 

    for (int x : order) cout << x << " ";
    cout << endl;
}

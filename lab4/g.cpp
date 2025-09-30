#include <iostream>
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

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data < node->data) 
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        
        return node;
    }

    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int find_distance(Node *node) {
        if (node == NULL)
            return 0;
        
        int leftgetHeight = getHeight(node->left);
        int rightgetHeight = getHeight(node->right);

        int diameterThroughRoot = leftgetHeight + rightgetHeight;
        
        int leftDiameter = find_distance(node->left);
        int rightDiameter = find_distance(node->right);
        
        return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
    }
};

int main() {
    BST *bst = new BST();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bst->root = bst->insert(bst->root, temp);
    }
    
    int res = bst->find_distance(bst->root);
    cout << res+1;
}
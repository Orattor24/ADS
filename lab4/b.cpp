#include <iostream>
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

    // In-order traversal - gives sorted output
    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Pre-order traversal
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

    // Find minimum element - leftmost node
    Node *findMin(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Find maximum element - rightmost node
    Node *findMax(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    // Search for a value
    Node *search(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    // Delete operation - most complex
    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
            
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            // Node to be deleted found
            
            // Case 1: Node has no children (leaf node)
            if (node->right == NULL && node->left == NULL) {
                delete node;
                node = NULL;
            }
            // Case 2: Node has only right child
            else if (node->left == NULL) {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
            // Case 3: Node has only left child
            else if (node->right == NULL) {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            // Case 4: Node has both children
            else {
                Node *tmp = findMax(node->left);  // Find inorder predecessor
                node->data = tmp->data;           // Replace data
                node->left = deleteNode(node->left, tmp->data);  // Delete predecessor
            }
        }
        return node;
    }

    // Helper function to get height of tree
    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Count total nodes in tree
    int countNodes(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};

int main() {
    BST *bst = new BST();
   int n;
   cin >> n;

   for(int i=0; i< n; i++){
    int temp;
    cin >> temp;
    bst->root = bst->insert(bst->root, temp);
   }

   int root;
   cin>> root;

   Node *targetNode = bst->search(bst->root, root);

    if (targetNode == NULL) {
        cout << 0;
    } else {
        int size = bst->countNodes(targetNode);
        cout << size;
    }
}
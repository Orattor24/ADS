#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    int count;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this-> count = 1;
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

        if (data < node->data) 
            node->left = insert(node->left, data);
        else if(data > node->data)
            node->right = insert(node->right, data);
        else{
            node->count++;
        }

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
            node->count--;  // Decrement multiplicity
            
            // If count becomes zero, remove the node
            if (node->count == 0) {
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
                    node->count = tmp->count;         // Replace count
                    // Set predecessor's count to 1 so it gets deleted properly
                    tmp->count = 1;
                    node->left = deleteNode(node->left, tmp->data);  // Delete predecessor
                }
            }
        }
        return node;
    }

    int cnt(Node *node, int data) {
        Node *found = search(node, data);
        if (found == NULL)
            return 0;
        else
            return found->count;
    }
    Node* find(Node* root, int x) {
        if (root == NULL) {
            return NULL;
        } else if (root->data == x) {
            return root;
        } else if (root->data < x) {
            return find(root->right, x);
        } else {
            return find(root->left, x);
        }
    }
};

int main() {
    BST *bst = new BST();
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string temp;
        int znachenie;
        cin >> temp >> znachenie;
        
        if(temp == "insert") {
            bst->root = bst->insert(bst->root, znachenie);
        }
        else if(temp == "delete") {
            bst->root = bst->deleteNode(bst->root, znachenie);
        }
        else if(temp == "cnt") {
            int result = bst->cnt(bst->root, znachenie);
            cout << result << endl;
        }
    }

}
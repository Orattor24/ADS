#include <iostream>
#include <vector>
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

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void inOrder(Node *node, vector<int> &result) {
        if (node == NULL)
            return;
        inOrder(node->left, result);
        result.push_back(node->data);
        inOrder(node->right, result);
    }

    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    Node *findMin(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *search(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
            
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL) {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL) {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL) {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
        return node;
    }

    bool pathfinder(Node *node, string path) {
        if (node == NULL) {
            return false;
        }
        
        Node *current = node;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == 'L') {
                if (current->left == NULL) {
                    return false; 
                }
                current = current->left;
            } 
            else if (path[i] == 'R') {
                if (current->right == NULL) {
                    return false;  
                }
                current = current->right;
            }
        }
        
        return true;
    }

    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int countNodes(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void count_sum(Node *node, int &sum) {
        if(node == NULL){
            return;
        }

        count_sum(node->right, sum);

        sum = sum + node->data;
        node->data = sum;

        count_sum(node->left, sum);
    }
};

int main() {
    BST *bst = new BST();
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        bst->root = bst->insert(bst->root, temp);
    }
    
    int sum = 0;
    bst->count_sum(bst->root, sum);

    vector<int> resum;
    bst->inOrder(bst->root, resum);

    

    for(int i = resum.size()-1; i >= 0; i--) {
        cout << resum[i]<< " ";
    }
}
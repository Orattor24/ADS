#include <iostream>
#include <vector>
#include <queue>
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
    int insert_e(vector<vector<int>> tree, int n){


        vector<Node*> nodes(n+1, NULL);

        for(int i= 1; i<=n; i++){
            nodes[i] = new Node(i);
        }
    
        for(int i=0; i< tree.size(); i++){
            int x = tree[i][0];
            int y = tree[i][1];
            int z = tree[i][2];

            if(z ==0){
                nodes[x]->left=nodes[y];
            } else{
                nodes[x]->right = nodes[y];
            }
        }
        queue<Node*> q;
        q.push(nodes[1]);
        int width=0;
    

        while(!q.empty()){
            int level = q.size();
            width = max(width, level);

            for(int i=0; i<level; i++){
                Node* current = q.front();
                q.pop();

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }

        return width;
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

    void count_sum(Node *node, int level, vector<int> &sums) {
        
        if (node == NULL) 
            return;
        
        if (level >= sums.size()) {
            sums.push_back(0);
        }
        
        sums[level] += node->data;
        
        count_sum(node->left, level + 1, sums);
        count_sum(node->right, level + 1, sums);
    }
};

int main() {
    BST *bst = new BST();
    
    int n;
    cin >> n;

    vector<vector<int>> shirina(n-1, vector<int>(3));

    for(int i=0; i<n-1; i++){
        cin >> shirina[i][0] >> shirina[i][1] >> shirina[i][2];
    }

    cout << bst->insert_e(shirina, n);
}
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root==NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* buildBST(vector<int> vec, int n) {
    Node* root = NULL;

    for(int i=0; i<=n; i++) {
        root = insert(root, vec[i]);
    }

    return root;
}

bool isValidBSTHelper(Node* root, Node* min, Node* max) {
    if (root==NULL) {
        return true;
    }

    if (min != NULL && root->data < min->data ) {
        return false;
    }

    if (max != NULL && root->data > max->data ) {
        return false;
    }

    return isValidBSTHelper(root->left, min, root) &&
    isValidBSTHelper(root->right, root, max);    
}

bool isValidBST(Node* root) {
    return isValidBSTHelper(root, NULL, NULL);
}

int main() {
    vector<int> vec = {2,4,1,5,3,9,6,0,8,7};
    int n = vec.size()-1;

    Node* root = buildBST(vec,n);
    cout << isValidBST(root);
}
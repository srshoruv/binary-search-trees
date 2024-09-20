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

void inorder(Node* root) {
    if(root==NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

Node* buildBST(vector<int> vec, int n) {
    Node* root = NULL;

    for(int i=0; i<=n; i++) {
        root = insert(root, vec[i]);
    }

    return root;
}

void printPath(vector<int> path) {
    for (int i=0; i<path.size(); i++) {
        cout << path[i] << " ";
    }

    cout << endl;
}

void helper(Node* root, vector<int> &path) {
    if(root == NULL) {
        return;
    }
    path.push_back(root->data);
    if (!root->left && !root->right) {
        printPath(path);
        path.pop_back();
        return;
    }

    helper(root->left, path);
    helper(root->right, path);
    
    return;
}

Node* rootToLeaf(Node* root) {
    vector<int> path;
    helper(root, path);
    return root;
}

int main() {
    vector<int> vec = {2,4,1,5,3,9,6,0,8,7};
    int n = vec.size()-1;

    Node* root = buildBST(vec,n);
    // printRange(root, 5,9);

    rootToLeaf(root);

}
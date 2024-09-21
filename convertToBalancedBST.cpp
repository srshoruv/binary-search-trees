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

void preorder(Node* root) {
    if (root==NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void getOrder(Node* root, vector<int> &nodes) {
    if(root==NULL) {
        return;
    }

    getOrder(root->left, nodes);
    nodes.push_back(root->data);
    getOrder(root->right, nodes);

}

Node* buildBSTSorted(vector<int> nodes, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start)/2;
    Node* curr = new Node(nodes[mid]);
    curr->left = buildBSTSorted(nodes, start, mid-1);
    curr->right= buildBSTSorted(nodes, mid+1, end);

    return curr;
}

Node* buildBalancedBST(Node* root) {
    vector<int> nodes;

    getOrder(root, nodes);
    return buildBSTSorted(nodes,0,nodes.size()-1);

}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = buildBalancedBST(root);
    preorder(root);
}
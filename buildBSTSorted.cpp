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

Node* buildBSTSorted(vector<int> vec, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start)/2;
    Node* curr = new Node(vec[mid]);
    curr->left = buildBSTSorted(vec, start, mid-1);
    curr->right = buildBSTSorted(vec, mid+1, end);

    return curr;
}

void preorder(Node* root) {
    if(root==NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> vec = {3,4,5,6,7,8,9};
    int start = 0;
    int end = vec.size()-1;
    Node* root = buildBSTSorted(vec, start, end);
    preorder(root);
}
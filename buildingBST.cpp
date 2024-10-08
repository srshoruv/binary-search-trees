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

bool search(Node* root, int key) {
    if (root==NULL) {
        return false;
    }
    if (root->data==key) {
        return true;
    }
    if (root->data > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* getIS(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root==NULL) {
        return NULL;
    }

    if ( val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // case 1: 0 child
        if (root->left == NULL && root->right == NULL ) {
            delete root;
            return NULL;

            //case 2: 1 child
        } 
       else if (root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        } else {
            Node* IS = getIS(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        } 
            
    
    }
    return root;
}

void printRange(Node* root, int start, int end) {
    if (root == NULL) {
        return;
    }

    if(start <= root->data && root->data <= end) {
        printRange(root->left, start, end);
        cout << root->data << " ";
        printRange(root->right, start, end);
    } else if ( root->data < start) {
        printRange(root->right, start, end);
    } else {
        printRange(root->left, start, end);
    }
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
    // printRange(root, 5,9);
    cout << isValidBST(root);
}
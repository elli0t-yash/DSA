#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;          
        }
};

// inorder: left -> root -> right
void inorder(Node* temp) {
    if(temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// preorder: root -> left -> right
void preorder(Node* temp) {
    if(temp == NULL)
        return;
    cout<<temp->data<<' ';
    preorder(temp->left);
    preorder(temp->right);
}

//postorder: left -> right -> root
void postorder(Node* temp) {
    if(temp == NULL)
        return;
    postorder(temp -> left);
    postorder(temp -> right);
    cout<<temp->data<<" ";
}

//Morris Inorder without call-stack or recursion
//using two pointers current  and previous in order to make a threaded binary tree
vector<int> morrisInorder(Node* root) {
    vector<int> inorder;
    Node* cur = root;
    while (cur != NULL) {
        if(cur -> left == NULL) {
            inorder.push_back(cur -> data);
            cur = cur -> right;
        } else {
            Node* prev = cur -> left;
            while(prev -> right && prev -> right != cur) {
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                prev -> right = cur;
                cur = cur -> left;
            } else {
                prev -> right = NULL;
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }
        }
    }
    return inorder;
}

//Morris Preorder without call-stack or recursion
vector<int> morrisPreorder(Node* root) {
    vector<int> preorder;
    Node* cur = root;
    while (cur != NULL) {
        if(cur -> left == NULL) {
            preorder.push_back(cur -> data);
            cur = cur -> right;
        } else {
            Node* prev = cur -> left;
            while(prev -> right && prev -> right != cur) {
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                prev -> right = cur;
                preorder.push_back(cur -> data);
                cur = cur -> left;
            } else {
                prev -> right = NULL;
                cur = cur -> right;
            }
        }
    }
    return preorder;
}


int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->right = new Node(8);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    morrisInorder(root);
}

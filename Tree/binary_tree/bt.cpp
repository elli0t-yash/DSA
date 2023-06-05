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

//left view: first node of every level
vector<int> leftView(Node* root, int level, vector<int> &res) {
    if(root == NULL) return res;
    if(res.size() == level) res.push_back(root -> data);
    leftView(root -> left, level + 1, res);
    leftView(root -> right, level + 1, res);
}

//right view: last node of every level
vector<int> rightView(Node* root, int level, vector<int> &res) {
    if(root == NULL) return res;
    if(res.size() == level) res.push_back(root -> data);
    leftView(root -> right, level + 1, res);
    leftView(root -> left, level + 1, res);
}

//bottom view: vertical order traversal in used 
vector<int> bottomView(Node* root) {
    vector<int> ans;
    if(root = NULL) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node -> data;
        if(node -> left != NULL) {
            q.push({node -> left, line - 1});
        } 
        if(node -> right != NULL) {
            q.push({node -> right, line - 1});
        }
    }
    for(auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}


int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->right = new Node(8);
    vector<int> ans = leftView(root, 0, ans);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    for(int x : ans)
    cout<<x;
    cout<<endl;
    
}

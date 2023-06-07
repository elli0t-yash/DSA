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

// Inorder: left -> root -> right
void inorder(Node* temp) {
    if(temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// Preorder: root -> left -> right
void preorder(Node* temp) {
    if(temp == NULL)
        return;
    cout<<temp->data<<' ';
    preorder(temp->left);
    preorder(temp->right);
}

// Postorder: left -> right -> root
void postorder(Node* temp) {
    if(temp == NULL)
        return;
    postorder(temp -> left);
    postorder(temp -> right);
    cout<<temp->data<<" ";
}

// Morris Inorder without call-stack or recursion
// Using two pointers current  and previous in order to make a threaded binary tree
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

// Morris Preorder without call-stack or recursion
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

// Left view: first node of every level
vector<int> leftView(Node* root, int level, vector<int> &res) {
    if(root == NULL) return res;
    if(res.size() == level) res.push_back(root -> data);
    leftView(root -> left, level + 1, res);
    leftView(root -> right, level + 1, res);
}

// Right view: last node of every level
vector<int> rightView(Node* root, int level, vector<int> &res) {
    if(root == NULL) return res;
    if(res.size() == level) res.push_back(root -> data);
    leftView(root -> right, level + 1, res);
    leftView(root -> left, level + 1, res);
}

// Bottom view: vertical order traversal in used 
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
            q.push({node -> right, line + 1});
        }
    }
    for(auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

// Top view: using level order traversal
vector<int> topView(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()) { 
            mpp[line] = node -> data;
        } 
        if(node -> left) {
            q.push({node -> left, line - 1});
        } 
        if(node -> right) {
            q.push({node -> right, line + 1});
        }
    }
    for(auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

// All the 3 traversal using stack 
vector<int> preInPostTraversal(Node* root) {
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if(root == NULL) return;
    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first -> data);
            it.second++;
            st.push(it);

            if(it.first -> left) {
                st.push({it.first -> left, 1});
            }
        }

        else if(it.second == 2) {
            in.push_back(it.first -> data);
            it.second++;
            st.push(it);

            if(it.first -> right) {
                st.push({it.first -> right, 1});
            }
        }

        else {
            post.push_back(it.first -> data);
        }
    }
}

// Vertical order traversal
vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int,int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node -> data);
        if(node -> left) {
            todo.push({node -> left, {x - 1, y + 1}});
        }
        if(node -> right) {
            todo.push({node -> right, {x + 1, y + 1}});
        }
    }
    
    vector<vector<int>> ans;
    for(auto p : nodes) {
        vector<int> col;
        for(auto q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// Maximum width of the tree
    int widthOfBinaryTree(Node* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;
            int first,last;
            for(int i = 0; i < size; i++) {
                int cur_id = q.front().second - mmin;
                Node* node = q.front().first;
                q.pop();
                if(i == 0) first = cur_id;
                if(i == size - 1) last = cur_id;
                if(node -> left) 
                    q.push({node -> left, cur_id*2+1});
                if(node -> right)
                    q.push({node -> right, cur_id*2+2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }

// Path from root to any node X
bool findPath(Node* root, vector<int> &arr, int x) {
    if(!root)
        return false;
    
    arr.push_back(root -> data);

    if(root -> data == x)
        return true;

    if(findPath(root -> left, arr, x) || findPath(root -> right, arr, x))
        return true;
    
    arr.pop_back();
    return false;
}

vector<int> pathInATree(Node* root, int x) {
    vector<int> arr;
    if(root) {
        findPath(root, arr, x);
        return arr;
    }
}

// Level order traversal
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                level.push_back(node -> data);
            }
            ans.push_back(level);
        }
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

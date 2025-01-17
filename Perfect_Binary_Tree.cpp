#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return NULL;
    queue<Node*> q;
    Node* root = new Node(levelOrder[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        Node* current = q.front();
        q.pop();
        if (levelOrder[i] != -1) {
            current->left = new Node(levelOrder[i]);
            q.push(current->left);
        }
        i++;
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new Node(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int calculateDepth(Node* root) {
    int depth = 0;
    while (root) {
        depth++;
        root = root->left;
    }
    return depth;
}

bool isPerfectBinaryTree(Node* root, int depth, int level = 0) {
    if (!root) return true;

    if (!root->left && !root->right) {
        return depth == level + 1;
    }

    if (!root->left || !root->right) {
        return false;
    }

    return isPerfectBinaryTree(root->left, depth, level + 1) &&
           isPerfectBinaryTree(root->right, depth, level + 1);
}

int main() {
    int n;
    vector<int> levelOrder;
    while (cin >> n) {
        levelOrder.push_back(n);
    }

    Node* root = buildTree(levelOrder);

    int depth = calculateDepth(root);

    if (isPerfectBinaryTree(root, depth)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

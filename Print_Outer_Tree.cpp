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

// Function to build the binary tree from level-order input
Node* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Collect the left boundary excluding leaf nodes
void collectLeftBoundary(Node* root, vector<int>& result) {
    Node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right) result.push_back(curr->val);
        curr = (curr->left) ? curr->left : curr->right;
    }
}

// Collect the leaf nodes
void collectLeaves(Node* root, vector<int>& result) {
    if (!root) return;

    if (!root->left && !root->right) {
        result.push_back(root->val);
        return;
    }

    collectLeaves(root->left, result);
    collectLeaves(root->right, result);
}

// Collect the right boundary excluding leaf nodes (in reverse order)
void collectRightBoundary(Node* root, vector<int>& result) {
    Node* curr = root->right;
    vector<int> temp;

    while (curr) {
        if (curr->left || curr->right) temp.push_back(curr->val);
        curr = (curr->right) ? curr->right : curr->left;
    }

    reverse(temp.begin(), temp.end());
    result.insert(result.end(), temp.begin(), temp.end());
}

// Function to compute the outer view of the binary tree
vector<int> getOuterView(Node* root) {
    vector<int> result;
    if (!root) return result;

    result.push_back(root->val); // Add the root

    collectLeftBoundary(root, result);
    collectLeaves(root, result);
    collectRightBoundary(root, result);

    return result;
}

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nodes;
    int val;

    while (ss >> val) {
        nodes.push_back(val);
    }

    Node* root = buildTree(nodes);
    vector<int> outerView = getOuterView(root);

    for (int i = 0; i < outerView.size(); i++) {
        cout << outerView[i];
        if (i < outerView.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

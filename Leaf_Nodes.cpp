#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(vector<int> &levelOrder)
{
    if (levelOrder.empty() || levelOrder[0] == -1)
        return NULL;
    queue<Node *> q;
    Node *root = new Node(levelOrder[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        Node *current = q.front();
        q.pop();
        if (levelOrder[i] != -1)
        {
            current->left = new Node(levelOrder[i]);
            q.push(current->left);
        }
        i++;
        if (i < levelOrder.size() && levelOrder[i] != -1)
        {
            current->right = new Node(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void collectLeafNodes(Node *root, vector<int> &leafNodes)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leafNodes.push_back(root->val);
    }
    collectLeafNodes(root->left, leafNodes);
    collectLeafNodes(root->right, leafNodes);
}

int main()
{
    int n;
    vector<int> levelOrder;
    while (cin >> n)
    {
        levelOrder.push_back(n);
    }

    Node *root = buildTree(levelOrder);

    vector<int> leafNodes;
    collectLeafNodes(root, leafNodes);

    sort(leafNodes.rbegin(), leafNodes.rend());

    for (int val : leafNodes)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

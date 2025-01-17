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
    {
        return NULL;
    }

    Node *root = new Node(levelOrder[0]);
    queue<Node *> q;
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

int sumNonLeafNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        return 0;
    }

    int sum = root->val;

    if (root->left)
    {
        sum += sumNonLeafNodes(root->left);
    }
    if (root->right)
    {
        sum += sumNonLeafNodes(root->right);
    }

    return sum;
}

int main()
{
    vector<int> levelOrder;
    int val;
    while (cin >> val)
    {
        levelOrder.push_back(val);
    }

    Node *root = buildTree(levelOrder);

    int result = sumNonLeafNodes(root);

    cout << result << endl;

    return 0;
}

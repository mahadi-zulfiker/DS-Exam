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

Node *buildTree(vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == -1)
        return NULL;

    Node *root = new Node(nodes[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        Node *current = q.front();
        q.pop();

        if (nodes[i] != -1)
        {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1)
        {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void printLevel(Node *root, int level)
{
    if (!root || level < 0)
    {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    int currentLevel = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (currentLevel == level)
        {
            bool hasNodes = false;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                cout << node->val << " ";
                hasNodes = true;
            }
            if (hasNodes)
                cout << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        currentLevel++;
    }

    cout << "Invalid" << endl;
}

int main()
{
    string input;
    getline(cin, input);
    stringstream ss(input);

    vector<int> nodes;
    int num;
    while (ss >> num)
    {
        nodes.push_back(num);
    }

    int level;
    cin >> level;

    Node *root = buildTree(nodes);

    printLevel(root, level);

    return 0;
}

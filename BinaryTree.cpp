#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    // Helper Function to 'insert()' Function
    Node *insertNode(Node *root, int val)
    {
        if (root == nullptr)
        {
            return new Node(val);
        }
        if (val < root->data)
        {
            root->left = insertNode(root->left, val);
        }
        else
        {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    void BFSTraversal()
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.BFSTraversal();
    return 0;
}
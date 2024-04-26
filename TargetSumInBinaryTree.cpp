#include <iostream>
#include <unordered_set>
using namespace std;

class NodeTree
{
public:
    int val;
    NodeTree *left;
    NodeTree *right;

    NodeTree(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class BinaryTree
{
private:
    NodeTree *root;

    NodeTree *createTreeRec(NodeTree *node, int val)
    {
        if (node == nullptr)
            return new NodeTree(val);

        if (val > node->val)
            node->right = createTreeRec(node->right, val);
        else
            node->left = createTreeRec(node->left, val);
        return node;
    }

    void traverseInorderRec(NodeTree *node)
    {
        if (node == nullptr)
            return;

        traverseInorderRec(node->left);
        cout << node->val << " ";
        traverseInorderRec(node->right);
    }

    bool findPairUntil(NodeTree *root, int k, unordered_set<int> &visited)
    {
        if (root == nullptr)
            return false;

        if (visited.count(k - root->val) > 0)
            return true;

        visited.insert(root->val);

        return findPairUntil(root->left, k, visited) || findPairUntil(root->right, k, visited);
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void createTree(int val)
    {
        root = createTreeRec(root, val);
    }

    void traverseInOrder()
    {
        traverseInorderRec(root);
    }

    bool findPair(int k)
    {
        unordered_set<int> visited;
        return findPairUntil(root, k, visited);
    }
};

int main()
{
    BinaryTree tree;
    tree.createTree(8);
    tree.createTree(3);
    tree.createTree(11);
    tree.createTree(1);
    tree.createTree(6);
    tree.createTree(4);
    tree.createTree(7);
    tree.createTree(15);
    tree.createTree(13);

    // Output the inorder traversal of the converted BST
    cout << "Inorder traversal of the converted BST: ";
    tree.traverseInOrder();
    cout << endl;

    if (tree.findPair(14))
        cout << " Target Sum exist" << endl;
    else
        cout << " Target doesn't Sum exist" << endl;
    return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    // Helper function to Recursively insert a key into BST
    Node *insertRec(Node *root, int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return root;
        }
        if (key < root->key)
        {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    // Helper Function for preOrder
    void preOrderRec(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->key << " ";
        preOrderRec(root->left);
        preOrderRec(root->right);
    }

    bool isBSTHelper(Node *node, int minValue, int maxValue)
    {
        if (node == nullptr)
            return true;
        if (node->key <= minValue || node->key >= maxValue)
        {
            return false;
        }
        return isBSTHelper(node->left, minValue, node->key) && isBSTHelper(node->right, node->key, maxValue);
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insertRec(root, key);
    }

    void preOrder()
    {
        cout << "Inorder Traversal : ";
        preOrderRec(root);
        cout << endl;
    }

    bool isBST()
    {
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BST obj;
    obj.insert(50);
    obj.insert(30);
    obj.insert(70);
    obj.insert(20);
    obj.insert(40);
    obj.insert(60);
    obj.insert(80);
    obj.preOrder();
    bool isValid = obj.isBST();
    cout << "Tree is Valid ? " << (isValid ? "Yess" : "Noo") << endl;
    return 0;
}
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

    // Helper Function for the Search
    bool searchRec(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        else if (root->key == key)
        {
            return true;
        }
        else if (key > root->key)
        {
            return searchRec(root->right, key);
        }
        else
        {
            return searchRec(root->left, key);
        }
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

    // Helper Function for inOrder
    void inOrderRec(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderRec(root->left);
        cout << root->key << " ";
        inOrderRec(root->right);
    }

    // Helper Function for postOrder
    void postOrderRec(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrderRec(root->left);
        postOrderRec(root->right);
        cout << root->key << " ";
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

    bool search(int key)
    {
        return searchRec(root, key);
    }

    void inOrder()
    {
        cout << "Inorder Traversal : ";
        inOrderRec(root);
        cout << endl;
    }
    void preOrder()
    {
        cout << "preOrder Traversal : ";
        preOrderRec(root);
        cout << endl;
    }
    void postOrder()
    {
        cout << "postOrder Traversal : ";
        postOrderRec(root);
        cout << endl;
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
    int key = 50;
    if (obj.search(key))
        cout << "Found in the BST" << endl;
    else
        cout << key << " Not found in the BST" << endl;
    obj.preOrder();
    obj.inOrder();
    obj.postOrder();
    return 0;
}
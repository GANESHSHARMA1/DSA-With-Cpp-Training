#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    TreeNode *root;

    // Helper function for recursive insertion
    TreeNode *insertRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < node->val)
        {
            node->left = insertRecursive(node->left, val);
        }
        else
        {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    int countNodes(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void storeNode(TreeNode *node, TreeNode **nodeList, int &index)
    {
        if (node == nullptr)
            return;

        storeNode(node->left, nodeList, index);
        nodeList[index++] = node;
        storeNode(node->right, nodeList, index);
    }

    void sortNode(TreeNode **nodeList, int nodeCount)
    {
        for (int i = 0; i < nodeCount; i++)
        {
            for (int j = 0; j < nodeCount - 1; j++)
            {
                if (nodeList[j]->val > nodeList[j + 1]->val)
                {
                    swap(nodeList[j], nodeList[j + 1]);
                }
            }
        }
    }

    TreeNode *buildBST(TreeNode **nodeList, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *newNode = nodeList[mid];

        newNode->left = buildBST(nodeList, left, mid - 1);
        newNode->right = buildBST(nodeList, mid + 1, right);

        return newNode;
    }

    // Helper function for inorder traversal (recursive)
    void inorderUtil(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inorderUtil(node->left);
        cout << node->val << " ";
        inorderUtil(node->right);
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    // Method to insert a value into the BST
    void insert(int val)
    {
        root = insertRecursive(root, val);
    }

    void convertToBST()
    {
        int nodeCount = countNodes(root);
        TreeNode **nodeList = new TreeNode *[nodeCount];
        int index = 0;

        storeNode(root, nodeList, index);

        sortNode(nodeList, nodeCount);

        root = buildBST(nodeList, 0, nodeCount - 1);

        delete[] nodeList;
    }

    // Function to perform inorder traversal of the BST
    void inorderTraversal()
    {
        inorderUtil(root);
    }
};

int main()
{

    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.convertToBST();

    // Output the inorder traversal of the converted BST
    cout << "Inorder traversal of the converted BST: ";
    tree.inorderTraversal();
    cout << endl;
    return 0;
}
// Test cases checked:
// adding negative values of nodes
// adding positive values of nodes
// deleting a node that does not exist
// adding a large Int to the tree
//

#include <iostream>
#include "vector"

using namespace std;
template <class T>
struct treeNode
{
    T *data;
    struct treeNode *left;
    struct treeNode *right;
};
template <class T>
struct tree
{

private:
    vector<treeNode<T> *> nodeslist;

    // takes int as a parameter
    // returns the parentIndex
    int parentIndex(int node)
    {
        return (node - 1) / 2;
    }
    // takes a pointer to the root of the tree as parameters
    // returns an int representing the Size of the tree
    int treeSize(treeNode<T> *root)
    {
        if (root == NULL)
            return 0;
        return 1 + treeSize(root->left) + treeSize(root->right);
    }

    // require a pointer to the Tree object
    //  print in postOrder, preOrder, inOrder traversals
    void postOrderPrint(treeNode<T> *root)
    {
        if (root == NULL)
            return;
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout << *(root->data);
    }
    void inOrderPrint(treeNode<T> *root)
    {
        if (root == NULL)
            return;
        inOrderPrint(root->left);
        cout << *(root->data);
        inOrderPrint(root->right);
    }

    void preOrderPrint(treeNode<T> *root)
    {
        if (root == NULL)
            return;
        cout << *(root->data);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }

};
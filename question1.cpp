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
};
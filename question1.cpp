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

public:
    // takes a T object as paramteter
    //  add the obejct T to the tree
    void addNode(T data)
    {
        int *a = new int;
        *a = data;
        treeNode<T> *temp = new treeNode<T>;
        *temp = {a, NULL, NULL};
        int index;
        for (int i = 0; i < nodeslist.size(); ++i)
        {
            if (nodeslist[i] == NULL)
            {
                index = i;
                break;
            }
            else
                index = i + 1;
        }
        if (index < nodeslist.size())
            nodeslist[index] = temp;
        else
            nodeslist.push_back(temp);
        if (index != 0)
        {
            int parent = parentindexex(index);
            if (nodeslist[parent]->left != NULL)
                nodeslist[parent]->right = temp;
            else
                nodeslist[parent]->left = temp;
        }
    }

    // takes a T object as parameter
    // deletes the node T
    void deleteNode(T data)
    {
        int index = -1;
        for (int i = 0; i < nodeslist.size(); i++)
        {
            if (nodeslist[i] != NULL && *(nodeslist[i]->data) == data)
            {
                index = i;
            }
        }
        if (index != -1 && nodeslist[index]->left == NULL && nodeslist[index]->right == NULL)
        {
            treeNode<T> * temp = nodeslist[index];
            nodeslist[index] = NULL;
            if (index != 0)
            {
                int parent = parentindexex(index);
                if (index % 2 == 0)
                    nodeslist[parent]->right = NULL;
                else
                    nodeslist[parent]->left = NULL;
            }
            free(temp);
        }
        else
            cout << "CANNOT DELETE NODE" << endl;
    }

    // requires T object as parameter
    // returns the size of subtree
    int subtreeSize(T data)
    {
        int index = -1;
        for (int i = 0; i < nodeslist.size(); i++)
        {
            if (nodeslist[i] != NULL && *(nodeslist[i]->data) == data)
            {
                index = i;
            }
        }
        if (index != -1)
            return treeSize(nodeslist[index]);
        return 0;
    }
    void postOrderPrint()
    {
        postOrderPrint(nodeslist[0]);
    }
    void inOrderPrint()
    {
        inOrderPrint(nodeslist[0]);
    }
    void preOrderPrint()
    {
        preOrderPrint(nodeslist[0]);
    }
    int treeSize()
    {
        if (nodeslist.size() == 0)
            return 0;
        return treeSize(nodeslist[0]);
    }
};

int main()
{
    tree<int> tree;
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(10);
    cout << tree.treeSize() << endl;
    tree.addNode(12);
    cout << endl;
    tree.postOrderPrint();
    cout << endl;
    tree.inOrderPrint();
    cout << endl;
    tree.preOrderPrint();
    return 0;
}
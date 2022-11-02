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
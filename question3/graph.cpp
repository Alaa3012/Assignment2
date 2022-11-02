/*- Testing:
    try it on lists of different sizes
    try it on long equal sizes vectors
*/

#include <bits/stdc++.h>
#include "stdexcept"
    using namespace std;
class Graph
{
protected:
    map<int, int> keyIndex;
    vector<vector<int> *> AdjacencyList;

public:
    /*
     -Requires: to vectors of integers representing the node ID where each element of the first vector
     is linked to the corresponding element in the second vector.
     constructs a tree connected from such that each element in the first vector
     is connected to the corresponding element in the second vector.
     throws an invalid_argument if the vectors are of different sizes.
    */
    Graph(const vector<int> &starts, const vector<int> &ends)
    {
        if (starts.size() != ends.size())
            throw invalid_argument("vectors are of different sizes.");
        int i = 0;
        for (int j = 0; j < starts.size(); j++)
        {
            if (keyIndex.find(starts[j]) == keyIndex.end())
            {
                keyIndex[starts[j]] = i++;
                vector<int> *temp = new vector<int>;
                AdjacencyList.push_back(temp);
            }
        }
        for (int j = 0; j < ends.size(); ++j)
        {
            if (keyIndex.find(ends[j]) == keyIndex.end())
                keyIndex[ends[j]] = i++;
        }
        for (int j = 0; j < starts.size(); ++j)
        {
            vector<int> *temp = AdjacencyList[keyIndex[starts[j]]];
            temp->push_back(keyIndex[ends[j]]);
        }
    };
    /*
     Requires: A node ID.
     returns the number of  edges from this node
    */
    int numOutgoing(const int nodeID)
    {
        if (keyIndex.find(nodeID) == keyIndex.end())
            throw invalid_argument("invalid nodeID");
        if (keyIndex[nodeID] >= AdjacencyList.size())
            return 0;
        return AdjacencyList[keyIndex[nodeID]]->size();
    }

    /*
     Requires: A node ID.
     returns a vector of the outgoing edges from the node.
    */

    const vector<int> &adjacent(const int nodeID)
    {
        if (keyIndex.find(nodeID) == keyIndex.end())
            throw invalid_argument("invalid nodeID");
        vector<int> *result = new vector<int>;
        if (keyIndex[nodeID] >= AdjacencyList.size())
            return *result;
        vector<int> temp = *(AdjacencyList[keyIndex[nodeID]]);
        for (int i = 0; i < temp.size(); ++i)
        {
            for (map<int, int>::iterator it = keyIndex.begin(); it != keyIndex.end(); ++it)
            {
                if (temp[i] == it->second)
                    result->push_back(it->first);
            }
        }

        return *result;
    }
};
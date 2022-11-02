#include <bits/stdc++.h>
#include "stdexcept"

using namespace std;
#include "graph.cpp"
class graph_cycles : public Graph
{
public:
    graph_cycles(const vector<int> &starts, const vector<int> &ends) : Graph(starts, ends)
    {
    }
    vector<int> &hasCycle()
    {
        vector<int> nodes;
        vector<int> * result = new vector<int>;

        if (AdjacencyList.empty())
            return *result;
        bool cycle = false;
        int current;
        for (int i = 0; !cycle && i < AdjacencyList.size(); ++i)
        {
            current = i;
            nodes.push_back(i);

            map<int, bool> visited;
            visited[i] = true;
            int c = 0;
            while (!cycle && !nodes.empty())
            {
                for (int a : *AdjacencyList[current])
                {
                    c++;
                    if (count(nodes.begin(), nodes.end(), a))
                    {
                        current = a;
                        cycle = true;
                        break;
                    }
                    if (!visited[a] && a < AdjacencyList.size())
                    {
                        current = a;
                        nodes.push_back(a);
                        visited[a] = true;
                        break;
                    }
                }
                if (!cycle && c == 0)
                {
                    nodes.pop_back();
                    current = nodes[nodes.size() - 1];
                }
                c = 0;
            }
        }
        vector<int> tempV;
        tempV.push_back(current);
        int temp = -1;
        while (!nodes.empty() && temp != current)
        {
            temp = nodes[nodes.size() - 1];
            tempV.push_back(temp);
            nodes.pop_back();
        }
        for (int i = tempV.size() - 1; i >= 0; --i)
        {
            for (map<int, int>::iterator it = keyIndex.begin(); it != keyIndex.end(); ++it)
            {
                if (tempV[i] == it->second)
                    result->push_back(it->first);
            }
        }

        return *result;
    }
};
int main()
{
    vector<int> a, b;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    a.push_back(30);
    b.push_back(23);
    b.push_back(0);
    b.push_back(2);
    b.push_back(2);
    b.push_back(13);
    b.push_back(13);
    graph_cycles g(a, b);
    vector<int> vec = g.hasCycle();
    for (int i : vec)
        std::cout << i << ' ';
}
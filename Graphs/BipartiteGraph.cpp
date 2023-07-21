#include <bits/stdc++.h>
#include "./Graphs.h"
using namespace std;
bool CheckBipartite(int node, vector<int> &color, vector<vector<int>> &list)
{
    queue<int> q;
    q.push(node);

    color[node] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : list[node])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = !color[node];

                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    Graphs graph(nodes, edges);
    graph.buildGraphList();

    vector<int> color(nodes + 1, -1);
    vector<vector<int>> adjList = graph.GetList();

    cout << CheckBipartite(0, color, adjList);

    return 0;
}
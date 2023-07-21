#include <bits/stdc++.h>
#include "./Graphs.h"
using namespace std;

bool CheckBipartiteDFS(int node, vector<int> &color, vector<vector<int>> &list)
{

    if (color[node] == -1)
    {
        color[node] = 0;
    }
    for (int neighbor : list[node])
    {
        if (color[neighbor] == -1)
        {
            color[neighbor] = !color[node];
            if (!CheckBipartiteDFS(neighbor, color, list))
            {
                return false;
            }
        }
        else if (color[neighbor] == color[node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    Graphs graph(nodes, edges);
    graph.buildGraphList();

    vector<int> color(nodes + 1, -1);
    vector<vector<int>> adjList = graph.GetList();

    cout << CheckBipartiteDFS(0, color, adjList);

    return 0;
}
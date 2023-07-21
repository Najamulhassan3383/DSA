#include <bits/stdc++.h>
using namespace std;
bool DFS(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> list[])
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto it : list[node])
    {
        if (visited[it] == 0)
        {
            if (DFS(it, visited, pathVisited, list))
            {
                return true;
            }
        }
        else if (pathVisited[it] == 1)
        {
            return true;
        }
    }
    pathVisited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (DFS(i, visited, pathVisited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(nodes, adj);

    return 0;
}
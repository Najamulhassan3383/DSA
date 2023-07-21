#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &visited, vector<int> list[])
{
    visited[node] = 2;
    for (auto it : list[node])
    {
        if (visited[it] == 0)
        {
            if (dfs(it, visited, list))
            {
                return true;
            }
        }
        else if (visited[it] == 2)
        {
            return true;
        }
    }
    visited[node] = 1;
    return false;
}

bool isCyclic(int V, vector<int> list[])
{
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i, visited, list))
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
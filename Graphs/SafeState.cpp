#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis))
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, pathVis);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (pathVis[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
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

    vector<int> ans = eventualSafeNodes(nodes, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
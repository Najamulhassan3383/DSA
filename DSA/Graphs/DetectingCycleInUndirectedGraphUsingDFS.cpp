#include <bits/stdc++.h>
using namespace std;

bool detect(int source, vector<int> adj[], vector<int> &vis, int parent)
{
    vis[source] = 1;
    for (auto it : adj[source])
    {
        if (vis[it] == 0)
        {
            if (detect(it, adj, vis, source))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //     int nodes, edges;
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    vector<int> vis(V + 1, 0);
    for (int i = 0; i < E; i++)
    {
        // nodes are 1 based indexed
        int node1, node2;

        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    bool ans = false;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == 0)
        {
            if (detect(i, adj, vis, -1))
            {
                ans = true;
            }
        }
    }
    if (ans)
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }

    return 0;
}
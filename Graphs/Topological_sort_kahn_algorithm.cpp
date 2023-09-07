#include <bits/stdc++.h>
using namespace std;

void topo_sort(int nodes, vector<int> adj[], vector<int> &indegree)
{
    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    vector<int> indegree(nodes, 0);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    topo_sort(nodes, adj, indegree);

    return 0;
}
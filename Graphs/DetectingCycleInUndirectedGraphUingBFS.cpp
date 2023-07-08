#include <bits/stdc++.h>
#include "./Graphs.h"
using namespace std;

bool isCycle(int V, vector<int> adj[])
{
    // declare visited vector
    vector<int> vis(V + 1, 0);
    // decalare the queue for bfs
    //{node, parent}
    queue<pair<int, int>> q;

    // for all the nodes even for disconnected graph

    for (int i = 1; i < V; i++)
    {
        // if not visited
        if (vis[i] == 0)
        {
            q.push({i, -1});
            // mark the node as visited
            vis[i] = 1;
            // while the queue is not empty
            while (!q.empty())
            {
                // get the first element
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                // for all the adjacent nodes
                for (auto it : adj[node])
                {
                    // if not visited
                    if (vis[it] == 0)
                    {
                        // push the node and its parent
                        q.push({it, node});
                        // mark the node as visited
                        vis[it] = 1;
                    }
                    // if the node is visited and it is not the parent of the current node
                    else if (it != parent)
                    {
                        // there is a cycle
                        return true;
                    }
                }
            }
        }
    }
    // if there is no cycle
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    Graphs g(nodes, edges);

    g.buildGraphList();

    vector<vector<int>> list;

    list = g.GetList();

    // cout << isCycle(nodes, list);

    return 0;
}
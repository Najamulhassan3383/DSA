#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    vector<int> indegree(N, 0);
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < P; i++)
    {
        indegree[prerequisites[i].first]++;
    }
    // make a adjacency list from pairs
    vector<int> adj[N];
    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }

    for (int i = 0; i < N; i++)
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
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (topo.size() == N)
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    vector<pair<int, int>> prerequisites;
    for (int i = 0; i < P; i++)
    {
        int u, v;
        cin >> u >> v;
        prerequisites.push_back({u, v});
    }
    bool ans = isPossible(N, P, prerequisites);
    cout << ans << endl;
    return 0;
}
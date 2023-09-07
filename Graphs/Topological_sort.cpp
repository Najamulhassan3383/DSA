#include <bits/stdc++.h>
using namespace std;

// 0 -> 1, 2
// 1 -> 3, 4
// 2 -> 4
// 3 -> 5
// 4 -> 5
// 5 ->
// This graph looks like :
// 0 -> 1 -> 3 -> 5
//  \-> 2 -> 4 -> 5
// To perform a topological sort on this graph,
// we can call the topo_sort function with the starting node 0,
// the adjacency list, an empty stack, and a boolean vector of size 6
//  initialized to false.

// vector<int> adj[6];
// adj[0].push_back(1);
// adj[0].push_back(2);
// adj[1].push_back(3);
// adj[1].push_back(4);
// adj[2].push_back(4);
// adj[3].push_back(5);
// adj[4].push_back(5);

// vector<bool> visited(6, false);
// stack<int> st;
// topo_sort(0, adj, visited, st);
// The function starts by marking node 0 as visited and recursively calling itself with
// node 1 and node 2. Node 1 is marked as visited and recursively calls itself
// with node 3 and node 4. Node 3 is marked as visited and has no adjacent nodes, so it is pushed onto the stack.Node 4 is marked as visited and has one adjacent node, node 5, which is not visited yet.Node 5 is marked as visited and pushed onto the stack.Node 4 is then pushed onto the stack.Node 1 is then pushed onto the stack.Node 2 is marked as visited and recursively calls itself with node 4. Node 4 has already been visited, so it is not visited again.Node 2 is then pushed onto the stack.Node 0 is then pushed onto the stack.
//   The resulting stack contains the nodes in the order in which they should be visited to satisfy the topological ordering of the graph : 0 2 4 5 1 3.

// The program then prints out the stack in reverse order,
//     which gives us the topological sort of the graph : 3 1 5 4 2 0.

void topo_sort(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            topo_sort(it, adj, visited, st);
        }
    }
    st.push(node);
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
    vector<bool> visited(nodes, false);
    stack<int> st;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            topo_sort(i, adj, visited, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
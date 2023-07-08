#include "./Graphs.h"
#include <bits/stdc++.h>
using namespace std;

int NumberOfProvinces(int nodes, vector<vector<int>> list)
{
    int count = 0;
    vector<bool> visited(nodes + 1, false);
    queue<int> q;
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            count++;

            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : list[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes;
    cin >> nodes;

    Graphs g(nodes);

    vector<vector<int>> arr;
    for (int i = 0; i < 4; i++)
    {

        vector<int> inArr;
        int a;

        for (int j = 0; j < 4; j++)
        {
            cin >> a;
            inArr.push_back(a);
        }
        arr.push_back(inArr);
    }
    vector<vector<int>> list;

    g.ChangeMatrixToList(arr);
    list = g.GetList();
    int ans = NumberOfProvinces(nodes, list);
    cout << ans << endl;

    return 0;
}
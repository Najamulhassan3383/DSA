// Description: Main file for testing Graphs.h

#include <bits/stdc++.h>
#include "Graphs.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int nodes, edges;
    // cin >> nodes >> edges;
    int nodes;
    cin >> nodes;

    Graphs g(nodes);
    // g.buildGraphList();
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
    g.DisplayGraph();

    return 0;
}
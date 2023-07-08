#include "./Graphs.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, coloumns;
    cin >> rows >> coloumns;
    vector<vector<int>> grid(rows, vector<int>(coloumns, 0));
    vector<vector<bool>> visited(rows, vector<bool>(coloumns, false));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    Graphs g;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == false)
            {
                count++;
                g.BFS(i, j, grid, visited);
            }
        }
    }
    cout << count << endl;

    return 0;
}
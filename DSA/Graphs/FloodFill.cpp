#include <bits/stdc++.h>
using namespace std;

// it does not work for the problem on geeksforgeeks for very large inputs but it is good starting point
// https : // practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
void BFS(int row, int col, vector<vector<int>> &grid, int newColor)
{

    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;

        // check there neighbors in four directions
        //(row, col-1), (row, col+1), (row-1, col), (row+1, col)
        if (r - 1 >= 0 && grid[r - 1][c] != newColor && grid[r - 1][c] != 0)
        {
            grid[r - 1][c] = newColor;
            q.push({r - 1, c});
        }
        if (r + 1 < grid.size() && grid[r + 1][c] != newColor && grid[r + 1][c] != 0)
        {
            grid[r + 1][c] = newColor;
            q.push({r + 1, c});
        }
        if (c - 1 >= 0 && grid[r][c - 1] != newColor && grid[r][c - 1] != 0)
        {
            grid[r][c - 1] = newColor;
            q.push({r, c - 1});
        }
        if (c + 1 < grid[0].size() && grid[r][c + 1] != newColor && grid[r][c + 1] != 0)
        {
            grid[r][c + 1] = newColor;
            q.push({r, c + 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, coloumns;
    cin >> rows >> coloumns;
    vector<vector<int>> grid(rows, vector<int>(coloumns, 0));
    vector<vector<bool>> visited(rows, vector<bool>(coloumns, false));

    int sourceRow, sourceCol, newColor;
    cin >> sourceRow >> sourceCol >> newColor;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            cin >> grid[i][j];
        }
    }

    BFS(sourceRow, sourceCol, grid, newColor);
    // display the grid now

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
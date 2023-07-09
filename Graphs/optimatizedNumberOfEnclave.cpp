#include <bits/stdc++.h>
using namespace std;

// this is the correct answer but it is giving TLE, so lets try to optimize it
void BFS(vector<vector<int>> grid, vector<vector<bool>> &vis, int i, int j, int dx[], int dy[])
{
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int x = r + dx[i];
            int y = c + dy[i];
            // check the neighbours
            if (x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 1 && !vis[x][y])
            {
                q.push({x, y});
                vis[x][y] = true;
            }
        }
    }
}
int NumberOfEnclaves(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int count = 0;
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // for the first row and last row
    for (int i = 0; i < col; i++)
    {
        if (grid[0][i] == 1 && !vis[0][i])
        {
            BFS(grid, vis, 0, i, dx, dy);
        }
        if (grid[row - 1][i] == 1 && !vis[row - 1][i])
        {
            BFS(grid, vis, row - 1, i, dx, dy);
        }
    }
    // for the first col and last col
    for (int i = 0; i < row; i++)
    {
        if (grid[i][0] == 1 && !vis[i][0])
        {
            BFS(grid, vis, i, 0, dx, dy);
        }
        if (grid[i][col - 1] == 1 && !vis[i][col - 1])
        {
            BFS(grid, vis, i, col - 1, dx, dy);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    // output the grid
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << NumberOfEnclaves(grid);

    return 0;
}
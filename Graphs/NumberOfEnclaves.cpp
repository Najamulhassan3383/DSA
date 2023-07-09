#include <bits/stdc++.h>
using namespace std;

// this is the correct answer but it is giving TLE, so lets try to optimize it
bool BFS(vector<vector<int>> grid, int i, int j, int dx[], int dy[])
{
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    vis[i][j] = true;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        // check the neighbours

        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int x = r + dx[i];
            int y = c + dy[i];
            // if any neighbour is the boundary, then the island is enclave so return true
            if (x < 0 || y < 0 || x >= row || y >= col)
            {
                cout << x << " " << y << endl;
                return false;
            }
        }
        // if the neighbour is not visited and is 1, then push it into the queue
        for (int i = 0; i < 4; i++)
        {

            int x = r + dx[i];
            int y = c + dy[i];
            if (x >= 0 && y >= 0 && x < row && y < col && !vis[x][y] && grid[x][y] == 1)
            {
                q.push({x, y});
                vis[x][y] = true;
            }
        }
    }
    return true;
}
int NumberOfEnclaves(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int count = 0;
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            if (grid[i][j] == 1)
            {
                if (BFS(grid, i, j, dx, dy))
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
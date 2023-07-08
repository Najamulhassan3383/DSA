#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int &area)
{
    int row = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        area++; // increment area for each cell visited

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < row && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int row = grid.size();
    int cols = grid[0].size();

    int maxArea = 0;
    vector<vector<bool>> visited(row, vector<bool>(cols, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                int area = 0;
                BFS(grid, visited, i, j, area);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, cols;
    cin >> row >> cols;
    vector<vector<int>> grid(row, vector<int>(cols, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];
    }
    cout << maxAreaOfIsland(grid) << "\n";

    return 0;
}
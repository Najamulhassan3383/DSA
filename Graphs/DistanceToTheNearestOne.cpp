#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> DistanceToNearestOne(vector<vector<int>> grid)
{
    int row = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> distance(row, vector<int>(cols, 0));
    vector<vector<bool>> visited(row, vector<bool>(cols, false));
    // {x, y, distance}
    queue<pair<pair<int, int>, int>> q;

    // push the 1 to queue and mark them visited
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        distance[x][y] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < row && ny >= 0 && ny < cols && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    return distance;
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
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> distance = DistanceToNearestOne(grid);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
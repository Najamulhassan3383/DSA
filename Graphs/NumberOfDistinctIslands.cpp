#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited, vector<pair<int, int>> &v, int row0, int col0)
{
    // mark is visited
    visited[row][col] = true;
    // push the current cell
    v.push_back({row - row0, col - col0});
    int delrow[] = {0, 0, 1, -1};
    int delcol[] = {1, -1, 0, 0};

    // go to all the neibouring
    for (int i = 0; i < 4; i++)
    {

        int newrow = row + delrow[i];
        int newcol = col + delcol[i];
        if (newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size() && grid[newrow][newcol] == 1 && !visited[newrow][newcol])
        {
            dfs(grid, newrow, newcol, visited, v, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                vector<pair<int, int>> v;
                dfs(grid, i, j, visited, v, i, j);
                s.insert(v);
            }
        }
    }
    return s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // number of disticnt islands:

    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> grid[i][j];
        }
    }
    cout << countDistinctIslands(grid) << endl;

    return 0;
}
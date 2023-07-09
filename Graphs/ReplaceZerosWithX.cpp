#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> grid, int dx[], int dy[])
{
    visited[x][y] = 1;
    int row = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // check if the cell is valid
        if (nx >= 0 && nx < row && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] == 'O')
        {
            dfs(nx, ny, visited, grid, dx, dy);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // declare the dx and dy array
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    // declare the visited array and initialize it with 0
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // chek for the boundaris
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O' && !visited[i][0])
        {
            dfs(i, 0, visited, mat, dx, dy);
        }
        if (mat[i][m - 1] == 'O' && !visited[i][m - 1])
        {
            dfs(i, m - 1, visited, mat, dx, dy);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 'O' && !visited[0][i])
        {
            dfs(0, i, visited, mat, dx, dy);
        }
        if (mat[n - 1][i] == 'O' && !visited[n - 1][i])
        {
            dfs(n - 1, i, visited, mat, dx, dy);
        }
    }

    // fill the cells with 'X' which are not visited
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    mat = fill(n, m, mat);

    // print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
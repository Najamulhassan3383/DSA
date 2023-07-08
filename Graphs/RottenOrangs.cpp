#include <bits/stdc++.h>
using namespace std;

// leetcode link
//  https://leetcode.com/problems/rotting-oranges/

// geeksforgeeks link
//  https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

int orangesRotting(vector<vector<int>> &grid)
{
    // get the size of the gird to make a visited array
    int rows = grid.size();
    int col = grid[0].size();

    // declare the data structure to store the rotten oranges and visited vector
    vector<vector<int>> rottenOranges(rows, vector<int>(col, 0));
    // store {{row, column}, time}
    queue<pair<pair<int, int>, int>> q;
    // get all the already rotten oranges in the queue and mark them in visited array
    int countFreshOranges = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                rottenOranges[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                countFreshOranges++;
            }
        }
    }
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    int time = 0;
    int countRottenOranges = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        time = max(time, q.front().second);
        q.pop();

        // check all the neighbors
        for (int i = 0; i < 4; i++)
        {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < col && grid[nr][nc] == 1 && rottenOranges[nr][nc] == 0)
            {
                q.push({{nr, nc}, time + 1});
                rottenOranges[nr][nc] = 2;
                countRottenOranges++;
            }
        }
    }
    return countFreshOranges == countRottenOranges ? time : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, coloumns;
    // cout << "enter the number of rows and coloumns:" << endl;
    cin >> rows >> coloumns;
    vector<vector<int>> grid(rows, vector<int>(coloumns, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            // cout << "enter the value at " << i << " " << j << endl;
            cin >> grid[i][j];
        }
    }

    cout << orangesRotting(grid) << endl;
    // output the grid
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < coloumns; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
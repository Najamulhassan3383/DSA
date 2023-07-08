#include "./Graphs.h"
#include <iostream>
#include <vector>
using namespace std;

Graphs::Graphs(int nodes, int edges = 0)
{
    this->nodes = nodes;
    this->edges = edges;

    // This is important; otherwise, it will give a segmentation fault
    graph.resize(nodes + 1);
}
Graphs::Graphs(int nodes)
{
    this->nodes = nodes;
    this->edges = 0;
    graph.resize(this->nodes + 1);
}

Graphs::Graphs()
{
    this->nodes = 0;
    this->edges = 0;
    graph.resize(this->nodes + 1);
}

vector<vector<int>> Graphs::GetList()
{
    return this->graph;
}

void Graphs::buildGraphList()
{
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;

        // Mark the edge between node1 and node2
        graph[node1].push_back(node2);

        // Mark the edge between node2 and node1
        graph[node2].push_back(node1);
    }
}

void Graphs::ChangeMatrixToList(vector<vector<int>> matrix)
{
    // function to convert matrix to list for graph
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {

            if (matrix[i][j] == 1)
            {
                graph[i].push_back(j);
            }
        }
    }
}

void Graphs::DisplayGraph()
{
    for (size_t i = 0; i <= nodes; i++)
    {
        std::cout << i << " -> ";
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graphs::BFS(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    // mark it visited
    visited[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;

        // check there neighbors
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
        {
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
            {

                int neighborRow = r + deltaRow;
                int neighborCol = c + deltaCol;
                if (neighborRow >= 0 && neighborRow < grid.size() && neighborCol >= 0 && neighborCol < grid[0].size() && visited[neighborRow][neighborCol] == false && grid[neighborRow][neighborCol] == 1)
                {
                    // mark it visited
                    visited[neighborRow][neighborCol] = true;
                    // cout << neighborCol << " " << neighborRow << endl;
                }
            }
        }
    }
}

std::vector<int> Graphs::BFS(int source)
{
    std::vector<int> bfs;
    std::vector<bool> visited(nodes + 1, false);
    std::queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Mark as visited
        visited[node] = true;
        bfs.push_back(node);

        // Explore all neighbors
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return bfs;
}

std::vector<int> Graphs::DFS(int source)
{
    std::vector<int> dfs;
    std::vector<int> visited(nodes + 1, false);
    std::stack<int> s;
    s.push(source);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        // Mark as visited
        visited[node] = true;
        dfs.push_back(node);

        // Explore all neighbors
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    return dfs;
}

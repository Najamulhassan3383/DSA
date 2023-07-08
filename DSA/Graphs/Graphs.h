#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graphs
{
private:
    int nodes;
    int edges;
    std::vector<std::vector<int>> graph;

public:
    Graphs(int nodes, int edges);
    Graphs(int nodes);
    Graphs();
    void buildGraphList();
    vector<vector<int>> GetList();
    void ChangeMatrixToList(vector<vector<int>> matrix);
    void DisplayGraph();
    std::vector<int> BFS(int source);
    void BFS(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited);
    std::vector<int> DFS(int source);
};

#endif

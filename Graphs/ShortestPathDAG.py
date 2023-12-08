# shortest path in directed acyclic graph

from typing import List

class Solution:
    def topologicalSort(self, node, visited, stack, graph):
        visited[node] = True
        for neighbour in graph[node]:
            if visited[neighbour[0]] == False:
                self.topologicalSort(neighbour[0], visited, stack, graph)
        stack.append(node)
        
    def shortestPath(self, n : int, m : int, edges : List[List[int]]) -> List[int]:
        # make a dictioanry for graph
        graph = {}
        for i in range(n):
            graph[i] = []
        for j in range(m):
            start = edges[j][0]
            end = edges[j][1]
            wt = edges[j][2]
            graph[start].append([end, wt])
        stack = []
        visited = [False] * n
        distance = [float('inf')] * n
        for i in range(n):
            if visited[i] == False:
                self.topologicalSort(i, visited, stack, graph)
        
        distance[0] = 0
        while stack:
            node = stack.pop()
            if distance[node] != float('inf'):
                for neighbour in graph[node]:
                    if distance[neighbour[0]] > distance[node] + neighbour[1]:
                        distance[neighbour[0]] = distance[node] + neighbour[1]
            else:
                distance[node] = -1
        return distance
    
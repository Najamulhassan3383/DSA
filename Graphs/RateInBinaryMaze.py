from typing import List
from heapq import heappop, heappush

class Solution:
    
    
    def shortestPath(self, grid: List[List[int]], source: List[int], destination: List[int]) -> int:
        """find the shortest path from source to destination
        Args:
            grid (list[list[int]]): binary grid
            source (list[int]): source coordinates
            destination (list[int]): destination coordinates
        """
        m  = len(grid)  #rows
        n = len(grid[0]) #columns
        #make a distace matrix to store the distance of each node from source
        distance = [[float('inf') for _ in range(n)] for _ in range(m)]
        queue = []
        queue.append((source,0))
        x = [0,1,0,-1]
        y = [1,0,-1,0]
        
        while queue:
            node,dis = queue.pop(0)
            # explore the neibhours of the node
            for i in range(4):
                new_x = node[0] + x[i]
                new_y = node[1] + y[i]
                
                if 0 <= new_x < m and 0 <= new_y < n and grid[new_x][new_y] == 1 and dis + 1 < distance[new_x][new_y]:
                    distance[new_x][new_y] = dis + 1
                    
                    
                    #check for the destination node
                    if (new_x,new_y) == tuple(destination):
                        return distance[new_x][new_y]
                    queue.append(([new_x,new_y],dis + 1))
        return -1                   

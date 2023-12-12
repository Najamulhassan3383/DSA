from typing import List

class Solution:
    def CheapestFLight(self,n,flights,src,dst,k):
        #build graph
        graph = {}
        for i  in range(n):
            graph[i] = []
        for flight in flights:
            graph[flight[0]].append((flight[1],flight[2]))
        #print(graph)
        queue = []
        
        distances = [float('inf') for _ in range(n)]
        distances[src] = 0
        queue.append((src,0,0))
        while queue:
            node,cost,stop = queue.pop(0)
            #print(node,cost,stop)
            
            #explore the neighbours
            for neighbour in graph[node]:
                if stop <= k and cost + neighbour[1] < distances[neighbour[0]]:
                    distances[neighbour[0]] = cost + neighbour[1]
                    queue.append((neighbour[0],cost + neighbour[1],stop+1))
        if distances[dst] == float ('inf'):
            return -1
        return distances[dst]

  
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1
sol = Solution()
print(sol.CheapestFLight(n,flights,src,dst,k))
       
             
class Solution:
    def bfs(self, src,visted,graph, distance):
        queue = []
        queue.append(src)
        visted[src] = True
        distance[src] = 0
        level = 0
        while queue:
            node = queue.pop(0)
            
            for neighbour in graph[node]:
                if visted[neighbour[0]] == False:
                    visted[neighbour[0]] = True
                    if distance[node] + 1 < distance[neighbour]:
                        distance[neighbour] = distance[node] + 1
                    
                    queue.append(neighbour[0])
    def shortestPath(self, edges, n, m, src):
        
        graph = {}
        for i in range (n):
            graph[i] = []
        
        distance = [float('inf')] * n
        visited = [False] * n
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        distance[src] = 0
        
        self.bfs(src, visited, graph, distance)
        for i in range(n):
            if distance[i] == float('inf'):
                distance[i] = -1
        return distance
        
        


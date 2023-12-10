from heapq import heappush, heappop
class Solution:

    #Function to find the shortest distance of all the vertices
    #from the source vertex S.
    def dijkstra(self, V, adj, S):
        """ Dijkstra's algorithm to find the shortest path from source vertex to all other vertices
        Args:
            V (int):number of edges
            adj (list[list]): adjacency list
            S (int): source vertex
        """
        heap = [(0, S)]
        visited = set()
        distances = [float('inf') for _ in range(V)]
        
        while heap:
            dis , node = heappop(heap)
            
            visited.add(node)
            
            #explore the neibhours fo the node
            for neibhour,weight in adj[node]:
                if neibhour not in visited:
                    if dis + weight < distances[neibhour]:
                        distances[neibhour] = dis + weight
                        heappush(heap,(dis + weight,neibhour))
                        
        return distances
    
        
        

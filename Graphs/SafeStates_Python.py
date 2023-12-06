from typing import List

class Solution:
    
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        number = len(graph)
        visited = [0 for i in range(number)]
        pathVisited = [0 for i in range(number)]
        ans =set()
        

        for i in range(number):
            if visited[i] == 0:
                self.dfsCheck(i, graph, visited, pathVisited)
        
        for i in range(number):
            if(pathVisited[i] == 0):
                print(i)
                ans.add(i)

        return sorted(ans)

    def dfsCheck(self, node, graph, visited, pathVisited):
        # mark the node visited
        
        visited[node] = 1
        pathVisited[node] = 1
        

        for i in graph[node]:
            if visited[i] != 1:
                if self.dfsCheck(i, graph, visited, pathVisited):
                    return True
            elif pathVisited[i] == 1:
                return True
            
        
        pathVisited[node] = 0
        return False

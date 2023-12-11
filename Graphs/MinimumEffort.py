from heapq import heappush, heappop
class Solution:
        
    def MinimumEffort(self, a):
        """Find the minimum effort required to reach the end of the array
        Args:
            a (list[int]): list of integers
        """
        m  = len(a)  #rows
        n = len(a[0]) #columns
        #make a distace matrix to store the distance of each node from source , initilize it to infinty for each node
        
        
        
        
        distance = [[float('inf') for _ in range(n)] for _ in range(m)]
        heap = []
        destination = [m-1,n-1]
        source = [0,0]
        distance[0][0] = 0
        heappush(heap,(0,source))
        x = [0,1,0,-1]
        y = [1,0,-1,0]
        
        while heap:
            dis,node = heappop(heap)
            # explore the neibhours of the node
            for i in range(4):
                new_x = node[0] + x[i]
                new_y = node[1] + y[i]
                #take absolute difference between the current node and the neibhour node
                
                if 0 <= new_x < m and 0 <= new_y < n:
                    abs_distance = abs(a[node[0]][node[1]] - a[new_x][new_y])
                    maxi_dis = max(abs_distance,dis)
                    if maxi_dis < distance[new_x][new_y]:
                        distance[new_x][new_y] = maxi_dis
                            #check for the destination node
                        if (new_x,new_y) == tuple(destination):
                            return distance[new_x][new_y]
                        heappush(heap,(distance[new_x][new_y],[new_x,new_y]))
                        
                    
                    
                    
        return -1
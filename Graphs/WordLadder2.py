# import collections
# class Solution:
#     #implement bfs on the graph, and print all the paths from start node to end node
    

#     def find_all_paths_bfs(self, graph, start, end):
#         """
#         Find all paths from start to end in a graph using BFS.

#         Args:
#             graph: Dict representing the graph.
#             start: Start node.
#             end: End node.

#         Returns:
#             List of all shortest paths from start to end.
#         """
#         queue = collections.deque([(start, [start])])
#         paths = []
#         visited = set()

#         while queue:
#             current, path = queue.popleft()

#             if current == end:
#                 paths.append(path)

#             if current not in visited:
#                 visited.add(current)
#                 for neighbor in graph[current][1:]:
#                     if neighbor not in visited:
#                         queue.append((neighbor, path + [neighbor]))
#         min_len = min([len(path) for path in paths])
#         return [path for path in paths if len(path) == min_len]

    
        
                    
                    


        
    
#     def findSequences(self, startWord, targetWord, wordList):
#         if targetWord not in wordList:
#             return 0
#         queue = []
#         queue.append((startWord,1))
#         graph = dict()
        
#         #insitilze the graph dictionary
#         for word in wordList:
#             graph[word]  = [False]
        
#         if startWord not in graph:
#             graph[startWord] = [False]
            
#         graph[startWord][0] = True
#         # del graph[startWord]
#         while queue:
#             word,steps = queue.pop(0)
            
#             graph[word][0] = True
            
#             if word == targetWord:
#                 # print(graph)
#                 return self.find_all_paths_bfs(graph,startWord,targetWord)
            
#             for i in range(len(word)):
                 
#                 for char in "abcdefghijklmnopqrstuvwxyz":
#                     if char == word[i]:
#                         continue
#                     newWord = word[:i] + char + word[i+1:]
#                     if newWord in graph and graph[newWord][0] == False:
#                         queue.append((newWord,steps+1))
                        
#                         graph[word].append(newWord)
#         return []
    
# start = "gedk"
# end = "geek"
# wordList = ["geek", "gefk"]

# print(Solution().findSequences(start,end,wordList))

from collections import deque

from collections import deque

class Solution:
    def findSequences(self, startWord, targetWord, wordList):
        if targetWord not in wordList:
            return 0

        queue = deque()
        queue.append([startWord])

        visited = set(wordList)
        visited.add(startWord)

        level = 0
        usedOnLevel = set(startWord)
        ans = []

        while queue:
            
            current_vec = queue.popleft()
            # print("queue", queue)

            # Delete the words used in the previous level
            if len(usedOnLevel) > level:
                # print("i am here")
                level += 1
                # print("before removing",visited)
                visited -= usedOnLevel
                # print("after removing from visted",visited)

            # Clear the usedOnLevel set
            usedOnLevel.clear()
            
            word = current_vec[-1]

            if word == targetWord:
                # Change this condition to allow vectors of equal length
                # print(current_vec)
                if not ans or len(current_vec) <= len(ans[0]):
                    ans.append(current_vec)

            for i in range(len(word)):
                for char in "abcdefghijklmnopqrstuvwxyz":
                    if char == word[i]:
                        continue

                    newWord = word[:i] + char + word[i+1:]
                    if newWord in visited:
                        # print("to be added",newWord)
                        current_vec.append(newWord)
                        # print("after adding", current_vec)
                        queue.append(current_vec.copy())
                        # print("after adding to queue", queue)
                        usedOnLevel.add(newWord)
                        # print("usedOnLevel", usedOnLevel)
                        current_vec.pop()

        return ans


            
start = "gedk"
end = "geek"
wordList = ["geek", "gefk"]
sol = Solution()

print(sol.findSequences(start,end,wordList))     
        

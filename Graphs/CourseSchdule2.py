from collections import deque
from typing import List
        
#this is my submission to leetcode problem titiled "course Schedule 2"

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(numCourses)}
        indegrees = [0] * numCourses

        for prerequisite in prerequisites:
            course, prereq = prerequisite
            graph[prereq].append(course)
            indegrees[course] += 1

        visited = []
        my_queue = deque()

        for course in range(numCourses):
            if indegrees[course] == 0:
                my_queue.append(course)
        print(graph)
        print(indegrees)
        while my_queue:
            node = my_queue.popleft()
            visited.append(node)

            for neighbor in graph[node]:
                indegrees[neighbor] -= 1
                if indegrees[neighbor] == 0:
                    my_queue.append(neighbor)

        if len(visited) == numCourses:
            return visited
        return []

        
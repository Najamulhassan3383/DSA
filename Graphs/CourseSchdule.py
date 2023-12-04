# Description: This file contains the implementation of the CourseSchedule class
from collections import deque
from typing import List
def canFinish( numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i: [] for i in range(numCourses)}
        indegrees = [0] * numCourses

        for prerequisite in prerequisites:
            course, prereq = prerequisite
            graph[prereq].append(course)
            indegrees[course] += 1

        visited = 0
        my_queue = deque()

        for course in range(numCourses):
            if indegrees[course] == 0:
                my_queue.append(course)

        while my_queue:
            node = my_queue.popleft()
            visited +=1

            for neighbor in graph[node]:
                indegrees[neighbor] -= 1
                if indegrees[neighbor] == 0:
                    my_queue.append(neighbor)

        return visited == numCourses

        





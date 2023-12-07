def findOrder(self, alien_dict):
    graph = {}
    
    # Initialize the graph and in-degrees
    for word in alien_dict:
        for c in word:
            if c not in graph:
                graph[c] = set()

    # Build the graph
    for i in range(len(alien_dict)-1):
        s1 = alien_dict[i]
        s2 = alien_dict[i+1]
        min_length = min(len(s1), len(s2))
        if len(s1) > len(s2) and s1[:min_length] == s2[:min_length]:
            return ""

        for j in range(min(len(s1), len(s2))):
            if s1[j] != s2[j]:
                key = s1[j]
                value = s2[j]
                graph[key].add(value)
                break

    # Perform topological sort
    result = []
    visited = {}

    def dfs(c):
        if c in visited and visited[c] == 1:
            return False  # Node is part of a cycle
        if c in visited and visited[c] == 2:
            return True  # Node has been visited and processed

        visited[c] = 1  # Mark node as being visited

        if c in graph:
            for nei in graph[c]:
                if not dfs(nei):
                    return False  # Cycle detected

        visited[c] = 2  # Mark node as visited and processed
        result.append(c)
        return True

    for c in graph:
        if not dfs(c):
            return ""

    result.reverse()
    return "".join(result)

alien_dict = ['baa', 'abcd', 'abca', 'cab', 'cad']
result = findOrder(None, alien_dict)
print("res")
print(result)

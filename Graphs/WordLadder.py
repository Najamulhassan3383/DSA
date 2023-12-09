class Solution:
    def wordLadderLength(self, startWord, targetWord, wordList):
        if targetWord not in wordList:
            return 0
        queue = []
        queue.append((startWord,1))
        visited = dict()
        
        #insitilze the visited dictionary
        for word in wordList:
            visited[word]  = False
        
        visited[startWord] = True
        del visited[startWord]
        while queue:
            word,steps = queue.pop(0)
            
            if word == targetWord:
                return steps
            
            for i in range(len(word)):
                 
                for char in "abcdefghijklmnopqrstuvwxyz":
                    if char == word[i]:
                        continue
                    newWord = word[:i] + char + word[i+1:]
                    if newWord in visited:
                        queue.append((newWord,steps+1))
                        del visited[newWord]
        return 0
            
        
        

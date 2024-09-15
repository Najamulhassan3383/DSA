def longest_substring_with_k_distinct_letters(s, k):
    left = right = maxi = 0
    count = {}
    for right in range(len(s)):
        end = s[right]
        if end in count:
            count[end] += 1
        else:
            count[end] = 1
        while len(count) > k:
            start = s[left]
            count[start] -= 1
            if count[start] == 0:
                del count[start]
            left += 1
        maxi = max(maxi, right-left+1)
        right += 1
    return maxi
        

s = "abaaacccccciiiii"
k = 2
print(longest_substring_with_k_distinct_letters(s,k))
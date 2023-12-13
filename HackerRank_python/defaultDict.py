from collections import defaultdict
integer_input = input()
n, m = list(map(int, integer_input.split()))
# print (n,m)
d = defaultdict(list)
for i in range(n):
    char = input()
    d[char].append(i+1)

# print(d)
for j in range(m):
    char = input()
    if char in d:
        for i in d[char]:
            print(i, end = " ")
        print()
    else:
        print(-1)
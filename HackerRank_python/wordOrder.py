from collections import OrderedDict
number = int(input())
d = OrderedDict()
for i in range(number):
    string = input()
    if string in d:
        d[string] += 1
    else:
        d[string] = 1
print(len(d))
for i in d:
    print(d[i], end = " ")
    
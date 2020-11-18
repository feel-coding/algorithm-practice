n = int(input())
from sys import stdin
li = []
for i in range(n):
    li.append(list(map(int, stdin.readline().split())))
    li[i].extend([0] * (n - 1 - i))
for i in range(n - 2, -1, -1):
    for j in range(i + 1):
        li[i][j] = max(li[i][j] + li[i + 1][j], li[i][j] + li[i + 1][j + 1])
print(li[0][0])
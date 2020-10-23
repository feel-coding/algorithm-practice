from sys import stdin
m, n = list(map(int, stdin.readline().split()))
matrix = []
count = 0
minus = 0
zero = 0
import collections
q = collections.deque()
one = []
for i in range(n):
    temp = list(map(int, stdin.readline().split()))
    matrix.append(temp)
    count += temp.count(1)
    minus += temp.count(-1)
    zero += temp.count(0)
    for j in range(m):
        if temp[j] == 1:
            q.append((i, j, 0))
if zero == 0:
    print(0)
else:
    day = 0
    ripen = 0
    result = 0
    visited = [[False] * m for i in range(n)]
    while q:
        cur = q.popleft()
        if not visited[cur[0]][cur[1]]:
            visited[cur[0]][cur[1]] = True
            matrix[cur[0]][cur[1]] = 1
            ripen += 1
            result = cur[2]
        else:
            continue
        if cur[0] + 1 < n and matrix[cur[0] + 1][cur[1]] == 0 and not visited[cur[0] + 1][cur[1]]:
            q.append((cur[0] + 1, cur[1], cur[2] + 1))
        if cur[1] + 1 < m and matrix[cur[0]][cur[1] + 1] == 0 and not visited[cur[0]][cur[1] + 1]:
            q.append((cur[0], cur[1] + 1, cur[2] + 1))
        if cur[0] - 1 >= 0 and matrix[cur[0] - 1][cur[1]] == 0 and not visited[cur[0] - 1][cur[1]]:
            q.append((cur[0] - 1, cur[1], cur[2] + 1))
        if cur[1] - 1 >= 0 and matrix[cur[0]][cur[1] - 1] == 0 and not visited[cur[0]][cur[1] - 1]:
            q.append((cur[0], cur[1] - 1, cur[2] + 1))
    if ripen == m * n - minus:
        print(result)
    else:
        print(-1)
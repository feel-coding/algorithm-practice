from sys import stdin
n = int(input())
m = int(input())
location = list(map(int, stdin.readline().split()))
gap = []
gap.append((location[0] - 0) * 2)
for i in range(1, m):
    gap.append(location[i] - location[i - 1])
gap.append((n - location[-1]) * 2)
a, b = divmod(max(gap), 2)
if b == 0:
    print(a)
else:
    print(a + 1)
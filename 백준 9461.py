test_case = int(input())
for i in range(test_case):
    n = int(input())
    li = [1] * n
    for j in range(3, n):
        li[j] = li[j - 3] + li[j - 2]
    print(li[n - 1])
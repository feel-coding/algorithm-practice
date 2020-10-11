from sys import stdin
n, l = list(map(int, stdin.readline().split()))
li = []
for i in range(n):
    li.append(list(map(int, stdin.readline().split())))
count = 0
for i in range(n):
    previous = -1
    seq = []
    maximum = -1
    for j in range(n):
        if j == 0:
            maximum = li[i][j]
            seq.append([li[i][j], 1])
        else:
            if li[i][j] > maximum:
                maximum = li[i][j]
            if previous == li[i][j]:
                seq[-1][1] = seq[-1][1] + 1
            else:
                seq.append([li[i][j], 1])
        previous = li[i][j]
    if len(seq) == 1:
        count += 1
    elif n / l < len(seq):
        pass
    else:
        for k in range(len(seq)):
            if k > 0 and abs(seq[k - 1][0] - seq[k][0]) != 1:
                break
            elif seq[k][0] != maximum and seq[k][1] < l:
                break
            elif 0 < k < len(seq) - 1:
                if seq[k - 1][0] > seq[k][0] and seq[k + 1][0] > seq[k][0] and seq[k][1] < l * 2:
                    break
            else:
                if k == len(seq) - 1:
                    count += 1
for i in range(n):
    previous = -1
    seq = []
    maximum = -1
    for j in range(n):
        if j == 0:
            maximum = li[j][i]
            seq.append([li[j][i], 1])
        else:
            if li[j][i] > maximum:
                maximum = li[j][i]
            if previous == li[j][i]:
                seq[-1][1] = seq[-1][1] + 1
            else:
                seq.append([li[j][i], 1])
        previous = li[j][i]
    if len(seq) == 1:
        count += 1
    elif n / l < len(seq):
        pass
    else:
        for k in range(len(seq)):
            if k > 0 and abs(seq[k - 1][0] - seq[k][0]) > 1:
                break
            elif seq[k][0] != maximum and seq[k][1] < l:
                break
            elif 0 < k < len(seq) - 1:
                if seq[k - 1][0] > seq[k][0] and seq[k + 1][0] > seq[k][0] and seq[k][1] < l * 2:
                    break
            else:
                if k == len(seq) - 1:
                    count += 1
print(count)
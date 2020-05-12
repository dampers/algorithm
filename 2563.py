c = [[0 for i in range(100)] for i in range(100)]

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    for j in range(a-1, a+9):
        for k in range(b-1, b+9):
            c[j][k] = 1

cnt = 0
for i in range(100):
    for j in range(100):
        if c[i][j]==1:
            cnt += 1
print(cnt)

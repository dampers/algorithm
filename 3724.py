import sys
input = sys.stdin.readline
tc = int(input())
for t in range(tc):
    m, n = map(int, input().split())
    v = [input().split() for _ in range(n)]
    ans = 1
    mx = 1
    for i in range(n):
        mx *= int(v[i][0])
    for j in range(m):
        tmp = 1
        for i in range(n):
            tmp *= int(v[i][j])
        if mx <= tmp:
            mx = tmp
            ans = j
            
    print(ans+1)
    

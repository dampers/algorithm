n = int(input())

num = [int(input) for i in range(n)]

#bubble sort

for i in range(n-1):
    for j in range(n-i-1):
        if num[j]>num[j+1]:
            num[j], num[j+1] = num[j+1], num[j]

for i in num:
    print(i)

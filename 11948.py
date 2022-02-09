abcd = []
ef = []
tmp = 0
for i in range(4):
    tmp = int(input())
    abcd.append(tmp)
for i in range(2):
    tmp = int(input())
    ef.append(tmp)
abcd.sort()
ef.sort()
print(abcd[1]+abcd[2]+abcd[3]+ef[1])

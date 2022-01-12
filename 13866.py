status = list(map(int, input().split()))
status.sort()

print(abs(status[0]+status[3]-status[1]-status[2]))

import heapq
from operator import itemgetter

classes = []

def greedy(classes):
    minheap = []
    for i, time in enumerate(sorted(classes, key=itemgetter(0))):
        if i == 0:
            heapq.heappush(minheap, time[1])
        elif time[0] < minheap[0]:
            heapq.heappush(minheap, time[1])
        else:
            heapq.heappushpop(minheap, time[1])
    return len(minheap)

if __name__ == "__main__":
    N = int(input())
    for i in range(N):
        classes.append(list(map(int, input().split())))
    print(greedy(classes))
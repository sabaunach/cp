n=int(input())
l = [*map(int,input().split())]
pos = [0] * n
pos[0] = 1
for i in range(n-1):
    pos[1+l[i]] = i+2
print(*pos)
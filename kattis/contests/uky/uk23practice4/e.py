n = int(input())
l = [*map(int,input().split())]
good = [True] * n
c = n
x = 0
while c > 1:
    d = (l[x] - 1) % c
    while d:
        x = (x+1) % n
        if good[x]:
            d -= 1

    good[x] = False
    c -= 1
    x = (x+1) % n
    while not good[x]:
        x = (x+1) % n

for i in range(n):
    if good[i]:
        print(i+1)
        break

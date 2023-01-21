n,m=map(int, input().split())
vals = [int(input()) for _ in range(m)]
all = [0] * m
c = 0
while c < n:
    b = False
    placed = False
    for i in range(m):
        if all[i] < vals[i]:
            c += 1
            all[i] += 1
            placed = True
            if c == n:
                b = True
                break
    if not placed:
        break
    if b:
        break
for v in all:
    print(v)

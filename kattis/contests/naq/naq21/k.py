m, n = map(int, input().split())
st = [*map(int, input().split())]

ps1 = [0]*m
ps1[0] = st[0]

ps2 = [0]*m
ps2[0] = st[-1]

for i in range(1, m):
    ps1[i] = ps1[i-1] + st[i]
    ps2[i] = ps2[i-1] + st[m-i-1]

ss = {0}
for p in ps1:
    ss.add(p)
for p in ps2:
    ss.add(p)

for i in range(m):
    for j in range(m-1-i):
        ss.add(ps1[i]+ps2[j])

for _ in range(n):
    q = int(input())
    print('Yes' if q in ss else 'No')

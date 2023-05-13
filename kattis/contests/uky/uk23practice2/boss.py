from collections import *

def read(f=int):
    return map(f,input().split())

def lca(a,b):
    if depth[a] < depth[b]:
        return lca(b,a)

    d = depth[a] - depth[b]
    for i in range(17,-1,-1):
        if d & (1 << i):
            a = anc[i][a]
    if a == b:
        return a

    for i in range(17,-1,-1):
        if anc[i][a] != anc[i][b]:
            a = anc[i][a]
            b = anc[i][b]
    return anc[0][a]

n,m=read()

anc = [[-1]*n for _ in range(18)]
adj = [set() for _ in range(n)]
for i in range(1,n):
    p,=read()
    p-=1
    anc[0][i] = p
    adj[p].add(i)

depth = [10**18]*n
depth[0] = 0

l = deque([0])
while l:
    v = l.popleft()
    for vv in adj[v]:
        if depth[vv] > depth[v] + 1:
            depth[vv] = depth[v]+1
            l.append(vv)

for i in range(1,18):
    for j in range(n):
        anc[i][j] = -1 if anc[i-1][j] == -1 else anc[i-1][anc[i-1][j]]

for _ in range(m):
    a,b = read()
    a-=1
    b-=1
    # print(a,b,lca(a,b))
    print('No' if lca(a,b) == b else 'Yes')
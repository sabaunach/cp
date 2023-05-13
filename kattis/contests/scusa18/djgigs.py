from functools import lru_cache
from bisect import bisect_left


def read(): return map(int, input().split())


# @lru_cache(maxsize=None)
def dp(n,t):
    a = 0
    l = bisect_left(S,t)
    # print(l)
    for i in range(l,g):
        if dist[n][V[i]] + t <= S[i]:
            a = max(a,M[i] + dp(V[i],E[i]))
    # print(n,t,a)
    return a

g,k,r=read()
dist = [[10**18]*k for _ in range(k)]
for i in range(k):dist[i][i] = 0
for _ in range(r):
    a,b,t = read()
    a-=1
    b-=1
    dist[a][b] = dist[b][a] = t
for c in range(k):
    for a in range(k):
        for b in range(k):
            dist[a][b] = min(dist[a][b], dist[a][c] + dist[c][b])

l = []
for _ in range(g):
    v,s,e,m = read()
    l.append((s,e,v-1,m))
l.sort()
S,E,V,M = zip(*l)
# print(S,E,V,M,sep='\n')

print(dp(0,0))
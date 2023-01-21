from collections import *
from heapq import *

def read(f=int):
    return map(f,input().split())

n,m = read()
adj = defaultdict(set)
for _ in range(m):
    a,b=  read()
    a-=1
    b-=1
    adj[a].add(b)
    adj[b].add(a)

sz = [int(input()) for _ in range(n)]
h = [(sz[i], i) for i in adj[0]]
heapify(h)
vis = {0}
v = sz[0]
while h:
    s,a = heappop(h)
    if a in vis:continue
    vis.add(a)
    # print(s,a)
    if s < v:
        v += s
        for nn in adj[a]:
            heappush(h,(sz[nn],nn))
        # print(v)
    else:
        break
print(v)
from collections import defaultdict
import heapq

n,m,s,t = map(int, input().split())
orig = [[0]*n for _ in range(n)]
copy = [[0]*n for _ in range(n)]
adj = [set() for _ in range(n)]
for _ in range(m):
    u,v,c = map(int, input().split())
    orig[u][v] = c
    copy[u][v] = c
    adj[u].add(v)

totalflow = 0
while True:
    vis = set()
    prev = {}
    flow = defaultdict(int)

    flow[s] = 10**13

    pq = [(-flow[s], s)]

    while pq:
        maxflow, maxloc = heapq.heappop(pq)
        maxflow *= -1

        if maxloc == t:
            break

        for i in adj[maxloc]:
            cap = min(maxflow, copy[maxloc][i])
            if i not in vis and flow[i] < cap:
                flow[i] = cap
                prev[i] = maxloc

                vis.add(i)
                heapq.heappush(pq, (-flow[i], i))


    if flow[t] == 0:
        break
    totalflow += maxflow

    cur = n-1
    while cur in prev:
        nxt = prev[cur]
        copy[nxt][cur] -= maxflow
        copy[cur][nxt] += maxflow

        if copy[nxt][cur] == 0:
            adj[nxt].remove(cur)
        adj[cur].add(nxt)

        cur = nxt
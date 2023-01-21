import heapq

n,s,t=map(int, input().split())
weights = []
for i in range(n):
    weights.append([*map(int, input().split())])

dis = [10**99] * n
dis[s] = 0
vis = set()
pq = [(0, s)]
while pq:
    d, n = heapq.heappop(pq)

    if n == t:
        print(d)
        break

    if n in vis:
        continue
    vis.add(n)

    for j, dd in enumerate(weights[n]):
        if d + dd < dis[j]:
            dis[j] = d + dd
            heapq.heappush(pq, (dis[j], j))

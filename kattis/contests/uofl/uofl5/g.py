from collections import defaultdict

m,n = map(int, input().split())
names = []
times = []
for i in range(m):
    name, _, *days = input().split()
    names.append(name)
    times.append([*map(int, days)])

k = 0
while True:
    k += 1

    adj = [[0]*(m+n+2) for _ in range(m+n+2)]
    for i in range(1, m+1):
        adj[0][i] = k
    for i in range(m):
        for j in times[i]:
            adj[i + 1][j + m] = 1
    for i in range(m + 1, m + n + 1):
        adj[i][m + n + 1] = 2

    totalflow = 0
    while True:
        prev = {}
        flow = defaultdict(int)
        vis = set()

        flow[0] = 3*n

        while True:
            maxloc = -1
            maxflow = 0
            for i in range(m+n+2):
                if i not in vis and maxflow < flow[i]:
                    maxflow = flow[i]
                    maxloc = i

            if maxloc in (-1, m+n+1):
                break
            vis.add(maxloc)

            for i in range(m+n+2):
                cap = min(maxflow, adj[maxloc][i])
                if flow[i] < cap:
                    prev[i] = maxloc
                    flow[i] = cap

        if maxloc == -1:
            assert flow[m+n+1] == 0
            break
        totalflow += flow[m+n+1]

        cur = m+n+1
        while cur in prev:
            nxt = prev[cur]
            adj[nxt][cur] -= flow[m+n+1]
            adj[cur][nxt] += flow[m+n+1]
            cur = nxt

    if totalflow == 2*n:
        break

print(k)

l = [[] for _ in range(n)]
for i in range(m):
    for j in times[i]:
        if adj[i+1][j+m] == 0:
            l[j-1].append(names[i])
for i in range(n):
    print('Day %d: %s %s' % (i+1, *l[i]))
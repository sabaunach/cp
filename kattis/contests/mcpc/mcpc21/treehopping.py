from collections import defaultdict, deque


def lca(a,b):
    # print('lca')
    if depth[a] < depth[b]:
        a,b=b,a
    diff = depth[a] - depth[b]
    i = 0
    while 1<<i  <= diff:
        if diff & (1<<i):
            a = anc[i][a]
        i += 1
    if a==b:
        return a
    for i in range(17, -1, -1):
        if anc[i][a] != anc[i][b]:
            a = anc[i][a]
            b = anc[i][b]
    return anc[0][a]

def dist(a,b):
    # print('dist')
    return depth[a] + depth[b] - 2*depth[lca(a,b)]

t=  int(input())
for _ in range(t):
    # print('new loop')
    n=int(input())
    adj = defaultdict(list)
    for j in range(n-1):
        a,b=map(int, input().split())
        adj[a-1].append(b-1)
        adj[b-1].append(a-1)
    perm = []
    for j in range(n):
        perm.append(int(input())-1)

    anc = [[1234]*n for _ in range(18)]
    depth = [10**18] * n
    depth[perm[0]] = 0
    anc[0][perm[0]] = -1

    d = deque([perm[0]])
    while d:
        node = d.popleft()
        # print('node=',node)
        for e in adj[node]:
            if depth[node] + 1 < depth[e]:

                depth[e] = depth[node] + 1
                anc[0][e] = node
                d.append(e)
    # print(depth)
    k = 1
    while (1 <<k) < n:
        # print(k)
        for i in range(n):
            anc[k][i] = -1 if anc[k-1][i] == -1 else anc[k-1][anc[k-1][i]]
        k += 1
    # print(*anc)

    for i in range(n-1):
        # print('i=',i)
        # print(perm[i]+1,perm[i+1]+1,dist(perm[i], perm[i+1]))
        if dist(perm[i], perm[i+1]) > 3:
            print(0)
            break
    else:
        print(1)
    # print('done')
    # print('done')

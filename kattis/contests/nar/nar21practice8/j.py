k=int(input())
lims = [[]] * k
flows = [0] * k
for i in range(k):
    t,a,b = map(int, input().split())
    flows[i] = t
    lims[i] = [a,b]

def dot(a,b):
    return sum(aa*bb for aa,bb in zip(a,b))

precomp = [[] for _ in range(k)]
sums = [[] for _ in range(k)]

for i in range(k):
    for j in range(2**(k-1)):
        point = [0]*k
        for b in range(k-1):
            index = b + (b >= i)
            point[index] = lims[index][(j >> b) & 1]

        precomp[i].append(point)
        sums[i].append(sum(point))

def process():
    tau,phi = map(int, input().split())
    target = tau*phi

    import heapq
    vis = set()
    pq = [(sum(arr[0] for arr in lims), set(range(k)), -1)]
    while pq:
        psum, unused, sb = pq[0]

        rep = tuple(sorted(unused)) + (sb,)
        if rep in vis:
            heapq.heappop(pq)
            continue
        vis.add(rep)

        if psum >= phi:
            mindot = 10**99
            maxdot = 0
            while pq:
                psum, unused, sb = heapq.heappop(pq)
                point = [0] * k
                psum -= lims[sb][1]
                if lims[sb][0] <= phi - psum <= lims[sb][1]:
                    for i in range(k):
                        point[i] = lims[i][i not in unused]
                    point[sb] = phi-psum
                    dotv = dot(flows, point)
                    mindot = min(mindot, dotv)
                    maxdot = max(maxdot, dotv)
                    if mindot <= target <= maxdot:
                        return 'yes'
        else:
            heapq.heappop(pq)
            for u in unused:
                heapq.heappush(pq, (psum - lims[u][0] + lims[u][1], unused - {u}, u))

    return 'no'

r = int(input())
for _ in range(r):
    print(process())

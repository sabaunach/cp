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

    mindot = 10**99
    maxdot = 0
    for i in range(k):
        for point,s in zip(precomp[i], sums[i]):
            if lims[i][0] <= phi - s <= lims[i][1]:
                point[i] = phi-s
                dotv = dot(flows,point)
                mindot = min(mindot, dotv)
                maxdot = max(maxdot, dotv)
                if mindot <= target <= maxdot:
                    return 'yes'
    return 'no'

r = int(input())
for _ in range(r):
    print(process())

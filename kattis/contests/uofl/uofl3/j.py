
from collections import deque

r,n,a,b,x=map(int, input().split())
xs = {*map(int, input().split())}

t = r**3 - (r-1)**3

dr = [r+min(i,2*(r-1)-i) for i in range(1,2*r)]

end = 2*(r+1)
row = [(1,r+1)]
for i in range(1,2*r-1):
    row.append((row[-1][1],end))
    end += dr[i]
# print(*row)

adj = [[] for _ in range(t+1)]


for rn in range(2*r-1):
    rvals = [*range(*row[rn])]

    adj[rvals[0]].append(rvals[1])
    adj[rvals[-1]].append(rvals[-2])
    for i in range(1,len(rvals)-1):
        adj[rvals[i]].append(rvals[i-1])
        adj[rvals[i]].append(rvals[i+1])

    if rn:
        if rn < r:
            for i in range(len(rvals)-1):
                adj[rvals[i]].append(rvals[i] - (r+rn)+1)
                adj[rvals[i+1]].append(rvals[i] - (r+rn)+1)

                adj[rvals[i]-r-rn+1].append(rvals[i])
                adj[rvals[i]-r-rn+1].append(rvals[i+1])
        else:
            tot = 3*r-1
            for i in range(len(rvals)):
                adj[rvals[i]].append(rvals[i]-(tot-rn))
                adj[rvals[i]].append(rvals[i]-(tot-rn)+1)

                adj[rvals[i]-tot+rn].append(rvals[i])
                adj[rvals[i]-tot+rn+1].append(rvals[i])

d = deque([[a,0,xs]])
while d:
    c,l,vis = d.popleft()
    if c in vis:
        continue
    if c == b:
        print(l)
        break

    if l+1 <= n:
        nvis = vis | {c}
        for cc in adj[c]:
            d.append([cc,l+1, nvis])
else:
    print("No")
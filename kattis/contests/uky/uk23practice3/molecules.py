n,m = map(int,input().split())
pos = []
move = set()
for i in range(n):
    a,b = map(int,input().split())
    pos.append((a,b))
    if a == b == -1:
        move.add(i)

adj = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a-=1
    b-=1
    adj[a].append(b)
    adj[b].append(a)

miter = 10**4
for _ in range(miter):
    npos = []
    for i in range(n):
        if i not in move:
            npos.append(pos[i])
        else:
            nx=ny=0
            for nn in adj[i]:
                nx += pos[nn][0]
                ny += pos[nn][1]
            nx /= len(adj[i])
            ny /= len(adj[i])
            if pos[i][0] == pos[i][1] == -1:
                npos.append((nx,ny))
            else:
                nx = (nx+pos[i][0])/2
                ny=(ny+pos[i][1])/2
                npos.append((nx,ny))
    pos = npos
for p in pos:
    print(*p)
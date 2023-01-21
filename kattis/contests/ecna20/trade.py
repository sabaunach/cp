def read(f=int):
    return map(f,input().split())

def dfs1(n):
    if n in vis:
        return
    vis.add(n)
    if n in adj:
        dfs1(adj[n])
    top.append(n)

def dfs2(n):
    if n in vis: return
    vis.add(n)
    comp.append(n)
    if n in adjr:
        dfs2(adjr[n])

n,=read()
adj = {}
adjr = {}
for _ in range(n):
    _,a,b=read(str)
    adj[a]=b
    adjr[b]=a

top  = []
vis=  set()
for v in adj:
    if v not in vis:
        dfs1(v)
top.reverse()
# print(top)

comp = []
vis.clear()
ans = 0
for v in top:
    if v not in vis:
        # print(v)
        dfs2(v)
        # print(comp)
        ans = max(ans,len(comp))
        comp.clear()
print(ans if ans > 1 else 'No trades possible')
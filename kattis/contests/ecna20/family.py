from collections import *

def read(f=int):
    return map(f,input().split())

def nstr(n):
    if n//10 == 1: return f'{n}th'

    if n % 10 == 1: return f'{n}st'
    if n % 10 == 2: return f'{n}nd'
    if n % 10 == 3: return f'{n}rd'
    return f'{n}th'

t,p=read()
adj=defaultdict(set)
par = {}
bads = set()
for _ in range(t):
    s0,_,*s = read(str)
    # print(s0,s)
    adj[s0] |= set(s)
    bads |= set(adj[s0])
    for v in s:
        par[v] = s0

root = (set(adj) - set(par)).pop()
# print(root)
par[root] = root
for _ in range(p):
    x,y = read(str)
    s1,s2=x,y
    vis = {}
    i = 0
    while s1 not in vis:
        vis[s1] = i
        i += 1
        s1 = par[s1]
        # print(i)
    j = 0
    while s2 not in vis:
        j += 1
        s2 = par[s2]

    i = vis[s2]

    s1,s2=x,y
    # print(i,j)
    if i == 0 or j == 0:
        if i == 0:
            i,j=j,i
            s1,s2=s2,s1
        if i == 1:
            print(f'{s1} is the child of {s2}')
        else:
            print(f'{s1} is the{" great"*(i-2)} grandchild of {s2}')
    elif i == j == 1:
        print(f'{s1} and {s2} are siblings')
    else:
        suff = f', {abs(i-j)} time{"s" if abs(i-j)!=1 else ""} removed'
        print(f'{s1} and {s2} are {nstr(min(i,j)-1)} cousins{suff if abs(i-j) else ""}')
n,k = map(int,input().split())
s = input()
l = []
v = 0
vis = set()
for c in s:
    if c in vis:
        while l and l[-1] != c:
            v += 1
            vis.remove(l.pop())
    else:
        l.append(c)
        vis.add(c)
    # print(c,v,l)
print(v+len(l))
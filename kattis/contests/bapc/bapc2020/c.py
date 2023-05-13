n,pr=map(int,input().split())
l = []
v = pr
p = 0
for i in range(n):
    x = int(input())
    if x == 0:
        if i == 0:
            print(*[0]*n,sep='\n')
            exit(0)
        else: continue
    if x < p:
        v -= 1
    l.append(v)
    p = x
# print(l,v)
if v != 1:
    print('ambiguous')
else:
    l += [0]*(n-len(l))
    print(*l,sep='\n')
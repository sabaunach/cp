def read(f=int):
    return map(f,input().split())

n,m = read()
l = [*range(1,n+1)]
for _ in range(m):
    a,b=read(str)
    a=int(a[1:])
    b=int(b[1:])
    i = l.index(a)
    j = l.index(b)
    # print(i,j)
    if i < j: continue
    l.insert(i+1,b)
    l.pop(j)
    # print(l)
print(' '.join(f'T{x}' for x in l))
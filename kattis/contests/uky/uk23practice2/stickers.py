def read(f=int):
    return map(f,input().split())

l,h,k=read()
g = [[0]*l for _ in range(h)]
for x in range(k):
    a,b,c,d = read()
    for i in range(d,min(d+b,h)):
        for j in range(c,min(c+a,l)):
            g[i][j] = x+1
for r in g:
    print(''.join('_' if not x else chr(96+x) for x in r))
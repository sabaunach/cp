def read(f=int):
    return map(f,input().split())

n,a,b = read()
for _ in range(b):
    _,*l = read()
    print(['KEEP','REMOVE'][a not in l])

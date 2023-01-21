def read(f=int):
    return map(f,input().split())

n,=read()
d,=read()
s = input()[2:]
v = 0
p = 1/2
for c in s:
    if c == '1':
        v += p
    p /= 2

a,b=0,1
for _ in range(n):
    m=a+d/8*(b-a)
    if v < m:
        b = m
        print('A',end='')
    else:
        a=m
        print('B',end='')
print()

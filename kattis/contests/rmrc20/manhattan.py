def read(f=int):
    return map(f,input().split())

n, = read()
x = []
y=  []
for _ in range(n):
    a,b =read()
    x.append(a)
    y.append(b)
x.sort()
y.sort()

t = 0
for l in [x,y]:
    s=  [0]*n
    for i in range(1,n):
        s[i] = s[i-1] + (i)*(l[i]-l[i-1])
        # print(l[i]-l[i-1],t)
    t += sum(s)
print(t)
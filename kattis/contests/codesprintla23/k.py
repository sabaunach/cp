n=int(input())
a=[*map(int,input().split())]
t=[*map(int,input().split())]
p=[*map(int,input().split())]
s=sum(a)
if s-a[0] > a[0]:
    print(1)
    print(*p[1:],p[0])
elif s==2*a[0]:
    if n == 2:
        print(0.25)
        print(*p)
    else:
        print(.5)
        print(p[0],*p[1:][::-1])
else:
    print(0.5)
    print(*p)
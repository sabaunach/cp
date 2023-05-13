n=int(input())
l = [tuple(map(int,input().split())) for _ in range(n)]
l.sort()
i = 0
j = n-1
if n % 2:
    print('impossible')
    exit(0)
t=None
while i < j:
    if t == None:
        t = l[i][0] + l[j][0]
    elif t != l[i][0] + l[j][0]:
        print('impossible')
        exit(0)
    i+=1
    j-=1
i = 0
j = n-1
t=None
while i < j:
    if t == None:
        t = l[i][1] + l[j][1]
    elif t != l[i][1] + l[j][1]:
        print('impossible')
        exit(0)
    i+=1
    j-=1
print('possible')
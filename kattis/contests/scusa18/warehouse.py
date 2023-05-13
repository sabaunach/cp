from collections import Counter
for _ in range(int(input())):
    n=int(input())
    c=Counter()
    for _ in range(n):
        a,b=input().split()
        c[a]+=int(b)
    l=sorted(c.items(),key=lambda x:(-x[1],x[0]))
    print(len(l))
    for a,b in l:
        print(a,b)
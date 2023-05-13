from math import *
# from itertools import *
# from functools import lru_cache
# from collections import *
# from bisect import *
# import sys
# sys.setrecursionlimit(10**5+10)


def read(f=int):
    return map(f,input().split())

s,t,n=read()
l=[tuple(read()) for _ in range(n)]
l.sort(key=lambda x:(-x[1],x[0]))
# print(l)
# ptr = [-1]*n
# mx=0
# mi=n
# for i in range(n-1,-1,-1):
#     ptr[i] = mi
#     if l[i][0] > mx:
#         mx=l[i][0]
#         mi=i

# if s > max(l[i][0] for i in range(n)):
#     print(-1)
#     exit(0)

# ans = 0
# sz=s
# i=0
# while i < n:
#     j = ptr[i]

#     while j != n and l[j][0] >= sz:
#         j = ptr[j]

#     # check for j = n
#     if j == n:
#         # print(l[i][1],sz,t)
#         ans += l[i][1]*log2(sz/t)
#         break
        
#     T = max(t,l[j][0])
#     # print(l[i][1],sz,T)
#     ans += l[i][1] * log2(sz/T)
#     i=j
#     sz=T

#     if sz == t:
#         break
# print(ans)

# # print(10*log2(10/4)+5*log2(4/1))
# # print(log2(10000/9999))

i=n-1
good=[n-1]
while i >= 0:
    if l[good[-1]][0]>= s:
        break
    j=i-1
    while j >= 0 and l[j][0] <= l[i][0]:
        j -= 1
    # if j == -1:
    #     break
    good.append(j)
    
    i=j

if i == -1:
    print(-1)
    exit(0)

good.reverse()
ans=0
i=0
sz=s
while i < len(good):
    if i == len(good)-1:
        ans += l[good[i]][1]*log2(sz/t)
    else:
        T=max(t,l[good[i+1]][0])
        ans+=l[good[i]][1]*log2(sz/T)
        sz=T
        if sz==t:break
    i+=1
print(ans)
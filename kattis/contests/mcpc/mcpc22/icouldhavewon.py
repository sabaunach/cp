from math import *
from itertools import *
from functools import lru_cache
from collections import *
from bisect import *
import sys
# sys.setrecursionlimit(10**5+10)


def read(f=int):
    return map(f,input().split())

s=input()
n=len(s)
ans=[]
for k in range(1,n+1):
    t=0
    d1=d2 = 0
    for c in s:
        if c=='A':d1+=1
        else:d2+=1
        if d1==k:
            t+=1
            d1=d2=0
        elif d2==k:
            t-=1
            d1=d2=0
        # print(k,d1,d2,t)
    if t>0:ans.append(k)
    
print(len(ans))
if ans:print(*ans)
from math import *
from itertools import *
from functools import lru_cache
from collections import *
from bisect import *
import sys
# sys.setrecursionlimit(10**5+10)


def read(f=int):
    return map(f,input().split())
n,k=read()
v = 0
c=0
for i in range(1,n+1):
    p = pow(10,len(str(i)))
    v = (p*v+i) % k
    c+= v == 0
print(c)
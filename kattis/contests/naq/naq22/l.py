from functools import *
from itertools import *
from collections import *
from heapq import *
from math import gcd, factorial as fact, comb, hypot
from bisect import *
import sys

input = sys.stdin.readline

def read(f=int):
    return map(f,input().split())

def calc(s,t):
    ans = 4*s+1
    a2 = 4*min(s,t)+1
    for d in range(s+1):
        v = int(2*(s-d)/3)
        ans += 8*v if d else 4*v
        v2 = max(0,min(v,int((t-d)/2)))
        a2 += 8*v2 if d else 4*v2
    return ans,a2

t,s = read()
vt = (t+1)**2 + t**2

vs,vt = calc(s,t)

g = gcd(vt,vs)
vt //= g
vs //= g
print(f'{vt}/{vs}' if vs != 1 else vt)
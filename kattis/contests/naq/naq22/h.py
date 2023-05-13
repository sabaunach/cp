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

n,mn,mx = read()
l = [int(input()) for _ in range(n)]
l.sort()

a = [(0,0)] * n
for i in range(n):
    if not i:
        a[i] = (l[i] - mx/2, l[i] + mx/2)
    else:
        if l[i] - l[i-1] < mn:
            print(-1)
            exit(0)

        vl = l[i-1]+mn/2
        vr = l[i] - mx/2

        if a[i-1][1] > vr:
            a[i] = (vl,2*l[i]-vl)
            a[i-1] = (2*l[i-1]-vl,vl)
        else:
            a[i] = (vr,2*l[i]-vr)
# print(*a,sep='\n')
# print()
for i in range(n-2,-1,-1):
    d = min(a[i+1][0] - a[i][1],mx/2-(a[i][1]-l[i]), (a[i][1] - a[i-1][0] if i else 10**18))
    a[i] = (a[i][0]-d,a[i][1]+d)
print(round(sum(x[1]-x[0] for x in a)))
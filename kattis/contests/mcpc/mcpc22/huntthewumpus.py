from math import *
from itertools import *
from functools import lru_cache
from collections import *
from bisect import *
import sys
# sys.setrecursionlimit(10**5+10)


def read(f=int):
    return map(f,input().split())

s,=read()

wpos = []
for _ in range(4):
    while True:
        s = s+s//13+15
        # print(s)
        p=divmod(s%100,10)
        if p not in wpos:
            break
    wpos.append(p)

# print(wpos)
t=0
for line in sys.stdin.readlines():
    n=int(line.strip())
    x,y=divmod(n,10)
    m=10**18
    l=[]
    for wx,wy in wpos:
        l.append(abs(wx-x)+abs(wy-y))
    if 0 in l:
        print('You hit a wumpus!')
        i=l.index(0)
        l.pop(i)
        wpos.pop(i)
    t+=1
    if not wpos:
        break
    print(min(l))
print(f'Your score is {t} moves.')
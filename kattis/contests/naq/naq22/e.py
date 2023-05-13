from functools import *
from itertools import *
from collections import *
from heapq import *
from math import gcd, factorial as fact, comb, hypot
from bisect import *
import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**5)

def read(f=int):
    return map(f,input().split())

def fill(x,y):
    if comp[x][y] >= 0: return 0
    comp[x][y] = C
    v = (g[x][y] == 1)
    for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]]:
        nx,ny=x+dx,y+dy
        if nx in range(n) and ny in range(m):
            if abs(g[nx][ny]) == 1:
                v += fill(nx,ny)
    return v

n,m = read()
g = [[0]*m for _ in range(n)]
walls = set()
starts = []
dots = []
DC = 0
for i in range(n):
    s = input().strip()
    for j,c in enumerate(s):
        if c == 'X':
            g[i][j] = 2
        elif c.isalpha():
            starts.append((i,j))
        elif c == '.':
            g[i][j] = 1
            DC += 1
        else:
            g[i][j] = -1

comp = [[-1]*m for _ in range(n)]
dc = []
C = 0
for i,(si,sj) in enumerate(starts):
    if comp[si][sj] == -1:
        cnt = fill(si,sj)
        dc.append(int(cnt))
        C += 1
print(sum(v != 0 for v in dc), DC - sum(dc))

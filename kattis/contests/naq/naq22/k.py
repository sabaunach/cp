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


m = 10**18
a,b,c=read()
ops = '+-*/'
for op in product(ops,repeat=2):
    v = a
    if op[0] == '+':
        v += b
    if op[0] == '-':
        v -= b
    if op[0] == '*':
        v *= b
    if op[0] == '/':
        if v % b:
            continue
        v //= b

    if op[1] == '+':
        v += c
    if op[1] == '-':
        v -= c
    if op[1] == '*':
        v *= c
    if op[1] == '/':
        if v % c:
            continue
        v //= c

    if v >= 0:
        m = min(m,v)
print(m)
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

n, = read()
l = sorted([int(input()) for _ in range(n)],reverse=True)
s = [0] * (n+1)
for i in range(n):
    s[i+1] = s[i] + l[i]

i = 1
while i <= n:
    j = i+1
    while j <= n and s[j] - s[i] < s[i]:
        j += 1
    if j > n:
        break
    i = j
print(i)
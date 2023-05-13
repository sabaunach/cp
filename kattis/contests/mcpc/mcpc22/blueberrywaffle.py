from math import *
from itertools import *
from functools import lru_cache
from collections import *
from bisect import *
import sys
# sys.setrecursionlimit(10**5+10)


def read(f=int):
    return map(f,input().split())

r,f=read()
print('down' if (f+r/2)//r % 2 else 'up')
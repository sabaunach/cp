from collections import Counter

def read():
    return map(int,input().split())

n,k=read()
l=[*read()]
c=Counter(l)

a=
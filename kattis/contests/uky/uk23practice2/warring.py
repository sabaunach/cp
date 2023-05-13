from itertools import *

n=int(input())
s = 0
ms = 0
p = ""
pa,pb= 0,0
ca,cb=0,0
# for _ in range(n):
#     i = input()
#     if i[0] == 'Y': s += 1
#     else: s -= 1
#     ms = max(ms,abs(s))
#
l = [input().strip() for _ in range(n)]
m1 = 0
s = 0
ms = 0
tie = False
for k,g in groupby(l):
    g=[*g]
    print(k,':',*g)
    if len(g) > abs(m1):
        m1 = -len(g) if k[0] == 'Y' else len(g)
        tie=False
    elif len(g) == abs(m1):
        if (-1)**(k[0]=='Y') * m1 < 0:
            tie = True
    s += (-1)**(k[0] == 'Y') * len(g)
    sg=  ms<0
    if abs(s) > abs(ms):

    ms = max(abs(ms),abs(s)) * (-1)**(s<0)
    print(m1,s,ms,tie)
print('Agree' if tie or m1*ms > 0 else 'Disagree')
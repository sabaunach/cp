from collections import defaultdict
from functools import reduce

def factor(n):
    m = defaultdict(int)
    for p in primes:
        while not n % p:
            m[p] += 1
            n //= p
        if n == 1:
            break
    if n != 1:
        m[n] += 1
        primes.append(n)
    return m

def crt(c1, c2):
    a1,m1 = c1
    a2,m2 = c2
    return [(a1*m2*pow(m2,-1,m1)+a2*m1*pow(m1,-1,m2)) % (m1*m2),m1*m2]

a,b,c,d,e,f,g = map(int,input().split())
if a > b: a,b=b,a
szs = sorted(s*(a-2*s)*(b-2*s) for s in range(a//2))
szs = szs[:-4:-1]

isp = [True] * (32000)
primes = []
for i in range(2,len(isp)):
    if isp[i]:
        primes.append(i)
        for j in range(i*i,len(isp),i):
            isp[j] = False
# print(len(primes))

f1 = factor(szs[0])
f2 = factor(szs[1])
f3 = factor(szs[2])
l = [(f1,c),(f2,d),(f3,e)]
# print(l,sep='\n')
congs = []
allps = [p for p in primes if p in f1 or p in f2 or p in f3]
for p in allps:
    me = 0
    mm = 0
    for fs,a in l:
        if p in fs and fs[p] > me:
            me = fs[p]
            mm = a % (p ** me)
    congs.append((mm,p**me))

cong = reduce(crt, congs)
l = f % cong[1]
if l > cong[0]:
    l -= cong[1]
print(f + cong[0] - l)
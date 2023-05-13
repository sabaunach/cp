from functools import lru_cache

mod=2305843009213693951

def h(s):
    v = 0
    for c in s:
        v = (27*v+ord(c)-97+1) % mod
    return v

@lru_cache(maxsize=None)
def p27(x):
    return pow(27,x,mod)

n=int(input())
l = [input().strip() for _ in range(n)]


hashes = set()
for s in l:
    hashes.add(h(s))

printed=False
for s in l:
    sf = [0] * (len(s)+1)
    poww = 1
    for i in range(len(s)-1,-1,-1):
        sf[i] = (sf[i+1] + poww*(ord(s[i])-ord('a')+1)) % mod
        poww *= 27
        poww %= mod

    pf = [0]*(len(s)+1)
    for i in range(1,len(s)+1):
        pf[i] = (pf[i-1]*27+ord(s[i-1])-97+1) % mod


    n=len(s)
    for i in range(len(s)):
        v1 = pf[i]
        v2 = sf[i+1]
        v = (v1 * p27(n-i-1) + v2) % mod
        if v in hashes:
            printed=True
            print(s)
            break

if not printed:
    print('NO TYPOS')
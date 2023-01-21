def inv(n, d={}):
    if n not in d:
        d[n] = pow(n, mod-2, mod)
    return d[n]


def choose(n, k):
    assert k in range(n+1), f'{n} {k}'
    return (fac[n] * inv(fac[k]) * inv(fac[n-k])) % mod


mod = 10 ** 9 + 7

N = 10 ** 6
fac = [1] * (N + 1)
for i in range(1, N + 1):
    fac[i] = (fac[i - 1] * i) % mod

n, x, y = map(int, input().split())
ans = 0
for k in range(1, 1+n//max(x, y)):
    cx = choose(n-1-k*(x-1), k-1)
    cy = choose(n-1-k*(y-1), k-1)
    ans = (ans + cx * cy) % mod
print(ans)
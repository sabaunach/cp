import sys

n, a, x, y, m, k = map(int, input().split())


fact = [1]*(n+1)
for i in range(2, n+1):
    fact[i] = fact[i-1]*i

mod = 998244353
coeff = (k == 1)
b = coeff*a
h = coeff
ans = 0
for i in range(1, n):
    ans ^= (b % mod)*i
    coeff = 0 if i+1 < k else fact[i+1]//(fact[k]*fact[i+1-k])
    b = coeff*a + b*x + h*y
    h = h + coeff

ans ^= (b % mod)*n
print(ans)
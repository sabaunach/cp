def inv(n, d={}):
    if n not in d:
        d[n] = pow(n, mod-2, mod)
    return d[n]


# def choose(n, k, d={}):
#     if k not in range(n+1):
#         return 0
#     if not k % n:
#         return 1
#     if k > n-k:
#         return choose(n, n-k)
#
#     print(f'{n=} {k=}')
#     if (n, k) not in d:
#         nn = n
#         c = 1
#         for i in range(1, 1+k):
#             c = (c * nn * inv(i)) % mod
#             d[n, i] = c
#             nn -= 1
#
#         # c = ((n-k+1)*choose(n, k-1) * inv(k)) % mod
#
#         # if (n+1,k) in d and (n,k-1) in d:
#         #     c = d[n+1,k] - d[n,k-1]
#         # else:
#         #     c = 0
#         #     i = k
#         #     s = 1
#         #     while i >= 0:
#         #         c += s * d[n+1,i]
#         #         s *= -1
#         #         i -= 1
#         d[n, k] = c
#     return d[n, k]

# choose(n,k) == choose(n-1,k) + choose(n-1,k-1)


def choose(n, k):
    return (fac[n] * inv(fac[k]) * inv(fac[n-k])) % mod


# def fac(n, d={0: 1}):
#     print(n)
#     if n not in d:
#         d[n] = n*fac(n-1) % mod
#     return d[n]


n, x, y = map(int, input().split())
mod = 10**9 + 7

fac = [1] * (n+1)
for i in range(1, n+1):
    fac[i] = fac[i-1] * i % mod

ans = 0
for k in range(1,1+n//max(x,y)):
    cx = choose(n-1-k*(x-1), k-1)
    cy = choose(n-1-k*(y-1), k-1)
    ans = (ans + cx * cy) % mod
print(ans)
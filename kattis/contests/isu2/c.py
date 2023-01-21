def gcd(a, b):
    return gcd(b, a % b) if b else a


def add(a, b, c, d):
    e = a*d+b*c
    f = b*d
    g = gcd(e, f)
    return e//g, f//g


s, n = input().split()
n = int(n)
i = s.index('.')
t = len(s) - i - 1

a = s[:-n]
b = s[-n:]

if t == n:
    a += '0'

den = 10 ** (len(a) - a.index('.') - 1)
x = int(a[:a.index('.')]) * den + int(a[a.index('.')+1:])

y = int(b)
z = int('9'*n) * 10**(t-n)

ans = add(x, den, y, z)
print(f'{ans[0]}/{ans[1]}')

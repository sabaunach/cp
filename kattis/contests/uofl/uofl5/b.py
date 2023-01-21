def mysum(l, u):
    return u*(u + 1)//2 - l*(l - 1)//2


def digsum(n):
    return sum(int(c) for c in str(n))


def solve(a, b):
    if a > b:
        return 0
    if a//10 == b//10:
        return digsum(a//10) * (b - a + 1) + mysum(a % 10, b % 10)

    tot = 0
    while a % 10:
        tot += a % 10 + digsum(a//10)
        a += 1
    while b % 10:
        tot += b % 10 + digsum(b//10)
        b -= 1
    tot += digsum(b // 10)

    return tot + 45*(b//10-a//10) + solve(a // 10, b // 10 - 1)*10


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(solve(a, b))
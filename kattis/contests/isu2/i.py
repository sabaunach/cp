from itertools import product

def isPal(s, k):
    #convert s to base k
    l = []
    n = int(''.join(s), 2)
    while n:
        l.append(n % k)
        n //= k

    l = ''.join(map(str,l))

    for i in range(len(l)//2):
        if l[i] != l[~i]:
            return False
    return True


a, b, k = map(int, input().split())

pals = []
for l in range(1, 22):
    for p in product('01', repeat=(l-1)//2):
        n = ['1', *p]
        add = reversed(n[:len(n) - (l % 2)])
        n = [*n, *add]
        pals.append(n)

for base in reversed(range(3, k+1)):
    pals = [*filter(lambda s: isPal(s, base), pals)]
    if not pals:
        break

print(sum(a <= int(''.join(v), 2) <= b for v in pals))

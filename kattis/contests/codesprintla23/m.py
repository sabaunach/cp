from random import randint

N = 100000
L = 7
Q = 100000
print(N)
for i in range(1,N+1):
    j = randint(1, N)
    while (j == i): j = randint(1, N)
    print(j, randint(1, N))
print(L)
for _ in range(L):
    i = randint(1, N)
    j = randint(1, N)
    while (j == i): j = randint(1, N)
    print(i, j, randint(1, N))
print(Q)
for _ in range(Q):
    a = randint(1, N)
    b = randint(1, N)
    while (a == b): b = randint(1, N)
    print(a, b)
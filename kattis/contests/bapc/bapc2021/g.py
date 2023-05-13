from itertools import product

n = int(input())
# primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]
primes = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
seen = {}
for s in product('+*',repeat=15):
    a = f'{2}'
    for i in range(1,16):
        a = f'({a}{s[i-1]}{primes[i]})'
    seen[eval(a) % (10**9+7)] = s



print(len(seen.keys()))
cnt = 0
sorted_keys = sorted(seen.keys())
for i in range(2, len(seen.keys())):
    if sorted_keys[i]-sorted_keys[i-1] <= 20000:
        print(sorted_keys[i], sorted_keys[i-1])

exit(0)


l = [0]*(n+1)
i = n
while i-15 >= 0:
    i -= 15
    for j in range(16):
        l[i+j] = primes[j]
    print('?',*l,flush=True)
    ret = int(input())
    s = seen[ret]
    for j in range(1,16):
        l[i+j] = 0 if s[i-1] == '+' else 1

    # i = max(0, i-15)

# for j in range(min(16,n)):
#     # print(i,j,len(l),len(primes))
#     l[i+j] = primes[j]
# print('?',*l,flush=True)
# ret = int(input())
# s = seen[ret]
# for j in range(1,min(16,n)):
#     l[i+j] = 0 if s[i-1] == '+' else 1
# print('!',''.join('+*'[i] for i in l[1:]),flush=True)
l[i] = 1
i -= 1
while i >= 0:
    l[i] = 1
    print('?',*l,flush=True)
    ret = int(input())
    if ret == 1:
        l[i+1] = 1
    else:
        assert ret == 2
        l[i+1] = 0
    i -= 1
print('!',''.join('+x'[i] for i in l[1:]),flush=True)
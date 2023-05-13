from collections import defaultdict

n,d = map(int,input().split())
l = [*map(int,input().split())]

D = defaultdict(int)
for v in l:
    D[v//d] += 1
# print(D)

print(sum(v*(v-1)//2 for v in D.values()))

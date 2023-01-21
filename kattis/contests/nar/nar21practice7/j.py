from collections import defaultdict

n=int(input())
arr = [int(input())-1 for _ in range(n)]

indeg = [0] * n
for v in arr:
    indeg[v] += 1


def dfs(x):
    c = arr[x]
    if merge(x, c):
        dfs(c)


def get(x):
    if par[x] < 0:
        return x
    par[x] = get(par[x])
    return par[x]


def merge(x, y):
    x = get(x)
    y = get(y)
    if x == y:
        return False
    if par[x] < par[y]:
        x, y = y, x

    par[y] += par[x]
    par[x] = y
    return True


par = [-1] * n
for i in range(n):
    dfs(i)

d = defaultdict(int)
for i in range(n):
    d[get(i)] += indeg[i] - 1 if indeg[i] > 1 else 0
print(sum(d.values()) + sum(v == 0 for v in d.values()))

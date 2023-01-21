n, m, k = map(int, input().split())

t = [0] * m
p = [0] * m

for i in range(m):
    t_in, p_in = input().split()
    t[i] = int(t_in)
    p[i] = 1 - float(p_in)

prevEV = 0
for i in range(n):
    minEV = ((t[0] + prevEV) + k * (1 - p[0])) / p[0]
    for j in range(m):
        minEV = min(minEV, ((t[j] + prevEV) + k * (1 - p[j])) / p[j])
    prevEV = minEV
print(prevEV)

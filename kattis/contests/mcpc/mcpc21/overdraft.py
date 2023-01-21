s = 0
m = 0
n = int(input())
for i in range(n):
    s += int(input())
    m = min(m, s)
print(-m)

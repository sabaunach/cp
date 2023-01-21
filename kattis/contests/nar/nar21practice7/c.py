s = input()
n = int(input())

l = []
for i in range(n):
    l.append([*map(int, input().split())])

s1='RUBEN'
s2 = 'ALBERT'
if n % 2:
    print(s)
else:
    print(s2 if s2 != s else s1)

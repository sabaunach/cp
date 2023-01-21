def read(f=int):
    return map(f,input().split())

n, = read()
l1 = []
l2 = []
for i in range(n):
    s = input()
    l = l1 if s[0] == 'N' else l2
    x = []
    for j in range(1,4):
        x.append(s[j] == 'Y')
    l.append(x)

for i in range(3):
    v1 = sum(x[i] for x in l1) / len(l1)*100
    v2 = sum(x[i] for x in l2) / len(l2)*100
    # print(v1,v2)
    if v1 <= v2:
        print('Not Effective')
    else:
        print(100*(v1-v2)/v1)
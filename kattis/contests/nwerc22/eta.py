a,b = map(int,input().split('/'))

d = 1
while True:

    t = a*d
    if t > d*b*(d*b-1)//2:
        d += 1
        continue

    l = 0
    r = d*b
    while l +1 < r:
        m = (l+r)//2
        v = (d*b-1 + d*b-1 - (m-1)) * m // 2
        if v < t:
            l = m
        else:
            r = m

    # print(l,r)

    v = [0] * d*b
    for i in range(l+1):
        v[i] = i
    # print(v)
    for i in range(l+1,d*b):
        v[i] = l
    # print(v)
    x = t - ((d*b-1 + d*b-1 - (l-1)) * l // 2 if l else 0)
    # print(x)
    for i in range(x):
        v[-i-1] = r

    if v[1] == 0:
        print('impossible')
        break
    # print(v)
    # print(d,t,l,r)

    print(d*b,d*b-1)
    i = 0
    while i < d*b:
        j = i+1
        while j < d*b and v[j] == v[i]:
            j += 1
        fi = j
        # print('\t',i,j)
        while j < d*b and v[j] == v[i] + 1:
            print(i+1,j+1)
            j += 1
        i = fi

    break
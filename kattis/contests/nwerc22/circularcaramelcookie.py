def count(r):
    v = 0
    y = int(r)
    x = 1
    while y >= 0:
        while y >= 0 and x*x+y*y > r*r:
            y -= 1
        v += y
        x += 1
        if x >= r:
            break
    return 4*v

s = int(input())

l = 0
r = 10**6
p = 0
while True:
    # print(l,r,p)
    m = (l+r)/2
    # print(count(m))
    c = count(m)
    if abs(m-p) < 10**-7 and c > s:
        break
    p = m
    if c <= s:
        l = m
    else:
        r = m
print(r)
# print(count(17841.881206868296))
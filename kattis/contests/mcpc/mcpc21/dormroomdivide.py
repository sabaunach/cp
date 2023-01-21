def area(l):
    a =0
    ll = len(l)
    for i in range(ll):
        a += (l[i][0]*l[(i+1)%ll][1] - l[(i+1)%ll][0]*l[i][1])
    return abs(a/2)


n = int(input())
pts = []
for i in range(n):
    pts.append([*map(int, input().split())])

tot = area(pts)

i = 2
ar = area(pts[:3])
while 2*ar < tot:
    i += 1
    ar += area([pts[0], pts[i-1], pts[i]])
if 2*ar == tot:
    print(*pts[i])
else:
    tar =tot - 2*area(pts[:i])
    dx = pts[i][0]-pts[i-1][0]
    dy=pts[i][1]-pts[i-1][1]
    num = tar - pts[i-1][0]*pts[0][1]+pts[0][0]*pts[i-1][1]-(pts[0][0]-pts[i-1][0])*pts[i-1][1]-(pts[i-1][1]-pts[0][1])*pts[i-1][0]
    den = abs((pts[0][0]-pts[i-1][0])*dy + (pts[i-1][1]-pts[0][1])*dx)
    t = num/den
    # print(num,den)
    print(pts[i-1][0]+dx*t, pts[i-1][1]+dy*t)

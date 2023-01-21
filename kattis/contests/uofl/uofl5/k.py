def sqrLen(a):
    return a[0]**2+a[1]**2


def sgn(val):
    return 1 if val > 0 else 0 if val == 0 else -1


def cross(a, b, c=None):
    if c is None:
        return a[0] * b[1] - a[1] * b[0]
    else:
        return cross((b[0]-a[0], b[1]-a[1]), (c[0]-a[0], c[1]-a[1]))


def pointInTriangle(a, b, c, point):
    s1 = abs(cross(a, b, c))
    s2 = abs(cross(point, a, b)) + abs(cross(point, b, c)) + abs(cross(point, c, a))
    return s1 == s2


def pointInConvexPolygon(point):
    point = (point[0] - cvHull[0][0], point[1] - cvHull[0][1])
    if cross(seq[0], point) and sgn(cross(seq[0], point)) != sgn(cross(seq[0], seq[N - 1])):
        return False
    if cross(seq[N - 1], point) and sgn(cross(seq[N - 1], point)) != sgn(cross(seq[N - 1], seq[0])):
        return False

    if cross(seq[0], point) == 0:
        return sqrLen(seq[0]) >= sqrLen(point)

    l = 0
    r = N - 1
    while r - l > 1:
        mid = (l + r) // 2
        if cross(seq[mid], point) >= 0:
            l = mid
        else:
            r = mid
    return pointInTriangle(seq[l], seq[l + 1], (0, 0), point)


L = int(input())
llocs = []
for _ in range(L):
    llocs.append(tuple(map(int, input().split())))
llocs.sort()

S = int(input())
slocs = []
for _ in range(S):
    slocs.append(tuple(map(int, input().split())))

N = 0
for i in range(L):
    if i < 2:
        N += 1
        continue

    prev = llocs[N - 2]
    curr = llocs[N - 1]
    while N >= 2 and (curr[0] - prev[0]) * (llocs[i][1] - prev[1]) - (curr[1] - prev[1]) * (llocs[i][0] - prev[0]) <= 0:
        N -= 1
        prev = llocs[N - 2]
        curr = llocs[N - 1]
    llocs[N] = llocs[i]
    N += 1

cvHull = llocs[:N+1]
seq = []
for i in range(N):
    seq.append((cvHull[i+1][0] - cvHull[0][0], cvHull[i+1][1] - cvHull[0][1]))

t = 0
for p in slocs:
    if pointInConvexPolygon(p):
        # print(p)
        t += 1
print(t)

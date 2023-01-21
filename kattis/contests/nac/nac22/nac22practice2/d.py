from itertools import permutations

def read(fn=int):
    return map(fn, input().split())

def isLp(y):
    if not y % 400: return True
    if not y % 100: return False
    if not y % 4: return True
    return False


days = [31,28,31,30,31,30,31,31,30,31,30,31]
t, = read()
for _ in range(t):
    s = read(str)
    nums = sorted(''.join(s))
    c = set()
    best = (1000000,100,100)
    for p in permutations(nums):
        d = ''.join(p[:2])
        m = ''.join(p[2:4])
        y = ''.join(p[4:])

        mm,dd,yy=map(int,[m,d,y])
        if mm in range(1,13) and yy >= 2000:
            if mm == 2 and dd == 29:
                if isLp(yy):
                    if (yy,mm,dd) >= (2000,1,1):
                        c.add((yy,mm,dd))
                        best = min(best, (yy,mm,dd))
            elif dd in range(1,days[mm-1]+1):
                if (yy,mm,dd) >= (2000,1,1):
                    c.add((yy,mm,dd))
                    best = min(best, (yy,mm,dd))
    v = len(c)
    if v == 0:
        print(0)
    else:
        y,m,d = best
        y = str(y)
        m = '0'*(m < 10) + str(m)
        d = '0'*(d<10) + str(d)
        print(v,d,m,y)

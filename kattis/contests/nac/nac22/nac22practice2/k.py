def read(fn=int):
    return map(fn, input().split())

q, = read()
ans = []
par = {}
vals = [{} for y in range(5002)]
for x in range(5002):
    vals[0][x] = 0
    vals[5001][x] = 0
qs = {0:(0,0,5001,5001)}
for i in range(1,q+1):
    v, *r = read()
    if v == 1:
        x1,y1,x2,y2 = r
        if x1>x2:x1,x2=x2,x1
        if y1>y2:y1,y2=y2,y1
        qs[i] = (x1,y1,x2,y2)
        for x in range(x1,x2+1):
            vals[y1][x] = i
            vals[y2][x] = i
    elif v == 2:
        j, = r
        x1,y1,x2,y2 = qs[j]
        for x in range(x1,x2+1):
            del vals[y1][x]
            del vals[y2][x]
    else:
        x1,y1,x2,y2 = r

        cy1 = y1
        while True:
            cy1 += 1
            while x1 not in vals[cy1]:
                cy1 += 1
            q1 = vals[cy1][x1]
            _,qy1,_,qy2 = qs[q1]
            if cy1 == qy2:
                break
            cy1 = qy2

        cy2 = y2
        while True:
            cy2 += 1
            while x2 not in vals[cy2]:
                cy2 += 1
            q2 = vals[cy2][x2]
            _,qy1,_,qy2 = qs[q2]
            if cy2 == qy2:
                break
            cy2 = qy2

        ans.append('YN'[q1!=q2])
print(''.join(ans))
def read(fn=int):
    return map(fn, input().split())


def solve1(ts):
    s, p, q = 0, 0, 0
    l = r = ts//2
    for i, v in enumerate(vals):
        for j in range(2):
            if j == 0:
                p += v[j]
            else:
                q += v[j]

            s += 1
            if j == 0: l -= 1
            else: r -= 1

            if p-q > r or q-p > l:
                return s
    return ts


def solve2(ts):
    lp = (ts+1)//2
    lq = ts//2

    lp -= 1
    lq -= 1

    dp = lp-1
    while dp >= 0 and vals[dp][0] == vals[lp][0]:
        dp -= 1

    dq = lq-1
    while dq >= 0 and vals[dq][1] == vals[lq][1]:
        dq -= 1

    # print(dp,dq)

    dp += 1
    dq += 1
    if dp <= dq:
        return 2*dq
    else:
        return 2*dp-1


t, = read()
for _ in ' '*t:
    k, = read()
    vals = []
    for _ in range(k):
        a,b = read(str)
        vals.append([int(a == 'E'), int(b == 'E')])

    s = solve1(2*k)
    c = solve2(s)
    print(s, c)
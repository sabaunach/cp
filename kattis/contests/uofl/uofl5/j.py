l, p = map(int, input().split())
scores = [float(input()) for _ in range(l)] + [0]*p
drop = {i: scores[i] for i in range(l)}
for i in range(p):
    lp, rp, x, y = map(float, input().split())
    x, y = map(int, (x-1, y-1))

    if x in drop: del drop[x]
    if y in drop: del drop[y]

    t = lp + rp
    scores[l+i] = (scores[x]*lp + scores[y]*rp) / t
    drop[l+i] = scores[l+i]

print(max(drop.values()))

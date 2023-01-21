class Con:
    def __init__(self, inp, out):
        self.inp = inp
        self.out = out

    def sat(self, inp):
        if all(p in inp for p in self.inp):
            return self.out
        return ""

    def __repr__(self):
        return ' and '.join(self.inp) + f' then {self.out}'


class Dis:
    def __init__(self, inp, out):
        self.inp = inp
        self.out = out

    def sat(self, inp):
        if any(p in inp for p in self.inp):
            return self.out
        return ""

    def __repr__(self):
        return ' or '.join(self.inp) + f' then {out}'


n = int(input())
s = [input() for _ in range(n)]

topp = set()
conds = []
for t in s:
    if ' ' not in t:
        topp.add(t)
    else:
        t = t.split()
        out = t[-1]
        inp = set(t[1:-1:2])

        if 'and' in t:
            conds.append(Con(inp, out))
        else:
            conds.append(Dis(inp, out))

change = True
while change:
    change = False
    conds2 = []
    for cond in conds:
        out = cond.sat(topp)
        if out:
            topp.add(out)
            change = True
        else:
            conds2.append(cond)
    conds = conds2

print(len(topp))

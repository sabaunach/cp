strs = {}
for i in range(2, 5):
    for j in range(1, pow(i, i+1)):
        for d in range(3, i+5):
            s = "("
            for e in range(i):
                # s += "+%ln^%l".format(j % i, e)
                s += f'+{j%i+3}n^{e}'
                j //= i
            s += f")/{d}"
            if s not in strs:
                print(s)
            strs[s] = 0
print('.')

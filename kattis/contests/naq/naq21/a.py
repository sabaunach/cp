

n = input()

unused = set('0123456789') - set(n)
if not unused: print('Impossible')
else:
    big = max(unused)
    small = min(unused)
    big2 = max(u for u in unused if u < n[0])
    try:
        small2 = min(u for u in unused if u > n[0])
    except:
        small2 = chr(ord('9')+1)
    smallnonzero = min(u for u in unused if u)

    if big2 == '0':
        l = big*(len(n)-1) or '0'
    else:
        l = big2 + big*(len(n)-1)

    if small2 <= '9':
        r = small2 + small*(len(n)-1)
    else:
        r = smallnonzero+small*(len(n))

    dl = abs(int(l) - int(n))
    dr = abs(int(r) - int(n))

    if dl == dr:
        print(int(l),int(r))
    elif dl < dr:
        print(int(l))
    else:
        print(int(r))

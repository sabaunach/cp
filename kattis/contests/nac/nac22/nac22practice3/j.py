while True:
    n,m = map(int, input().split())
    if n == -1: break
    if 2*m % n: print('NO')
    else:
        print('YES')
        k = 2*m//n
        offs = []
        for i in range(k//2):
            offs.append(i+1)
            offs.append(-i-1)
        if k % 2:
            offs.append(n//2)

        for i in range(n):
            for o in offs:
                j = (i + o) % n
                if i < j:
                    print(i+1, j+1)
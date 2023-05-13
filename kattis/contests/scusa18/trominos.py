def val(x,y):
    n = max(len(bin(x)),len(bin(y)))-2
    C = 1<<n
    if (x,y) in((C//2,C//2-1),(C//2-1,C//2),(C//2-1,C//2-1)):
        return 0

    b1=x>=C//2
    b2=y>=C//2
    if b1^b2:
        if b1:
            return val(y,C-1-x)-1
        else:
            return val(C-1-y,x)+1
    return val(x%(C//2),y%(C//2))

for _ in range(int(input())):
    x,y = map(int,input().split())
    print(val(x,y)%4)
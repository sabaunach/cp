t =  int(input())
for i in range(t):
    s = input()
    for j in range(7):
        if len(set(s[:j])) == j:
            for k in range(j,len(s),7):
                if len(set(s[k:k+7])) < len(s[k:k+7]):
                    break
            else:
                print(1)
                break
    else:
        print(0)

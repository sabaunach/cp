
# Online Python - IDE, Editor, Compiler, Interpreter
t = int(input())
m = 1000000007
six = 166666668
for i in range(t):
    n = int(input())
    print(n)
    print(((((3*n-2)*(n*(n+1)//2)) % m) -((n*(n+1)*(2*n+1))//6)) % m)

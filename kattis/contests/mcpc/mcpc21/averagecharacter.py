s = input()
c =0 
for ch in s:
    c += ord(ch)
c //= len(s)
print(chr(c))

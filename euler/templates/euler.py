import os
import sys

n = str(sys.argv[1])

if len(n) == 1:
    directory = os.path.join("0-99", "0-9", n)
elif len(n) == 2:
    directory = os.path.join("0-99", n[0]+"0-"+n[0]+"9", n)
else:
    directory = os.path.join(n[0]+"00-"+n[0]+"99", n[0]+n[1]+"0-"+n[0]+n[1]+"9", n)

print(directory)

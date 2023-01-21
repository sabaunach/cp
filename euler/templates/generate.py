import os

script_dir = os.path.dirname(os.path.realpath(__file__))
os.chdir(os.path.join(script_dir, '..'))

base_dir = "0-99"
for c in range(0, 10):
    try:
        os.makedirs(os.path.join(base_dir, "0-9", str(c)))
    except FileExistsError:
        pass

for b in range(1, 10):
    b_dir = str(b)+"0-"+str(b)+"9"
    for c in range(0, 10):
        try:
            os.makedirs(os.path.join(base_dir, b_dir, str(b)+str(c)))
        except FileExistsError:
            pass

for a in range(1, 9):
    a_dir = str(a)+"00-"+str(a)+"99"
    for b in range(0, 10):
        b_dir = str(a)+str(b)+"0-"+str(a)+str(b)+"9"
        for c in range(0, 10):
            try:
                os.makedirs(os.path.join(a_dir, b_dir, str(a)+str(b)+str(c)))
            except FileExistsError:
                pass

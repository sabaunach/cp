import random

with open('b.in', 'w') as f:
    f.write('1\n')
    f.write('6\n')
    for i in range(6):
        f.write(f"{'EN'[random.random() < 0.5]} {'EN'[random.random() < 0.5]}\n")
from math import log

def v(f):
    return round(12*log(f/440,2))%12

kname = ['G major', 'C major','Eb major','F# minor','G minor']
key = [
    {10,0,2,3,5,7,9},
    {3,5,7,8,10,0,2},
    {6,8,10,11,1,3,5},
    {9,11,0,2,4,5,7},
    {10,0,1,3,5,6,8}
]
knname = [
    ['A','A#','B','C','C#','D','D#','E','F','F#','G','G#'],
    ['A','A#','B','C','C#','D','D#','E','F','F#','G','G#'],
    ['A','Bb','B','C','C#','D','Eb','E','F','F#','G','Ab'],
    ['A','A#','B','C','C#','D','D#','E','F','F#','G','G#'],
    ['A','Bb','B','C','C#','D','Eb','E','F','F#','G','G#'],
]

n=int(input())
l = []
for _ in range(n):
    f=float(input())
    l.append(v(f))
# print(l)
s=set(l)
m = -1
for i in range(5):
    if s & key[i] == s:
        if m != -1:
            print('cannot determine key')
            exit(0)
        m = i
if m == -1:
    print('cannot determine key')
    exit(0)
print(kname[m])
for i in l:
    print(knname[m][i])
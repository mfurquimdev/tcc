from itertools import *

class Counter(dict):
    def __missing__(self, key):
        return 0

c = Counter()
for n in range(0,4):
    a = permutations('RGB', n)
    for it in a:
        c[it] += 1

i = 0
for b in c:
    print (str(i) + ": " + "".join(b))
    i += 1

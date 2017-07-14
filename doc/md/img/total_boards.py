#!/usr/bin/python3

from math import factorial

def binom(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))

def ntab_inicial(c,d):
    tabs = 1
    total = c*d
    for i in range(0,c):
        tabs *= binom(total-(i*d),d)
    return tabs

 
for c in range(2,6):
    for d in range(2,5):
        with open("{}_{}.txt".format(c,d), 'w') as f:
            f.write(str(ntab_inicial(c,d))+'\n')


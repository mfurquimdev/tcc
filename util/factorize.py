from math import *

def big_mult(number_list):
    number = 1;
    for n in number_list:
        number *= n
    return prime_factorize(number)

def prime_factorize(n):
    factors = []
    number = abs(n)
    while number > 1:
        factor = get_next_prime_factor(number)
        factors.append(factor)
        number /= factor
    if n < -1:
            factors[0] = -factors[0]
    return factors

def get_next_prime_factor(n):
    if n%2 == 0:
        return 2
    for x in range(3, int(sqrt(n)+1), 2):
        if n%x == 0:
            return x
    return n

all_prime_factors = []

def add_prime_factors(prime_factors):
    for p in prime_factors:
        all_prime_factors.append(p)

add_prime_factors(big_mult([55,54,53,52,51]))
add_prime_factors(big_mult([50,49,48,47,46]))
add_prime_factors(big_mult([45,44,43,42,41]))
add_prime_factors(big_mult([40,39,38,37,36]))
add_prime_factors(big_mult([35,34,33,32,31]))
add_prime_factors(big_mult([30,29,28,27,26]))
add_prime_factors(big_mult([25,24,23,22,21]))
add_prime_factors(big_mult([20,19,18,17,16]))
add_prime_factors(big_mult([15,14,13,12,11]))
add_prime_factors(big_mult([10,9,8,7,6]))
add_prime_factors(big_mult([5,4,3,2,1]))

class Counter(dict):
    def __missing__(self, key):
        return 0

c = Counter()
for n in all_prime_factors:
    c[n] += 1

# print c

def binom(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))

num_games = 4*binom(55,5)*binom(50,5)*binom(45,9)*binom(36,9)*binom(27,9)*binom(18,9)*binom(9,9)
print num_games < 10**42

years = (num_games/(60*60*24*365))
print years < 10**35

num_estados = (2**55)*(61*5*72)
print num_estados < 10**21

years = (num_estados/(60*60*24*365))
print years < 10**14

print num_estados
num_estados = (2**55)*(11*5*72)
print num_estados
years = (num_estados/(60*60*24*365))
print years

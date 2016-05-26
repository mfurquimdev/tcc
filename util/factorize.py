from math import *

pf = 0

all_prime_factors = []

class Counter(dict):
    def __missing__(self, key):
        return 0

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


def add_prime_factors(prime_factors):
    for p in prime_factors:
        all_prime_factors.append(p)

if (pf == 1):
    for n in range(1,56):
        add_prime_factors(prime_factorize(n))

    c = Counter()
    for n in all_prime_factors:
        c[n] += 1
    # print c

def binom(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))

seconds_in_a_year = 60*60*24*365

print ("\nQuantidade de jogos distintos")

num_games = int(4*binom(55,5)*binom(50,5)*binom(45,9)*binom(36,9)*binom(27,9)*binom(18,9)*binom(9,9))
years = int(num_games/seconds_in_a_year)

print ("#game:\t" + str(num_games))
print ("years:\t" + str(years))
print ("#game:\t%e" % num_games)
print ("years:\t%e" % years)

print ("\nQuantidade de estados para cada jogo")
num_estados = int((2**55)*(61**5)*(10**5 + 6**2))
years = int(num_estados/seconds_in_a_year)

print ("#stat:\t" + str(num_estados))
print ("years:\t" + str(years))
print ("#stat:\t%e" % num_estados)
print ("years:\t%e" % years)

print ("\nPoda 1: Cada peão pode estar apenas em cima de discos da sua própria cor")
num_estados = int((2**55)*(11**5)*(10**5 + 6**2))
years = int(num_estados/seconds_in_a_year)

print ("#stat:\t" + str(num_estados))
print ("years:\t" + str(years))
print ("#stat:\t%e" % num_estados)
print ("years:\t%e" % years)

print ("\nW/o Board")
num_estados = int((11**5)*(10**5 + 6**2))
years = int(num_estados/seconds_in_a_year)

print ("#stat:\t" + str(num_estados))
print ("years:\t" + str(years))

# print (3**22)*3*5*6
# Poda 2: Nem todos os estados de tabuleiro são possíveis (?)

n = (2**(11*5)*61**5*(11**25)*6**10*5)

# print (log10(n)+1 )

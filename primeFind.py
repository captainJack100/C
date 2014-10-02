#
#	Stupid way to find primes
#	Run with pypy b/c it's slow
#

from math import sqrt

def findPrime(max):
	primeList = {}
	max = max + 1
	
	for x in xrange(2, max):
		primeList[x] = True
		for y in xrange(2, int(sqrt(x)) + 1):
			if x % y == 0:
				primeList[x] = False
	
	#print [x for x in primeList if primeList[x] == True]

def main():
	findPrime(1000000)

if __name__ == "__main__":
	main()

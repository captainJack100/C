""" Recursion Refactoring
Generally, Tail recusion is optimized in some languages (e.g. Lisp).
How to refactor recursion into interation. 2 cases.
	1. Tail recursion (nothing is left over on stack)
	2. regular recursion. Use stack.

General rules for making stack (heuristic ... not always true)
	1. Have a stack for each parameter. Stack frame remebers the parameters
	2. Have place to store running values
	3. Have loop that loops until stack is empty
"""

###########################################
# Tail recursive case. Only iterate if Compiler
# Doesn't optimize.
############################################
def countdown (n):
	""" Tail recursive function. 
	"""
	if (n == 0):
		return
	print "% d " % n
	countdown(n-1)

def countdownIt (n):
	"""Refactored
	1. Find base case (n == 0). Turn into stopping criteria
	2. Make progress by iterating instead of calling function.
	"""
	while (n > 0):
		print "%d " % n
		n = n -1

################################################
# Factorail tail recursion.
###############################################3

def fac2 (n, acc):
	""" tail recursive
	"""
	if (n == 0):
		return acc
	return fac2(n-1, acc*n)

def fac3 (n):
	""" iteration from tail recursive
	1. Find base case (n == 0)
	2. Make progress towards the base case by using some accumulator variable.
	"""
	ans = 1
	while (n > 0):
		ans = ans*n
		n = n-1
	return ans

##################################################
# Regular recursion. Use stack in free store instead
# compiler stack.
###################################################

def fac4 (n):
	""" Non-tail recursive
	"""
	if (n == 0):
		return 1
	return n*fac4(n-1)

def fac5 (n):
	""" Poor example. But illustrates the point.
	"""
	stack = []
	stack.append(n)
	acc = 1	

	while (stack):
		currN = stack.pop()
		acc = acc*currN
		if (currN == 1):
			return acc
		stack.append(currN -1)

############################################3

def main():
	print fac5(5)

if __name__ == '__main__':
	main()

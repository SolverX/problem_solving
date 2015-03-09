import math
def sum_digits(n):
   r = 0
   while n:
       r, n = r + n % 10, n / 10
   return r
for x in range(1, 1000001):
	print sum_digits(math.factorial(x))
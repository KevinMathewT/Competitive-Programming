import random

n = int(random.random() * (100000-1)) + 1
print(n)

for i in range(0, n):
	print(int(random.random() * ((10 ** 9) - 100000)) + 100000)
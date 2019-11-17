import random

t = 0 #int(random.random() * (100000-1)) + 1
print(100000)

d = {}

for i in range(0, 100):
	# print((2 ** i), "-----")
	if((2 ** i) <= (10 ** 18)):
		for j in range(((2 ** i) - 10), ((2 ** i) + 11)):
			if j < 1 or j in d:
				continue
			d[j] = 1
			print(j)
			t = t + 1

for i in range((10 ** 18) - 1000, 10 ** 18 + 1):
	print(i)
	t = t + 1

for i in range(100000 - t):
	print(int(random.random() * ((10 ** 18) - 1000000)) + 1000000)
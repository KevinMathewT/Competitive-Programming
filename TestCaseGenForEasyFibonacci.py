import random

N = 1000
V = 10000000000000
Q = 1000

t = int(random.random() * (N-1)) + 1
print(t, Q)

# d = {}

rl = V - V // N
rr = V

for i in range(0, t):
	val = int(random.random() * (rr-(rl))) + rl
	rl -= V // N
	rr -= V // N
	print(val, end = ' ')

print()

for i in range(0, t):
	print(int(random.random() * (V-1)) + 1, end = ' ')

print()

for i in range(0, Q):
	type = int(random.random() * (2)) + 1
	if type == 1:
		print(type, int(random.random() * (t-1)) + 1, int(random.random() * (V-1)) + 1)
	else:
		print(type, int(random.random() * (t-1)) + 1, int(random.random() * (t-1)) + 1)

print()
# for i in range((10 ** 18) - 1000, 10 ** 18 + 1):
# 	print(i)
# 	t = t + 1

# for i in range(100000 - t):
# 	print(int(random.random() * ((10 ** 18) - 1000000)) + 1000000)
import random

lim = 1

n = lim
m = lim
print(n, m)

for i in range(0, n):
	for j in range(0, m):
		print(int(random.random() * ((10 ** 18) - 0)) + 0, end = " ")
	print()	

# q = int(random.random() * (1000000-1)) + 1
# print(q)

# for i in range(0, q):
# 	t = random.random()
# 	if t > 0.5:
# 		print(2)
# 		print(int(random.random() * ((10 ** 18) - 1000000)) + 1000000)
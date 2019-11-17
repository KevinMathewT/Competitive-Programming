n = int(input())

def rec(x):
	if x == 1:
		return 0
	return x * rec(x - 1) + pow(-1, x)

print(rec(n))
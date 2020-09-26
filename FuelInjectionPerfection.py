def solution(n):
	n = int(n)
	steps = 0

	while n > 1:
		steps = steps + 1

		if n % 2 == 0:
			n /= 2
			continue

		if n == 3:
			n = n - 1
			continue

		if n % 4 == 3:
			n = n + 1
		else:
			n = n - 1

	return steps

print(answer("4"))
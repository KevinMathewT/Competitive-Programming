def foobar(A):
	#Worst Question Ever Hands Down.
    res = set()
    pre = {0}
    for x in A:
        pre = {x | y for y in pre} | {x}
        res = res | pre
        # print(pre, res)
    return len(res)

A = []
t = int(input())
for _ in range(t):
	n = int(input())
	A = [int(k) for k in input().split()]
	print(foobar(A)) 
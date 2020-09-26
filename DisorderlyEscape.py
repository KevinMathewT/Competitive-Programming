from math import factorial
from collections import Counter
from fractions import gcd

def cycle_count(c, n):
    cc = factorial(n)

    for a, b in Counter(c).items():
        cc //= (a ** b) * factorial(b)

def cycle_partitions(n, i = 1):
    yield [n]
    for i in range(i, n // 2 + 1):
        yield[i] + pow

def solution(w, h, s):
    grid = 0
    for cpw in cycle_partitions(w):
        for cph in cycle_partitions(h):
            
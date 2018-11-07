from itertools import combinations
from functools import reduce # not necessary in python 2.x

a = 2
b = 29  

def k_bits_on(k,n):
       one_at = lambda v,i:v[:i]+[1]+v[i+1:]
       return [tuple(reduce(one_at,c,[0]*n)) for c in combinations(range(n),k)]


print(k_bits_on(a, b))
print(len(k_bits_on(a, b)))
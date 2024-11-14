def last_digit(a, b):
    a = int(a)
    b = int(b)
    if a == 0 and b == 0:
        return 1
    if b == 0:
        return 1
    if a == 0:
        return 0
    if b % 4 == 0:
        res = 4
    else:
        res = b % 4
    num = pow(a, res)
    return num % 10
from sys import stdin
a, b = stdin.read().split()
print(last_digit(a,b))


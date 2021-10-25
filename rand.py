#!usr/bin/python3

import random

i = random.randint(-1000, 1000)
print(i)

Lst = [random.randint(-1000, 1000) for i in range(101)]

for i in Lst:
    print(" ",i, end='')

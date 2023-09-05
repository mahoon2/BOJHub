from fractions import *

x1 = Fraction('0')
y1 = Fraction('0')
for _ in range(4):
    [n, m] = list(map(int,input().split()))
    x1 += Fraction(n)
    y1 += Fraction(m)

x1 /= Fraction(4)
y1 /= Fraction(4)

x2 = Fraction('0')
y2 = Fraction('0')
for _ in range(4):
    [n, m] = list(map(int,input().split()))
    x2 += Fraction(n)
    y2 += Fraction(m)

x2 /= Fraction(4)
y2 /= Fraction(4)

p = (y2-y1)/(x2-x1)
q = y1-p*x1

if p.denominator == 1: print(p.numerator, end=' ')
else: print(p, end=' ')
if q.denominator == 1: print(q.numerator)
else: print(q)
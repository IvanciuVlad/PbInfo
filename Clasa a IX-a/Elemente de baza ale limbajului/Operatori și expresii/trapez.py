import math
bm, b, l = map(float, raw_input().split())
m = (bm - b)/2
n = bm - m
h = math.sqrt((l * l) - (m * m))
d = math.sqrt((n * n) + (h * h))
print(str(d))
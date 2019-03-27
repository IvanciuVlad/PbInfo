h1, m1, x, y = map(int, raw_input().split())
h = h1 + x
m = y + m1
if m > 59:
	h = h + 1
	m = m % 60
if h > 23:
	h = h % 24
print(str(h) + " " +  str(m))
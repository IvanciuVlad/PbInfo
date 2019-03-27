h1, m1, x = map(int, raw_input().split())
hx = x // 60
mx = x - (hx * 60)
h = h1 + hx
m = mx + m1


if m > 59:
	h = h + 1
	m = m % 60
if h > 23:
	h = h % 24
print(str(h) + " " +  str(m))
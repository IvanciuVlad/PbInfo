x, y = map(int, raw_input().split())
a = y // x 
if(y % x == 0):
	print(str(a))
else:
  print(str(a + 1))
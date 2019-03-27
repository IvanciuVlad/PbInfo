n = raw_input("")
n = int(n)
s = 0
while(n > 0):
  s += n % 10
  n = n // 10
print(str(s))
  
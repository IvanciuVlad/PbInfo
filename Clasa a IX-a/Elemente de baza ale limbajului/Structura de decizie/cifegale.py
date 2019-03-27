n = raw_input("")
n = int(n)
a = n % 10
n = n // 10
b = n % 10
n = n // 10
c = n
if a == b and b == c:
  print("da")
else:
  print("nu")
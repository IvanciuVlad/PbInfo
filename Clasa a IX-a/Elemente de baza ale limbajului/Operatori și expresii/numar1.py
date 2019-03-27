n = input("")
n = int(n)
u = n % 10
n = n // 10
n = n // 10
s = n
p = (s*10 + u) ** 2
print(str(p))
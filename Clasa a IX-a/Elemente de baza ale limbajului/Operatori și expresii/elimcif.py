n = raw_input("")
n = int(n)
u = n % 10
n = n // 10
n = n // 10
n = n * 10 + u
print(str(n))
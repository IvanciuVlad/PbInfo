n = input("")
n = int(n)
s = 0
s += n % 10
n = n // 10
s += n % 10
n = n // 10
s += n
print(str(s))
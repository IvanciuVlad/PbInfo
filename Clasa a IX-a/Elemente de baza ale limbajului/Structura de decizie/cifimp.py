n = raw_input("")
n = int(n)
ci = 0
while(n > 0):
  if(n%10)%2 == 1:
  	ci += 1
  n = n // 10
print(str(ci))
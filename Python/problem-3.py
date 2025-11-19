num1,num2=input().split()
a=bool(int(num1))
b=bool(int(num2))
print(a and (not b) or ((not a) and b))
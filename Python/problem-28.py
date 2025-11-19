a=int(input())
b=int(input())
print(a*(b%10))  #123 123  1. 123*3  2. 123
print(a*((b // 10)%10))   #4번 계산 이슈 ?? 원인 모름
print(a*(b // 100))       #5번 계산 이슈 ??
print(a*b)
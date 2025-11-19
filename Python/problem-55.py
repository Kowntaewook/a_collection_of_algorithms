num1,num2=map(int, input().split())
result=0
num3=list(map(int, input().split()))[:num2-1]

for i in range(num1):
    if(num3[i] == 3 or num3[i] == 4):
        result+=1
        print(result)
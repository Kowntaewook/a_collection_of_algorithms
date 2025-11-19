num1,num2,num3=input().split()
num1,num2,num3=int(num1),int(num2),int(num3)
c=(num1 if(num1 < num2) else num2) if ((num1 if num1<num2 else num2)<num3) else num3
print(c)
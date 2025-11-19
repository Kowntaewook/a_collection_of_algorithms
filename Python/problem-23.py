a=input()
a=int(a)

for i in range(1, a+1):
    if i%3 and i%6 and i%9 == 0:   #tlqkf 조건 실수
        print("X", end=" ")
    else:
        print(i, end=" ")
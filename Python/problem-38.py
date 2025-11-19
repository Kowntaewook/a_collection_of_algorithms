a,b,c=map(int, input().split())

if a==b and a==c:
    print(1000+a*1000)
elif a==b or a==c or b==c:
    if a==b or a==c:
        print(1000+a*100)
    else:
        print(1000+b*100)
else:
    if a>b and a>c:
        print(a*100)
    elif b>a and a>c:
        print(b*100)
    else:
        print(c*100)
n = int(input())  # 입력받은 정수

if n < 0:  # 음수일 경우
    if n % 2 == 0:
        print('A')  # 음수이면서 짝수
    else:
        print('B')  # 음수이면서 홀수
else:  # 양수일 경우
    if n % 2 == 0:
        print('C')  # 양수이면서 짝수
    else:
        print('D')  # 양수이면서 홀수

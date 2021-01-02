# -*- coding: cp949 -*-
# 계산기 프로그램
# 사용자에게 어떤 연산을 할지와 두개의 숫자를 받는다.
a=raw_input('What to do?\n')
firstnumber=input('first operand')
secondnumber=input('second operand')
# 조건문을 이용하여 사용자의 답변에 따른 경우를 나눈다.
# 'or'을 이용하여 사용자가 둘중 아무 명령어나 입력해도 가능하도록 한다.
if a=='+' or a=='add':
    print ('result is %.2f') %(firstnumber+secondnumber)
elif a=='-' or a=='sub':
# 사용자에게 연산 순서를 묻는다.
    b=raw_input('first - second or second - first? (f-s or s-f)\n')
# 조건문안에 조건문을 넣어 연산 순서를 지정한다.
    if b=='f-s':
        print ('result is %.2f') %(firstnumber-secondnumber)
    else:
        print ('result is %.2f') %(secondnumber-firstnumber)
elif a=='*' or a=='mul':
    print ('result is %.2f') %(firstnumber*secondnumber)
elif a=='/' or a=='div':
# 사용자에게 연산 순서를 묻는다.
    c=raw_input('first / second or second / first? (f/s or s/f)\n')
# 조건문안에 조건문을 넣어 연산 순서를 지정한다.
# 분모가 0이 될 경우 에러 메시지가 출력되도록 한다.
    if c=='f/s':
        if secondnumber==0:
            print 'can\'t divide by zero!!'
        else:
            print ('result is %.2f') %(firstnumber/secondnumber)
    else:
        if firstnumber==0:
            print 'can\'t divide by zero!!'
        else:
            print ('result is %.2f') %(secondnumber/firstnumber)

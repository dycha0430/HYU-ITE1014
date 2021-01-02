# -*- coding: cp949 -*-
#a를 빈 리스트로 놓는다.
a=[]
#덧셈을 하는 함수를 정의한다.
def sum(a):
#total을 0으로 놓고 반복문 for을 이용하여 a에 있는
#원소들이 total에 하나씩 더해지도록 한다.
    total = 0
    for argument in a:
        total += argument
#total값을 리턴한다.
    return total
#뺄셈을 하는 함수를 정의한다.
#c,d를 매개변수로 두고 (c-d)값을 리턴한다.
def sub(c,d):
    return c-d
#e를 빈 리스트로 놓는다.
e=[]
#곱셈을 하는 함수를 정의한다.
def mul(e):
#total을 1로 두고 반복문 for을 이용하여 e에 있는
#원소들이 total에 하나씩 곱해지도록 한다.
    total=1
    for argument in e:
        total *= argument
#total값을 리턴한다.
    return total
#나눗셈을 하는 함수를 정의한다.
#g,h를 매개변수로 두고 (g/h)값을 리턴한다.
def div(g,h):
    return g/h
#무한루프에서 메뉴를 출력하기 위해 while에 항상 참인 명제를 조건문으로 넣는다.
while 1==1:
#메뉴를 출력한다.(여러 줄을 출력해야하므로 '''를 이용한다.)
    print '''
-----------------------------
         Calculator
-----------------------------
         What to do?
-----------------------------
1.add
2.sub
3.mul
4.div
0.quit
-----------------------------'''
#무엇을 할지에 대한 답변을 받는다.
    ans=raw_input()
    if ans=='1': #ans이 1이면 아래의 작업을 수행한다.
        print('Input as many as you want (input result to quit)')
        while True: #사용자가 result를 입력할때까지 무한히 반복하기 위해
            #항상 참인 명제를 조건문으로 둔다.
            b=raw_input()
            if b=='result':
                num=len(a) #num을 a의 요소의 개수로 둔다.
                print(str(num)+'numbers added, result is %0.2f' %(sum(a)))
                break #반복문에서 벗어난다.
            else:
                a.append(float(b))#b를 실수형으로 바꿔서 리스트a에 추가한다.
    elif ans=='2':#ans이 2이면 아래의 작업을 수행한다.
        #c,d의 값을 받아서 실수형으로 바꾼다.
        c=float(raw_input('first operand:'))
        d=float(raw_input('second operand:'))
        print ('%0.2f - %0.2f = %0.2f' %(c,d,sub(c,d)))
    elif ans=='3':#ans이 3이면 아래의 작업을 수행한다.
        print('Input as many as you want(input result to quit)')
        while True:#사용자가 result를 입력할때까지 무한히 반복하기 위해
             #항상 참인 명제를 조건문으로 둔다.
            f=raw_input()
            if f=='result':
                ber=len(e) #ber을 e의 요소의 개수로 둔다.
                print(str(ber)+'numbers multiplied, result is %0.2f' %(mul(e)))
                break#반복문에서 벗어난다.
            else:
                e.append(float(f))#f를 실수형으로 바꿔서 리스트e에 추가한다.
    elif ans=='4':#ans이 4이면 아래의 작업을 수행한다.
        #g,h의 값을 받아서 실수형으로 바꾼다
        g=float(raw_input('first operand: '))
        h=float(raw_input('second operand: '))
        if h==0: #분모인 h에 0이 입력되면 에러메시지를 출력한다.
            print ' Can\'t divide by zero!!!'
        else:
            print('%0.2f / %0.2f = %0.2f' %(g,h,div(g,h)))
    elif ans=='0': #ans이 0이면 아래의 작업을 수행한다.
        print 'bye!'
        break #반복문에서 벗어난다.
    else: #위의 경우가 모두 아니라면
        print 'Wrong command!' #에러메시지를 출력한다.
        

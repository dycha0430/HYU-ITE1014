# -*- coding: cp949 -*-
# 행렬 덧셈 함수
def Add_f(raws1,cols1):
     for i in range(raws1): #1번 행렬의 행의 개수만큼 반복한다.
        for j in range(cols1): #1번 행렬의 열의 개수만큼 반복한다.
             list1[i][j]=putlist1[i][j]+putlist2[i][j]
#리스트의 인덱스를 이용하여 빈리스트를 두개의 행렬을 더한 결괏값으로 채운다.
     for i in list1:
        for j in i:
            print (j), #더한 결과의 행렬을 출력한다.
        print '' #한 행이 출력되면 다음 줄로 넘어가도록 한다.

# 행렬 뺄셈 함수(두개의 행렬을 뺀다는 것 제외 위와 동일)
def Sub_f(raws1,cols1):
    for i in range(raws1):
        for j in range(cols1):
            list1[i][j]=putlist1[i][j]-putlist2[i][j]
    for i in list1:
       for j in i:
           print (j),
       print ''

# 행렬 곱셈 함수
def Mul_f(raws1,raws2,cols1,cols2):
    for i in range(raws1): #1번 행렬의 행의 개수만큼 반복한다.
        for j in range(cols2): #2번 행렬의 열의 개수만큼 반복한다.
            for k in range(raws2): #2번 행렬의 행의 개수만큼 반복한다.
                list2[i][j]+=putlist1[i][k]*putlist2[k][j]
#행렬곱의 법칙을 만족하도록 빈리스트를 채운다.
#행렬곱의 법칙대로 한 행과 한 열을 순서대로 곱하여 차례로 더해준다.
    for i in list2:
       for j in i:
           print (j), #곱한 결과의 행렬을 출력한다.
       print ''

#무한루프로 프로그램이 실행된다.
while True:
    try:
        # 첫번째 행렬의 행의 개수를 입력받는다.
        raws1=input('Input Your First Matrix\'s Rows Size : ')
        if raws1<=0: #행의 개수를 음수 또는 0으로 입력하면 다시 되돌아가도록 한다.
            print 'please input positive number'
            continue
        # 첫번째 행렬의 열의 개수를 입력받는다.
        cols1=input('Input Your First Matrix\'s Cols Size : ')
        if cols1<=0: #열의 개수를 음수 또는 0으로 입력하면 다시 되돌아가도록 한다.
            print 'please input positive number'
            continue
        
    except NameError: #input함수에 문자를 입력하면 예외처리한다.
        print '<ERROR> Input number'
        continue
        
    import random #랜덤모듈을 가져온다.
    # 첫번째 행렬을 만들기 위해 0으로 채워진 빈리스트를 정의한다.
    putlist1=[[0 for i in range(cols1)] for j in range(raws1)]
    for i in range(raws1):
        for j in range(cols1):
    # 위에서 정의한 빈리스트를 0,1,2의 랜덤한 숫자로 채운다.
            putlist1[i][j]=random.randint(0,2)
    for i in putlist1:
        for j in i:
            print (j), # 첫번째 행렬을 출력한다.
        print ('')
        
    try:
        # 두번째 행렬의 행의 개수를 입력받는다.
        raws2=input('Input Your Second Matrix\'s Rows Size : ')
        if raws2<=0:#행의 개수를 음수 또는 0으로 입력하면 다시 되돌아가도록 한다.
            print 'please input positive number'
            continue
        # 두번째 행렬의 열의 개수를 입력받는다.
        cols2=input('Input Your Second Matrix\'s Cols Size : ')
        if cols2<=0:#열의 개수를 음수 또는 0으로 입력하면 다시 되돌아가도록 한다.
            print 'please input positive number'
            continue
        
    except NameError:
        print '<ERROR> Input number'
        continue

    # 두번째 행렬을 만들기 위해 0으로 채워진 빈리스트를 정의한다.
    putlist2=[[0 for i in range(cols2)] for j in range(raws2)]
    for i in range(raws2):
        for j in range(cols2):
    # 위에서 정의한 빈리스트를 0,1,2의 랜덤한 숫자로 채운다.
            putlist2[i][j]=random.randint(0,2)
    for i in putlist2:
        for j in i:
            print (j), # 두번째 행렬을 출력한다.
        print('')

    # 더한 혹은 뺀 결괏값의 행렬을 만들기 위해 0으로 채워진 빈리스트를 정의한다.
    list1=[[0 for i in range(cols1)] for j in range(raws1)]
    # 곱한 결괏값의 행렬을 만들기 위해 0으로 채워진 빈리스트를 정의한다.
    list2=[[0 for i in range(cols2)] for j in range(raws1)]

    if raws1==raws2 and cols1==cols2: 
        if cols1==raws2:
    #어떤 연산을 할지를 입력받는다.
            ans=raw_input( "Input '*' or '+' or '-' : ") 
            if ans=='+':
                Add_f(raws1,cols1) # Add_f함수를 호출한다.
            elif ans=='-':
                Sub_f(raws1,cols1) # Sub_f함수를 호출한다.
            elif ans=='*':
                Mul_f(raws1,raws2,cols1,cols2) # Mul_f함수를 호출한다.
        else:
            ans=raw_input("Input '+' or '-'")
            if ans=='+':
                Add_f(raws1,cols1) 
            if ans=='-':
                Sub_f(raws1,cols1)
    elif cols1==raws2:
        ans=raw_input("Input '*'")
        if ans=='*':
            Mul_f(raws1,raws2,cols1,cols2)
    con=raw_input('Continue? (o or x) : ') # 이어서 할지를 입력받는다.
    if con=='o':
        continue #처음으로 돌아간다.
    elif con=='x':
        break #프로그램을 끝낸다.

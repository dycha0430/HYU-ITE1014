# -*- coding: cp949 -*-
# ��� ���� �Լ�
def Add_f(raws1,cols1):
     for i in range(raws1): #1�� ����� ���� ������ŭ �ݺ��Ѵ�.
        for j in range(cols1): #1�� ����� ���� ������ŭ �ݺ��Ѵ�.
             list1[i][j]=putlist1[i][j]+putlist2[i][j]
#����Ʈ�� �ε����� �̿��Ͽ� �󸮽�Ʈ�� �ΰ��� ����� ���� �ᱣ������ ä���.
     for i in list1:
        for j in i:
            print (j), #���� ����� ����� ����Ѵ�.
        print '' #�� ���� ��µǸ� ���� �ٷ� �Ѿ���� �Ѵ�.

# ��� ���� �Լ�(�ΰ��� ����� ���ٴ� �� ���� ���� ����)
def Sub_f(raws1,cols1):
    for i in range(raws1):
        for j in range(cols1):
            list1[i][j]=putlist1[i][j]-putlist2[i][j]
    for i in list1:
       for j in i:
           print (j),
       print ''

# ��� ���� �Լ�
def Mul_f(raws1,raws2,cols1,cols2):
    for i in range(raws1): #1�� ����� ���� ������ŭ �ݺ��Ѵ�.
        for j in range(cols2): #2�� ����� ���� ������ŭ �ݺ��Ѵ�.
            for k in range(raws2): #2�� ����� ���� ������ŭ �ݺ��Ѵ�.
                list2[i][j]+=putlist1[i][k]*putlist2[k][j]
#��İ��� ��Ģ�� �����ϵ��� �󸮽�Ʈ�� ä���.
#��İ��� ��Ģ��� �� ��� �� ���� ������� ���Ͽ� ���ʷ� �����ش�.
    for i in list2:
       for j in i:
           print (j), #���� ����� ����� ����Ѵ�.
       print ''

#���ѷ����� ���α׷��� ����ȴ�.
while True:
    try:
        # ù��° ����� ���� ������ �Է¹޴´�.
        raws1=input('Input Your First Matrix\'s Rows Size : ')
        if raws1<=0: #���� ������ ���� �Ǵ� 0���� �Է��ϸ� �ٽ� �ǵ��ư����� �Ѵ�.
            print 'please input positive number'
            continue
        # ù��° ����� ���� ������ �Է¹޴´�.
        cols1=input('Input Your First Matrix\'s Cols Size : ')
        if cols1<=0: #���� ������ ���� �Ǵ� 0���� �Է��ϸ� �ٽ� �ǵ��ư����� �Ѵ�.
            print 'please input positive number'
            continue
        
    except NameError: #input�Լ��� ���ڸ� �Է��ϸ� ����ó���Ѵ�.
        print '<ERROR> Input number'
        continue
        
    import random #��������� �����´�.
    # ù��° ����� ����� ���� 0���� ä���� �󸮽�Ʈ�� �����Ѵ�.
    putlist1=[[0 for i in range(cols1)] for j in range(raws1)]
    for i in range(raws1):
        for j in range(cols1):
    # ������ ������ �󸮽�Ʈ�� 0,1,2�� ������ ���ڷ� ä���.
            putlist1[i][j]=random.randint(0,2)
    for i in putlist1:
        for j in i:
            print (j), # ù��° ����� ����Ѵ�.
        print ('')
        
    try:
        # �ι�° ����� ���� ������ �Է¹޴´�.
        raws2=input('Input Your Second Matrix\'s Rows Size : ')
        if raws2<=0:#���� ������ ���� �Ǵ� 0���� �Է��ϸ� �ٽ� �ǵ��ư����� �Ѵ�.
            print 'please input positive number'
            continue
        # �ι�° ����� ���� ������ �Է¹޴´�.
        cols2=input('Input Your Second Matrix\'s Cols Size : ')
        if cols2<=0:#���� ������ ���� �Ǵ� 0���� �Է��ϸ� �ٽ� �ǵ��ư����� �Ѵ�.
            print 'please input positive number'
            continue
        
    except NameError:
        print '<ERROR> Input number'
        continue

    # �ι�° ����� ����� ���� 0���� ä���� �󸮽�Ʈ�� �����Ѵ�.
    putlist2=[[0 for i in range(cols2)] for j in range(raws2)]
    for i in range(raws2):
        for j in range(cols2):
    # ������ ������ �󸮽�Ʈ�� 0,1,2�� ������ ���ڷ� ä���.
            putlist2[i][j]=random.randint(0,2)
    for i in putlist2:
        for j in i:
            print (j), # �ι�° ����� ����Ѵ�.
        print('')

    # ���� Ȥ�� �� �ᱣ���� ����� ����� ���� 0���� ä���� �󸮽�Ʈ�� �����Ѵ�.
    list1=[[0 for i in range(cols1)] for j in range(raws1)]
    # ���� �ᱣ���� ����� ����� ���� 0���� ä���� �󸮽�Ʈ�� �����Ѵ�.
    list2=[[0 for i in range(cols2)] for j in range(raws1)]

    if raws1==raws2 and cols1==cols2: 
        if cols1==raws2:
    #� ������ ������ �Է¹޴´�.
            ans=raw_input( "Input '*' or '+' or '-' : ") 
            if ans=='+':
                Add_f(raws1,cols1) # Add_f�Լ��� ȣ���Ѵ�.
            elif ans=='-':
                Sub_f(raws1,cols1) # Sub_f�Լ��� ȣ���Ѵ�.
            elif ans=='*':
                Mul_f(raws1,raws2,cols1,cols2) # Mul_f�Լ��� ȣ���Ѵ�.
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
    con=raw_input('Continue? (o or x) : ') # �̾ ������ �Է¹޴´�.
    if con=='o':
        continue #ó������ ���ư���.
    elif con=='x':
        break #���α׷��� ������.

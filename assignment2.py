# -*- coding: cp949 -*-
#a�� �� ����Ʈ�� ���´�.
a=[]
#������ �ϴ� �Լ��� �����Ѵ�.
def sum(a):
#total�� 0���� ���� �ݺ��� for�� �̿��Ͽ� a�� �ִ�
#���ҵ��� total�� �ϳ��� ���������� �Ѵ�.
    total = 0
    for argument in a:
        total += argument
#total���� �����Ѵ�.
    return total
#������ �ϴ� �Լ��� �����Ѵ�.
#c,d�� �Ű������� �ΰ� (c-d)���� �����Ѵ�.
def sub(c,d):
    return c-d
#e�� �� ����Ʈ�� ���´�.
e=[]
#������ �ϴ� �Լ��� �����Ѵ�.
def mul(e):
#total�� 1�� �ΰ� �ݺ��� for�� �̿��Ͽ� e�� �ִ�
#���ҵ��� total�� �ϳ��� ���������� �Ѵ�.
    total=1
    for argument in e:
        total *= argument
#total���� �����Ѵ�.
    return total
#�������� �ϴ� �Լ��� �����Ѵ�.
#g,h�� �Ű������� �ΰ� (g/h)���� �����Ѵ�.
def div(g,h):
    return g/h
#���ѷ������� �޴��� ����ϱ� ���� while�� �׻� ���� ������ ���ǹ����� �ִ´�.
while 1==1:
#�޴��� ����Ѵ�.(���� ���� ����ؾ��ϹǷ� '''�� �̿��Ѵ�.)
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
#������ ������ ���� �亯�� �޴´�.
    ans=raw_input()
    if ans=='1': #ans�� 1�̸� �Ʒ��� �۾��� �����Ѵ�.
        print('Input as many as you want (input result to quit)')
        while True: #����ڰ� result�� �Է��Ҷ����� ������ �ݺ��ϱ� ����
            #�׻� ���� ������ ���ǹ����� �д�.
            b=raw_input()
            if b=='result':
                num=len(a) #num�� a�� ����� ������ �д�.
                print(str(num)+'numbers added, result is %0.2f' %(sum(a)))
                break #�ݺ������� �����.
            else:
                a.append(float(b))#b�� �Ǽ������� �ٲ㼭 ����Ʈa�� �߰��Ѵ�.
    elif ans=='2':#ans�� 2�̸� �Ʒ��� �۾��� �����Ѵ�.
        #c,d�� ���� �޾Ƽ� �Ǽ������� �ٲ۴�.
        c=float(raw_input('first operand:'))
        d=float(raw_input('second operand:'))
        print ('%0.2f - %0.2f = %0.2f' %(c,d,sub(c,d)))
    elif ans=='3':#ans�� 3�̸� �Ʒ��� �۾��� �����Ѵ�.
        print('Input as many as you want(input result to quit)')
        while True:#����ڰ� result�� �Է��Ҷ����� ������ �ݺ��ϱ� ����
             #�׻� ���� ������ ���ǹ����� �д�.
            f=raw_input()
            if f=='result':
                ber=len(e) #ber�� e�� ����� ������ �д�.
                print(str(ber)+'numbers multiplied, result is %0.2f' %(mul(e)))
                break#�ݺ������� �����.
            else:
                e.append(float(f))#f�� �Ǽ������� �ٲ㼭 ����Ʈe�� �߰��Ѵ�.
    elif ans=='4':#ans�� 4�̸� �Ʒ��� �۾��� �����Ѵ�.
        #g,h�� ���� �޾Ƽ� �Ǽ������� �ٲ۴�
        g=float(raw_input('first operand: '))
        h=float(raw_input('second operand: '))
        if h==0: #�и��� h�� 0�� �ԷµǸ� �����޽����� ����Ѵ�.
            print ' Can\'t divide by zero!!!'
        else:
            print('%0.2f / %0.2f = %0.2f' %(g,h,div(g,h)))
    elif ans=='0': #ans�� 0�̸� �Ʒ��� �۾��� �����Ѵ�.
        print 'bye!'
        break #�ݺ������� �����.
    else: #���� ��찡 ��� �ƴ϶��
        print 'Wrong command!' #�����޽����� ����Ѵ�.
        

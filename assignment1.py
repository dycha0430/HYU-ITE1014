# -*- coding: cp949 -*-
# ���� ���α׷�
# ����ڿ��� � ������ ������ �ΰ��� ���ڸ� �޴´�.
a=raw_input('What to do?\n')
firstnumber=input('first operand')
secondnumber=input('second operand')
# ���ǹ��� �̿��Ͽ� ������� �亯�� ���� ��츦 ������.
# 'or'�� �̿��Ͽ� ����ڰ� ���� �ƹ� ��ɾ �Է��ص� �����ϵ��� �Ѵ�.
if a=='+' or a=='add':
    print ('result is %.2f') %(firstnumber+secondnumber)
elif a=='-' or a=='sub':
# ����ڿ��� ���� ������ ���´�.
    b=raw_input('first - second or second - first? (f-s or s-f)\n')
# ���ǹ��ȿ� ���ǹ��� �־� ���� ������ �����Ѵ�.
    if b=='f-s':
        print ('result is %.2f') %(firstnumber-secondnumber)
    else:
        print ('result is %.2f') %(secondnumber-firstnumber)
elif a=='*' or a=='mul':
    print ('result is %.2f') %(firstnumber*secondnumber)
elif a=='/' or a=='div':
# ����ڿ��� ���� ������ ���´�.
    c=raw_input('first / second or second / first? (f/s or s/f)\n')
# ���ǹ��ȿ� ���ǹ��� �־� ���� ������ �����Ѵ�.
# �и� 0�� �� ��� ���� �޽����� ��µǵ��� �Ѵ�.
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

#include <stdio.h>
#include <stdlib.h>
//���� �Լ��� �����Ѵ�.
float add(float a,float b) {
    return a+b;}
//���� �Լ��� �����Ѵ�.
float sub(float a,float b) {
    return a-b;}
//���� �Լ��� �����Ѵ�.
float mul(float a,float b) {
    return a*b;}
//������ �Լ��� �����Ѵ�.
float div1(float a,float b) {
    return a/b;}
//������ ���Ѵ�.
char ans;
char v1[100],v2[100],input[100];
float v3 = 0, v4 = 0, v5 = 0, v6 = 0;

int main(void){
    //���� �̸��� ����Ѵ�.
    printf("\n---------------------------------\n");
    printf("          Last Calculator        \n");
    printf("---------------------------------\n");
    printf("---------------------------------\n");
    do{
        //���� �޴��� ����Ѵ�.
        printf("1. add\n2. sub\n3. mul\n4. div\n0. exit\n");
        printf("---------------------------------\n>>> ");
        scanf(" %c", &ans); //�޴��� �Է¹޴´�.
        if (ans=='1'){
        printf("Input first operand: ");
        scanf("%s", v1); //ù��° ���ڸ� �Է¹޴´�.
        v3=atof(v1); //v1�� �Ǽ������� �ٲپ� v3�� �ִ´�.
        while (v3==0){
            if (v1[0]=='0'){
            break; //v3�� 0�϶�, v1[0]�� 0�̸� �Էµ� ���ڰ� 0�̹Ƿ� while������ Ż���Ѵ�.
            }
            else { //���� ��찡 �ƴ϶�� �߸� �Էµ� ���̹Ƿ� �ٽ� �Է¹޴´�.
            printf("Wrong input! Input again: ");
            scanf("%s", v1);
            v3=atof(v1);
            }
        }
        printf("Input second operand: ");
        scanf("%s", v2); //�ι�° ���ڸ� �Է¹޴´�.
        v4=atof(v2); //���� ������ ���.
        while (v4==0){
            if (v2[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v2);
            v4=atof(v2);
            }
        }
        v5=add(v3,v4); //�Լ��� ȣ���ؼ� ���ϰ��� v5�� �ִ´�.
        printf("Result is %0.4f", v5);} //����� ����Ѵ�.
    //�Ʒ� ������ ���� ����
    else if (ans=='2'){
        printf("Input first operand: ");
        scanf("%s", v1);
        v3=atof(v1);
        while (v3==0){
            if (v1[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v1);
            v3=atof(v1);
            }
        }
        printf("Input second operand: ");
        scanf("%s", v2);
        v4=atof(v2);
        while (v4==0){
            if (v2[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v2);
            v4=atof(v2);
            }
        }
        v5=sub(v3,v4);
        printf("Result is %.4f", v5);
        }
    else if (ans=='3'){
        printf("Input first operand: ");
        scanf("%s", v1);
        v3=atof(v1);
        while (v3==0){
            if (v1[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v1);
            v3=atof(v1);
            }
        }
        printf("Input second operand: ");
        scanf("%s", v2);
        v4=atof(v2);
        while (v4==0){
            if (v2[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v2);
            v4=atof(v2);
            }
        }
        v5=mul(v3,v4);
        printf("Result is %.4f", v5);
    }
    else if (ans=='4'){
        do{
        printf("Input first operand: ");
        scanf("%s", v1);
        v3=atof(v1);
        while (v3==0){
            if (v1[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v1);
            v3=atof(v1);
            }
        }
        printf("Input second operand: ");
        scanf("%s", v2);
        v4=atof(v2);
        while (v4==0){
            if (v2[0]=='0'){
            break;
            }
            else {
            printf("Wrong input! Input again: ");
            scanf("%s", v2);
            v4=atof(v2);
            }
        }
        if (v4==0){ //�и� 0�̸� �޽����� ����Ѵ�.
            printf("Can't divide by zero\n");
        }
        else{ //�и� 0�� �ƴϸ� ���� ����Ѵ�.
            v5=div1(v3,v4);
            printf("Result is %.4f", v5);
            }
        }while(v4==0); //v4�� 0�� ���� �ݺ��Ͽ� 0���� ������ ���� �����Ѵ�.
    }
    else if (ans=='0'){
        printf("Good bye!");}
    else {printf("Wrong command!");}
    }while(ans!='1'&&ans!='2'&&ans!='3'&&ans!='4'&&ans!='0');
    //�Է¹��� ���� 1,2,3,4,0�� ��� �ƴ϶�� �ݺ��Ѵ�.

//ans�� 0�� �ƴ϶�� �ݺ��Ѵ�.
    while(ans!=0){
            //�޴��� ����Ѵ�.
        printf("\n---------------------------------\n");
        printf("1. add\n2. sub\n3. mul\n4. div\n0. exit\n");
        printf("---------------------------------\n>>> ");
        scanf(" %c", &ans);
        if(ans=='1'){
            printf("%.4f + ", v5); //���� ����� ����Ѵ�.
            scanf("%s",input); //���� ������ ���ڸ� �Է¹޴´�.
            v6=atof(input);
            while (v6==0){
                if (input[0]=='0'){
                break;
                }
                else {
                printf("Wrong input! Input again: ");
                scanf("%s", input);
                v6=atof(input);
                }
            }
            v5=add(v5,v6);
            printf("Result is %.4f", v5);}
        else if(ans=='2'){ //���� ����
            printf("%.4f - ", v5);
            scanf(" %s",input);
            v6=atof(input);
            while (v6==0){
                if (input[0]=='0'){
                break;
                }
                else {
                printf("Wrong input! Input again: ");
                scanf("%s", input);
                v6=atof(input);
                }
            }
            v5=sub(v5,v6);
            printf("Result is %.4f", v5);
        }
        else if(ans=='3'){
            printf("%.4f * ", v5);
            scanf(" %s",input);
            v6=atof(input);
            while (v6==0){
                if (input[0]=='0'){
                break;
                }
                else {
                printf("Wrong input! Input again: ");
                scanf("%s", input);
                v6=atof(input);
                }
            }
            v5=mul(v5,v6);
            printf("Result is %.4f", v5);
        }
        else if(ans=='4'){
            printf("%.4f / ", v5);
            scanf(" %s",input);
            v6=atof(input);
            while (v6==0){
                if (input[0]=='0'){
                break;
                }
                else {
                printf("Wrong input! Input again: ");
                scanf("%s", input);
                v6=atof(input);
                }
            }
            if(v6==0){
                printf("Can't divide by zero\n");
                printf("Result is %.4f",v5);
            }
            else{
            v5=div1(v5,v6);
            printf("Result is %.4f", v5);
            }}
        else if(ans=='0'){
            printf("Good bye!");
            break;}
        else{
            printf("wrong command!");
        }
        }
  return 0; }




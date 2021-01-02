#include <stdio.h>
#include <stdlib.h>
//덧셈 함수를 정의한다.
float add(float a,float b) {
    return a+b;}
//뺄셈 함수를 정의한다.
float sub(float a,float b) {
    return a-b;}
//곱셈 함수를 정의한다.
float mul(float a,float b) {
    return a*b;}
//나눗셈 함수를 정의한다.
float div1(float a,float b) {
    return a/b;}
//변수를 선한다.
char ans;
char v1[100],v2[100],input[100];
float v3 = 0, v4 = 0, v5 = 0, v6 = 0;

int main(void){
    //계산기 이름을 출력한다.
    printf("\n---------------------------------\n");
    printf("          Last Calculator        \n");
    printf("---------------------------------\n");
    printf("---------------------------------\n");
    do{
        //계산기 메뉴를 출력한다.
        printf("1. add\n2. sub\n3. mul\n4. div\n0. exit\n");
        printf("---------------------------------\n>>> ");
        scanf(" %c", &ans); //메뉴를 입력받는다.
        if (ans=='1'){
        printf("Input first operand: ");
        scanf("%s", v1); //첫번째 숫자를 입력받는다.
        v3=atof(v1); //v1을 실수형으로 바꾸어 v3에 넣는다.
        while (v3==0){
            if (v1[0]=='0'){
            break; //v3이 0일때, v1[0]이 0이면 입력된 숫자가 0이므로 while문에서 탈출한다.
            }
            else { //위의 경우가 아니라면 잘못 입력된 것이므로 다시 입력받는다.
            printf("Wrong input! Input again: ");
            scanf("%s", v1);
            v3=atof(v1);
            }
        }
        printf("Input second operand: ");
        scanf("%s", v2); //두번째 숫자를 입력받는다.
        v4=atof(v2); //위와 동일한 경우.
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
        v5=add(v3,v4); //함수를 호출해서 리턴값을 v5에 넣는다.
        printf("Result is %0.4f", v5);} //결과를 출력한다.
    //아래 경우들은 위와 동일
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
        if (v4==0){ //분모가 0이면 메시지를 출력한다.
            printf("Can't divide by zero\n");
        }
        else{ //분모가 0이 아니면 값을 출력한다.
            v5=div1(v3,v4);
            printf("Result is %.4f", v5);
            }
        }while(v4==0); //v4가 0인 동안 반복하여 0으로 나누는 것을 방지한다.
    }
    else if (ans=='0'){
        printf("Good bye!");}
    else {printf("Wrong command!");}
    }while(ans!='1'&&ans!='2'&&ans!='3'&&ans!='4'&&ans!='0');
    //입력받은 것이 1,2,3,4,0이 모두 아니라면 반복한다.

//ans이 0이 아니라면 반복한다.
    while(ans!=0){
            //메뉴를 출력한다.
        printf("\n---------------------------------\n");
        printf("1. add\n2. sub\n3. mul\n4. div\n0. exit\n");
        printf("---------------------------------\n>>> ");
        scanf(" %c", &ans);
        if(ans=='1'){
            printf("%.4f + ", v5); //이전 결과를 출력한다.
            scanf("%s",input); //다음 연산할 숫자를 입력받는다.
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
        else if(ans=='2'){ //위와 같음
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




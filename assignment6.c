#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//메뉴를 출력하는 함수.
void printMenu(void)
{
    printf("----------- Lottery Ticket -----------\n");
    printf("--------------------------------------\n");
    printf("1. Buy tickets\n");
    printf("2. Spent money\n");
    printf("3. Earned money\n");
    printf("4. Buy until I get 4th or higher prize\n");
    printf("0. exit\n");
    printf("--------------------------------------\n");
}



//번호 6개를 중복없이 생성하여 그 일차원배열을 리턴하는 함수.
int* newTicket(void)
{
    int ctr = 0;
    //번호 6개가 들어갈 일차원 배열을 생성한다.
    int * arr = NULL;
    arr = (int *)malloc(6*sizeof(int));

    //중복없이 6개의 숫자를 뽑는다.
    for(int i = 0; i<6; i++)
        {
            while(1){
                //1~45까지의 숫자 중 하나를 뽑는다.
                arr[i] = rand()%45 + 1;
                ctr = 0;
                for(int j = 0; j < i; j++){
                    if (arr[i]==arr[j])
                    {
                       //중복되는게 있으면 ctr을 증가시킨다.
                       ctr++;
                    }
                }
                //ctr이 0이 아니라면 돌아가 숫자를 다시 받는다.
                if (ctr!=0){continue;}
                // 아니라면 while문으로 돌아간다.
                else {break;}
            }
        }

    //버블소트로 오름차순으로 정렬한다.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}










int main(void)
{
    srand(time(NULL));
    int earnedMoney = 0, ticketSum = 0;
    int rank3 = 0, rank4 = 0, rank5 = 0, rank1 = 0, rank2 = 0;
    int bonusNum = 0, n = 0, t = 0;


    //지금까지 구매한 티켓들의 목록을 넣을 배열을 생성한다.
    int** doubleArr = NULL;
    doubleArr = (int**)malloc(1*sizeof(int*));
    doubleArr[0] = (int *)malloc(6*sizeof(int));

    //당첨번호 6개가 들어갈 일차원 배열을 생성한다.
    int * arr = NULL;
    arr = (int *)malloc(6*sizeof(int));

    //보너스 번호 1개를 뽑는다.
    bonusNum = rand()%45+1;

    //중복되지 않게 당첨 번호 6개를 생성한다.
    for(int i = 0; i<6; i++)
        {
            while(1){
                arr[i] = rand()%45 + 1; //번호를 뽑는다.
                t = 0;
                for(int j = 0; j < i; j++){
                    if (arr[i]==arr[j] || arr[i] == bonusNum)
                    {
                       t++; //당첨번호나 보너스번호와 중복되는게 있으면 t를 증가시킨다.
                    }
                }
                if(t!=0){continue;} //t가 0이 아니라면 되돌아가서 숫자를 다시 받는다.
                else{break;}
            }
        }

    //당첨 번호 6개가 든 배열을 오름차순으로 정렬한다. (버블소트 사용)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    //무한 루프로 반복한다.
   while (1)
   {
        int num = 0, rightBonus = 0, ticketNum = 0, ctr = 0, rightNum = 0;
        int rank_1 = 0, rank_2 = 0, rank_3 = 0, rank_4 = 0, rank_5 = 0;
        char ans;
        int * a;
        printf("\n");
        //메뉴를 출력한다.
        printMenu();
        //몇번 메뉴를 출력할지 입력받는다.
        scanf(" %d", &num);


        if (num == 1)
        {
            n++;
            printf("\nHow many lines will you buy? : ");
            //몇개의 복권을 구매할지 입력받는다.
            scanf("%d", &ticketNum);
            //전체 티켓의 개수를 계산한다.
            ticketSum += ticketNum;


            //첫번째 돈다면 malloc으로 구매복권목록의 크기를 지정한다.
            if(n == 1){
                for(int i = 0; i < ticketNum; i++){
                    doubleArr[i] = (int*)malloc(6*sizeof(int));
                }
            }
            //두번째 이후부터는 realloc으로 공간을 확보하고 추가된 공간안에 6짜리 일차원배열을 만든다.
            else {
                doubleArr = (int**)realloc(doubleArr, ticketSum*sizeof(int*));
                for(int i = ticketSum-ticketNum; i < ticketSum; i++ ){
                    doubleArr[i] = (int*)malloc(6*sizeof(int));}
            }
            // newTicket함수로 복권번호를 목록에 추가한다.
            for(int i = ticketSum-ticketNum; i < ticketSum ; i++){
                doubleArr[i] = newTicket();
            }
            // 1번에서 뽑은 복권 목록을 출력한다.
            for(int i = ticketSum-ticketNum; i < ticketSum; i++){
                for(int j = 0; j < 6; j++){
                    printf("%3d", doubleArr[i][j]);
                }
                printf("\n");
            }
            // 1번에서 뽑은 복권을 검사하여 당첨된 복권이 있는 경우 rank_n과 rankn 변수를 1씩 증가시킨다.
            for(int i = ticketSum-ticketNum; i < ticketSum; i++){
                rightBonus = 0;
                rightNum = 0;
                for(int j = 0; j<6; j++){
                        //보너스 번호와 같은 번호가 있다면 rightBonus를 1로 한다.
                        if (doubleArr[i][j] == bonusNum){
                            rightBonus = 1;
                        }
                }
                //당첨번호와 구매한 티켓의 번호가 일치하는 게 있다면 rightNum을 1씩 증가시킨다.
                for(int k = 0; k < 6; k++){
                        if(doubleArr[i][k] == arr[k]){
                            rightNum += 1;}
                }

                //rightNum의 개수와 rightBonus에 따라 몇 등에 당첨되었는지 기록한다.
                if(rightNum == 3){
                    rank_5+=1;
                    rank5+=1;
                }
                else if(rightNum == 4){
                    rank_4+=1;
                    rank4+=1;
                }
                else if(rightNum == 5 && rightBonus == 0){
                    rank_3+=1;
                    rank3+=1;
                }
                else if(rightNum == 5 && rightBonus == 1){
                    rank_2+=1;
                    rank2+=1;
                }
                else if(rightNum == 6){
                    rank_1+=1;
                    rank1+=1;
                }
            }
            //당첨된 순위를 출력한다.
            printf("ranking 1 : %d\n", rank_1);
            printf("ranking 2 : %d\n", rank_2);
            printf("ranking 3 : %d\n", rank_3);
            printf("ranking 4 : %d\n", rank_4);
            printf("ranking 5 : %d", rank_5);
        }




        else if (num == 2)
        {
            printf("\nYou bought %d tickets, and the total cost is %d won\n", ticketSum, ticketSum*1000);
        }


        else if (num == 3)
        {
            printf("\n%5d %5d %5d %5d %5d\n", 1,2,3,4,5);
            printf("%5d %5d %5d %5d %5d", rank1, rank2, rank3, rank4, rank5);
            printf("\nYou earned %d won.\n", rank1*2000000000+rank2*100000000+rank3*2000000+rank4*50000+rank5*5000);}


        else if (num == 4)
        {
            int ctr = 0;

            // 입력확인을 한다.
            printf("\nAre you sure? (y or n)");
            scanf(" %c", &ans);

            if (ans == 'y')
            {
                do{
                    rightNum = 0;
                    rightBonus = 0;
                    // 지금까지 구매한 티켓의 수를 센다.
                    ticketSum+=1;
                    int * a = NULL;
                    //일차원 배열을 하나 만들어 6개의 숫자를 저장한다.
                    a = (int *)malloc(6*sizeof(int));
                    a = newTicket();


                    //doubleArr의 공간을 확보하고 새로 뽑은 복권을 목록에 추가한다.
                    doubleArr = (int**)realloc(doubleArr, ticketSum*sizeof(int*));
                    doubleArr[ticketSum - 1] = (int*)malloc(6*sizeof(int));
                    doubleArr[ticketSum - 1] = a;



                    for(int i = 0; i<6; i++){

                        //보너스 번호와 같은 번호가 있다면 rightBonus를 1로 한다.
                        if (a[i] == bonusNum){
                            rightBonus = 1;
                        }
                        //당첨번호와 구매한 티켓의 번호가 일치하는 게 있다면 rightNum을 1씩 증가시킨다.
                        for(int j = 0; j < 6; j++){
                            if(a[i] == arr[j]){
                                rightNum += 1;
                            }
                        }
                    }
                    //rightNum의 개수와 rightBonus에 따라 당첨순위를 기록하고 4번에서 누적된 돈을 계산한다.
                    if(rightNum == 3){
                        earnedMoney += 5000;
                        rank5+=1;
                    }
                    else if(rightNum == 4){
                        earnedMoney += 50000;
                        rank4+=1;
                    }
                    else if(rightNum == 5 && rightBonus == 0){
                        earnedMoney += 2000000;
                        rank3+=1;
                    }
                    else if(rightNum == 5 && rightBonus == 1){
                        earnedMoney += 100000000;
                        rank2+=1;
                    }
                    else if(rightNum == 6){
                        earnedMoney += 2000000000;
                        rank1+=1;
                    }
                    //4번 실행에서 4등 이상이 당첨될 때까지 구매한 티켓의 수를 센다.
                    ctr+=1;
                //4개 미만으로 당첨번호와 뽑은 번호가 같다면 계속 다시뽑는다.
                }while(rightNum<4);

                printf("You bought %d tickets, and the total cost is %d won. ",ctr, 1000*ctr);
                printf("You earned %d won.\n", earnedMoney);
            }
            //'n'을 입력했다면 다시선택하라는 메시지를 띄운다.
            else if(ans == 'n'){printf("Select menu again");}
            //그 외 다른 문자를 입력했다면 오류메시지를 띄운다.
            else {printf("Wrong comment!");}

        }


        else if (num == 0)
        {
            //0이 입력되면 while문을 탈출하고 프로그램을 종료한다.
            printf("Good bye!");
            break;
        }

        //이외에 다른 숫자가 입력되면 오류메시지를 띄운다.
        else
        {printf("Wrong number! Put number among(1,2,3,4,0)");}

    }
    //arr의 메모리를 해제한다.
    free(arr);
    arr = NULL;

    //doubleArr의 메모리를 해제한다.
    for (int i = 0; i < ticketSum; i++){
        free(doubleArr[i]);
    }
    free(doubleArr);
    doubleArr = NULL;
   return 0;
}

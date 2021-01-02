#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//�޴��� ����ϴ� �Լ�.
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



//��ȣ 6���� �ߺ����� �����Ͽ� �� �������迭�� �����ϴ� �Լ�.
int* newTicket(void)
{
    int ctr = 0;
    //��ȣ 6���� �� ������ �迭�� �����Ѵ�.
    int * arr = NULL;
    arr = (int *)malloc(6*sizeof(int));

    //�ߺ����� 6���� ���ڸ� �̴´�.
    for(int i = 0; i<6; i++)
        {
            while(1){
                //1~45������ ���� �� �ϳ��� �̴´�.
                arr[i] = rand()%45 + 1;
                ctr = 0;
                for(int j = 0; j < i; j++){
                    if (arr[i]==arr[j])
                    {
                       //�ߺ��Ǵ°� ������ ctr�� ������Ų��.
                       ctr++;
                    }
                }
                //ctr�� 0�� �ƴ϶�� ���ư� ���ڸ� �ٽ� �޴´�.
                if (ctr!=0){continue;}
                // �ƴ϶�� while������ ���ư���.
                else {break;}
            }
        }

    //�����Ʈ�� ������������ �����Ѵ�.
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


    //���ݱ��� ������ Ƽ�ϵ��� ����� ���� �迭�� �����Ѵ�.
    int** doubleArr = NULL;
    doubleArr = (int**)malloc(1*sizeof(int*));
    doubleArr[0] = (int *)malloc(6*sizeof(int));

    //��÷��ȣ 6���� �� ������ �迭�� �����Ѵ�.
    int * arr = NULL;
    arr = (int *)malloc(6*sizeof(int));

    //���ʽ� ��ȣ 1���� �̴´�.
    bonusNum = rand()%45+1;

    //�ߺ����� �ʰ� ��÷ ��ȣ 6���� �����Ѵ�.
    for(int i = 0; i<6; i++)
        {
            while(1){
                arr[i] = rand()%45 + 1; //��ȣ�� �̴´�.
                t = 0;
                for(int j = 0; j < i; j++){
                    if (arr[i]==arr[j] || arr[i] == bonusNum)
                    {
                       t++; //��÷��ȣ�� ���ʽ���ȣ�� �ߺ��Ǵ°� ������ t�� ������Ų��.
                    }
                }
                if(t!=0){continue;} //t�� 0�� �ƴ϶�� �ǵ��ư��� ���ڸ� �ٽ� �޴´�.
                else{break;}
            }
        }

    //��÷ ��ȣ 6���� �� �迭�� ������������ �����Ѵ�. (�����Ʈ ���)
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

    //���� ������ �ݺ��Ѵ�.
   while (1)
   {
        int num = 0, rightBonus = 0, ticketNum = 0, ctr = 0, rightNum = 0;
        int rank_1 = 0, rank_2 = 0, rank_3 = 0, rank_4 = 0, rank_5 = 0;
        char ans;
        int * a;
        printf("\n");
        //�޴��� ����Ѵ�.
        printMenu();
        //��� �޴��� ������� �Է¹޴´�.
        scanf(" %d", &num);


        if (num == 1)
        {
            n++;
            printf("\nHow many lines will you buy? : ");
            //��� ������ �������� �Է¹޴´�.
            scanf("%d", &ticketNum);
            //��ü Ƽ���� ������ ����Ѵ�.
            ticketSum += ticketNum;


            //ù��° ���ٸ� malloc���� ���ź��Ǹ���� ũ�⸦ �����Ѵ�.
            if(n == 1){
                for(int i = 0; i < ticketNum; i++){
                    doubleArr[i] = (int*)malloc(6*sizeof(int));
                }
            }
            //�ι�° ���ĺ��ʹ� realloc���� ������ Ȯ���ϰ� �߰��� �����ȿ� 6¥�� �������迭�� �����.
            else {
                doubleArr = (int**)realloc(doubleArr, ticketSum*sizeof(int*));
                for(int i = ticketSum-ticketNum; i < ticketSum; i++ ){
                    doubleArr[i] = (int*)malloc(6*sizeof(int));}
            }
            // newTicket�Լ��� ���ǹ�ȣ�� ��Ͽ� �߰��Ѵ�.
            for(int i = ticketSum-ticketNum; i < ticketSum ; i++){
                doubleArr[i] = newTicket();
            }
            // 1������ ���� ���� ����� ����Ѵ�.
            for(int i = ticketSum-ticketNum; i < ticketSum; i++){
                for(int j = 0; j < 6; j++){
                    printf("%3d", doubleArr[i][j]);
                }
                printf("\n");
            }
            // 1������ ���� ������ �˻��Ͽ� ��÷�� ������ �ִ� ��� rank_n�� rankn ������ 1�� ������Ų��.
            for(int i = ticketSum-ticketNum; i < ticketSum; i++){
                rightBonus = 0;
                rightNum = 0;
                for(int j = 0; j<6; j++){
                        //���ʽ� ��ȣ�� ���� ��ȣ�� �ִٸ� rightBonus�� 1�� �Ѵ�.
                        if (doubleArr[i][j] == bonusNum){
                            rightBonus = 1;
                        }
                }
                //��÷��ȣ�� ������ Ƽ���� ��ȣ�� ��ġ�ϴ� �� �ִٸ� rightNum�� 1�� ������Ų��.
                for(int k = 0; k < 6; k++){
                        if(doubleArr[i][k] == arr[k]){
                            rightNum += 1;}
                }

                //rightNum�� ������ rightBonus�� ���� �� � ��÷�Ǿ����� ����Ѵ�.
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
            //��÷�� ������ ����Ѵ�.
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

            // �Է�Ȯ���� �Ѵ�.
            printf("\nAre you sure? (y or n)");
            scanf(" %c", &ans);

            if (ans == 'y')
            {
                do{
                    rightNum = 0;
                    rightBonus = 0;
                    // ���ݱ��� ������ Ƽ���� ���� ����.
                    ticketSum+=1;
                    int * a = NULL;
                    //������ �迭�� �ϳ� ����� 6���� ���ڸ� �����Ѵ�.
                    a = (int *)malloc(6*sizeof(int));
                    a = newTicket();


                    //doubleArr�� ������ Ȯ���ϰ� ���� ���� ������ ��Ͽ� �߰��Ѵ�.
                    doubleArr = (int**)realloc(doubleArr, ticketSum*sizeof(int*));
                    doubleArr[ticketSum - 1] = (int*)malloc(6*sizeof(int));
                    doubleArr[ticketSum - 1] = a;



                    for(int i = 0; i<6; i++){

                        //���ʽ� ��ȣ�� ���� ��ȣ�� �ִٸ� rightBonus�� 1�� �Ѵ�.
                        if (a[i] == bonusNum){
                            rightBonus = 1;
                        }
                        //��÷��ȣ�� ������ Ƽ���� ��ȣ�� ��ġ�ϴ� �� �ִٸ� rightNum�� 1�� ������Ų��.
                        for(int j = 0; j < 6; j++){
                            if(a[i] == arr[j]){
                                rightNum += 1;
                            }
                        }
                    }
                    //rightNum�� ������ rightBonus�� ���� ��÷������ ����ϰ� 4������ ������ ���� ����Ѵ�.
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
                    //4�� ���࿡�� 4�� �̻��� ��÷�� ������ ������ Ƽ���� ���� ����.
                    ctr+=1;
                //4�� �̸����� ��÷��ȣ�� ���� ��ȣ�� ���ٸ� ��� �ٽû̴´�.
                }while(rightNum<4);

                printf("You bought %d tickets, and the total cost is %d won. ",ctr, 1000*ctr);
                printf("You earned %d won.\n", earnedMoney);
            }
            //'n'�� �Է��ߴٸ� �ٽü����϶�� �޽����� ����.
            else if(ans == 'n'){printf("Select menu again");}
            //�� �� �ٸ� ���ڸ� �Է��ߴٸ� �����޽����� ����.
            else {printf("Wrong comment!");}

        }


        else if (num == 0)
        {
            //0�� �ԷµǸ� while���� Ż���ϰ� ���α׷��� �����Ѵ�.
            printf("Good bye!");
            break;
        }

        //�̿ܿ� �ٸ� ���ڰ� �ԷµǸ� �����޽����� ����.
        else
        {printf("Wrong number! Put number among(1,2,3,4,0)");}

    }
    //arr�� �޸𸮸� �����Ѵ�.
    free(arr);
    arr = NULL;

    //doubleArr�� �޸𸮸� �����Ѵ�.
    for (int i = 0; i < ticketSum; i++){
        free(doubleArr[i]);
    }
    free(doubleArr);
    doubleArr = NULL;
   return 0;
}

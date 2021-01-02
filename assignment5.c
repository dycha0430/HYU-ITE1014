#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//90�� �ð�������� ȸ����Ų �������迭�� �����ϴ� �Լ�
int** rotate(int** mat)
{
    //��� ���� ������ �ް� �� ������ ���� �ٲ۴�.
    int temp = 0;
    int rowSize = _msize(mat)/sizeof(mat[0]);
    int colSize = _msize(*mat)/sizeof(*mat[0]);

    temp = rowSize;
    rowSize = colSize;
    colSize = temp;

    //ȸ���� ũ�⿡ �´� ������ �迭 ����.
    int ** mat2 = NULL;
    mat2 = (int **)malloc(rowSize * sizeof(int *));
    for(int i = 0; i < rowSize; i++){
        mat2[i] = (int *)malloc(colSize * sizeof(int));
    }

    //mat2�� 90�� ȸ����Ų ���� ����.
    for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            mat2[i][j] = mat[colSize-1-j][i];
        }
    }


    //mat�� �޸𸮴� ������Ŵ.
    for (int i = 0; i<colSize; i++){
        free(mat[i]);
    }
    free(mat);
    mat = NULL;

    //mat2�� mat�� �ٲ۴�.
    mat = (int **)malloc(rowSize * sizeof(int*));
    for(int i = 0; i < rowSize; i++){
        mat[i] = (int *)malloc(colSize * sizeof(int));
    }

    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            mat[i][j] = mat2[i][j];
        }
    }

    //mat2�� �޸𸮸� ������Ŵ.
    for (int i = 0; i<rowSize; i++){
        free(mat2[i]);
    }
    free(mat2);
    mat2 = NULL;

    //90�� ȸ���� �迭�� ������.
    return mat;
}


int main(void)
{
    //�迭�� ������.
    int** mat = NULL;
    int rowSize = 0, colSize = 0;
    int ctr = 0;
    //��� ���� ������ �Է¹޴´�.
    printf("Input row size of the matrix : ");
    scanf("%d", &rowSize);
    printf("Input column size of the matrix : ");
    scanf("%d", &colSize);

    //������ �迭�� �����Ҵ��Ѵ�.
    mat = (int **)malloc(rowSize * sizeof(int *));
    for(int i = 0; i < rowSize; i++){
        mat[i] = (int *)malloc(colSize * sizeof(int));
    }

    //������ �迭�� 1���� 1�� �÷� ������ ���ڸ� ä���.
    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
                ctr++;
            mat[i][j] = ctr;
        }
    }


    printf("< degree : 0 >\n");

    //�迭�� ����Ѵ�.
    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }



    printf("< degree : 90 >\n");
    //rotate�Լ��� ȣ���Ѵ�. -> �迭�� 90�� ȸ����Ŵ.
    rotate(mat);
    //�迭�� ����Ѵ�.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    printf("< degree : 180 >\n");
    //rotate�Լ��� ȣ���Ѵ�.
    rotate(mat);
    //�迭�� ����Ѵ�.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    printf("< degree : 270 >\n");
    //rotate�Լ��� ȣ���Ѵ�.
    rotate(mat);
    //�迭�� ����Ѵ�.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    //�迭�� �޸𸮸� �����Ѵ�.
    for (int i = 0; i<rowSize; i++){
        free(mat[i]);
    }
    free(mat);
    mat = NULL;


    return 0;
}

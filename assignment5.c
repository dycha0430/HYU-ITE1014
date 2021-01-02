#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//90도 시계방향으로 회전시킨 이차원배열을 리턴하는 함수
int** rotate(int** mat)
{
    //행과 열의 개수를 받고 그 개수를 서로 바꾼다.
    int temp = 0;
    int rowSize = _msize(mat)/sizeof(mat[0]);
    int colSize = _msize(*mat)/sizeof(*mat[0]);

    temp = rowSize;
    rowSize = colSize;
    colSize = temp;

    //회전한 크기에 맞는 이차원 배열 생성.
    int ** mat2 = NULL;
    mat2 = (int **)malloc(rowSize * sizeof(int *));
    for(int i = 0; i < rowSize; i++){
        mat2[i] = (int *)malloc(colSize * sizeof(int));
    }

    //mat2에 90도 회전시킨 값을 담음.
    for(int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            mat2[i][j] = mat[colSize-1-j][i];
        }
    }


    //mat의 메모리는 해제시킴.
    for (int i = 0; i<colSize; i++){
        free(mat[i]);
    }
    free(mat);
    mat = NULL;

    //mat2를 mat로 바꾼다.
    mat = (int **)malloc(rowSize * sizeof(int*));
    for(int i = 0; i < rowSize; i++){
        mat[i] = (int *)malloc(colSize * sizeof(int));
    }

    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            mat[i][j] = mat2[i][j];
        }
    }

    //mat2의 메모리를 해제시킴.
    for (int i = 0; i<rowSize; i++){
        free(mat2[i]);
    }
    free(mat2);
    mat2 = NULL;

    //90도 회전한 배열을 리턴함.
    return mat;
}


int main(void)
{
    //배열을 생성함.
    int** mat = NULL;
    int rowSize = 0, colSize = 0;
    int ctr = 0;
    //행과 열을 개수를 입력받는다.
    printf("Input row size of the matrix : ");
    scanf("%d", &rowSize);
    printf("Input column size of the matrix : ");
    scanf("%d", &colSize);

    //이차원 배열을 동적할당한다.
    mat = (int **)malloc(rowSize * sizeof(int *));
    for(int i = 0; i < rowSize; i++){
        mat[i] = (int *)malloc(colSize * sizeof(int));
    }

    //이차원 배열에 1부터 1씩 늘려 나가며 숫자를 채운다.
    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
                ctr++;
            mat[i][j] = ctr;
        }
    }


    printf("< degree : 0 >\n");

    //배열을 출력한다.
    for (int i = 0; i<rowSize; i++){
        for(int j = 0; j<colSize; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }



    printf("< degree : 90 >\n");
    //rotate함수를 호출한다. -> 배열을 90도 회전시킴.
    rotate(mat);
    //배열을 출력한다.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    printf("< degree : 180 >\n");
    //rotate함수를 호출한다.
    rotate(mat);
    //배열을 출력한다.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    printf("< degree : 270 >\n");
    //rotate함수를 호출한다.
    rotate(mat);
    //배열을 출력한다.
    for (int i = 0; i<_msize(mat)/sizeof(mat[0]); i++){
        for(int j = 0; j<_msize(*mat)/sizeof(*mat[0]); j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    //배열의 메모리를 정리한다.
    for (int i = 0; i<rowSize; i++){
        free(mat[i]);
    }
    free(mat);
    mat = NULL;


    return 0;
}

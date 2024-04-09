#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5
#define M 7

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int **mt;
    mt = (int**)malloc(N * sizeof(int*));
    for (int i=0;i<N;i++){
        mt[i] = (int *) malloc (M * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            mt[i][j]=1+rand()%100;
            printf(" %d ", mt[i][j]);
        }
        printf("\n");

    }
    

    return 0;
}
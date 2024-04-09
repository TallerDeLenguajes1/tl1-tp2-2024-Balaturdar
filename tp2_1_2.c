#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20

int main(int argc, char const *argv[])
{
    int i;
    double *vt;
    vt =(double*) malloc(sizeof(double) * N);

    srand(time(NULL));

    for(i = 0;i<N; i++){
        *(vt+i) = 1+rand()%100;
        printf("%f \n", *(vt+i));
    }

    return 0;
}
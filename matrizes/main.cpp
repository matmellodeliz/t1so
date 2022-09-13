#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3
#define n 3

struct v
{
    size_t i;
    size_t j;
};

double A[N][N];
double B[N][N];
double C[N][N];

static void * multiplication(void *arg){
    struct v *data = (struct v *)arg;

    size_t l;
    for(l=0; l < N; l++)
    {
        size_t i=(data[l]).i;
        size_t j=(data[l]).j;
        double sum=0;
        size_t d;

        for (d = 0; d < N; d++)
        {
            sum = sum + A[i][d]*B[d][j];
        }

        C[i][j] = sum;
        sum = 0;
    }
    return 0;
}

int main(void)
{
    srand(time(NULL));
    int a, b;
    printf("Matriz A:\n");
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            A[a][b] = rand() % 9 + 1;
            printf("%lf\t", A[a][b]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");
    printf("Matriz B:\n");
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            B[a][b] = rand() % 9 + 1;
            printf("%lf\t", B[a][b]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");
    pthread_t threads[n];
    size_t i, k;

    struct v **data;
    data = (struct v **)malloc(n * sizeof(struct v*));

    for(i = 0; i < n; i++)
    {
        data[i] = (struct v *)malloc(n * sizeof(struct v));

        for(k = 0; k < n; k++)
        {
            data[i][k].i = i;
            data[i][k].j = k;
        }

        pthread_create(&threads[i], NULL, multiplication, data[i]);
    }

    for(i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Matriz Final C:\n");
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < N; k++)
        {
            printf("%lf\t", C[i][k]);
        }

        printf("\n");

        free(data[i]);
    }

    free(data);

    return 0;
}

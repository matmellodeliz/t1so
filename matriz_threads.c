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
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            A[a][b] = rand() % 9 + 1;
            printf("%lf\t", A[a][b]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");
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



/**<
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM 4

void preenche(int mat1[][TAM], int mat2[][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            mat1[i][j] = rand() % 9 + 1;
            mat2[i][j] = rand() % 9 + 1;
        }
    }
}

void processa(int mat1[][TAM], int mat2[][TAM], int mat3[][TAM]) {
    int i, j;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mat3[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

void imprime(int mat1[][TAM], int mat2[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
}

void imprime_resultado(int mat3[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }
}

int main() {
    system("CLS");
    srand(time(NULL));  // Reseta a 'semente' da aleatoridade, fazendo que novos números aleatórios sejam escolhidos
    int mat1[TAM][TAM], mat2[TAM][TAM], mat3[TAM][TAM];

    preenche(mat1, mat2);
    imprime(mat1, mat2);
    processa(mat1, mat2, mat3);
    printf("\n");
    imprime_resultado(mat3);

    return 0;
}
 */

// #include <locale.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>

// #define TAM 5

// void preenche(int mat[][TAM]) {
//     int i, j;
//     printf("Digite os elementos da primeira matriz\n");
//     for (i = 0; i < linha; i++) {
//         for (j = 0; j < coluna; j++) {
//             scanf("%d", mat[i][j]);
//         }
//     }
// }

// int imprime() {
//     int i, j, linha, coluna, mul[linha][coluna];
//     for (int i = 0; i < linha; i++) {
//         for (int j = 0; j < coluna; j++) {
//             printf("%d\t", mul[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     setlocale(LC_ALL, "Portuguese");
//     int a[TAM][TAM], b[TAM][TAM], mul[TAM][TAM], linha, coluna, i, j, k;

//     printf("Digite o número de linhas: ");
//     scanf("%d", &linha);
//     printf("Digite o número de colunas: ");
//     scanf("%d", &coluna);

//     printf("Digite os elementos da segunda matriz\n");
//     for (i = 0; i < linha; i++) {
//         for (j = 0; j < coluna; j++) {
//             scanf("%d", &b[i][j]);
//         }
//     }

//     // Realiza a multiplicação
//     printf("Matriz final da multiplicação: \n");
//     for (i = 0; i < linha; i++) {
//         for (j = 0; j < coluna; j++) {
//             mul[i][j] = 0;
//             for (k = 0; k < coluna; k++) {
//                 mul[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }
//     imprime();
//     return 0;
// }

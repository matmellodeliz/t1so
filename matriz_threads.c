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

int main() {
    system("CLS");
    srand(time(NULL));  // Reseta a 'semente' da aleatoridade, fazendo que novos números aleatórios sejam escolhidos
    int mat1[TAM][TAM], mat2[TAM][TAM];

    preenche(mat1, mat2);
    imprime(mat1, mat2);
    return 0;
}

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
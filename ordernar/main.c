#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
 #define TAM 10

int a[TAM], swapped = 0;
pthread_t thread[TAM];

void criarVetor() {
	srand(time(NULL));
	int i;
	for(i = 0; i < TAM; i++)
		a[i] = rand() % TAM;

	printf("Vetor Original\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void bubble(int i) {
	int tmp, mod;

	mod = i % 2;

	if (i != TAM-1) {
		if(a[i] > a[i+1]) {
			tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
			swapped = 1;
		}
	}
}

int main() {
	int i;
	criarVetor();


	do {

		swapped = 0;

		for(i = 0; i < TAM; i+=2)
			pthread_create(&thread[i], NULL, &bubble, i);
		for(i = 0; i < TAM; i+=2)
			pthread_join(thread[i], NULL);

		swapped = 0;

		for(i = 1; i < TAM; i+=2)
			pthread_create(&thread[i], NULL, &bubble, i);
		for(i = 1; i < TAM; i+=2)
			pthread_join(thread[i], NULL);


	} while(swapped == 1);

	printf("Vetor Ordenado\n");
	for(i = 0; i < TAM; i++)
		printf("%d ", a[i]);
	printf("\n");

	exit(0);
}

#define LINHA
#define COLUNA

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main()
{
	int **matriz1;
	int **matriz2;
	int linha, coluna;
	
	printf("Digite a quantidade de linhas das matrizes: ");
	scanf("%d", &linha);
	printf("Digite a quantidade de colunas das matrizes: ");
	scanf("%d", &coluna);
	
	//matriz 1
	matriz1 = (int**)malloc(linha*sizeof(int*));//alocacao das linhas da matriz
	for(int i = 0; i < linha; i++)
	{
		matriz1[i] = (int*)malloc(coluna*sizeof(int));//alocacao das colunas de cada linha
	}
	
	//matriz2
	matriz2 = (int**)malloc(linha*sizeof(int*));
	for(int i = 0; i < linha; i++)
	{
		matriz2[i] = (int*)malloc(coluna*sizeof(int));
	}
	
	//preenche ambas matrizes com numeros aleatorios de 0-99
	srand(time(NULL));
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			matriz1[j][i] = rand()%100;
			matriz2[j][i] = rand()%100;
		}
	}
	
	//imprime na tela as matrizes 1 e 2 e a soma das mesmas
	printf("\n");
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			printf("%i ", matriz1[j][i]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			printf("%i ", matriz2[j][i]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			printf("%i ", matriz1[j][i]+matriz2[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
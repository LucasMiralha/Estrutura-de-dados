#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main()
{
	int *ptr;
	int tam;
	int num;
	
	printf("Digite o tamanho do array: ");
	scanf("%d", &tam);
	printf("\n");
	
	ptr = (int*)malloc(tam*sizeof(int));//alocacao do espaco exato do tamanho do array
	
	srand(time(NULL));
	
	for(int i = 0; i < tam; i++, ptr++)//laco para preencher a matriz com numeros aleatorios
	{
		num = rand()%100;//definindo um numero aleatorio de 0-99
		*ptr = num;//preenchendo o array com os numeros aleatorios
		printf("%d\n", num);//imprimindo o array
	}
		
	return 0;
}
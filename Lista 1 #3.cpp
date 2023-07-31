#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int media(int array[], int tam)//funcao para calcular a media
{
	int media;
	
	for(int i = 0; i < tam; i++)
	{
		media += array[i];//calculo da media, somando todos os termos do array 
	}
	media = media/tam;//calculo da media, dividindo o numero total pelo numero de elementos
	
	return media;
}

int main()
{
	int array[50] = { };//array de tamanho qualquer preenchido com 0
	int *ptr = array;
	int size = (sizeof(array)/sizeof(int));//definindo o tamanho do array para poder existir livre alteracao do tamanhon do array
	
	ptr = (int*)malloc(size*sizeof(int));//alocacao exata do tamanho do array

	srand(time(NULL));
	for(int i = 0; i < size; i++)
	{
		array[i] = rand()%100;//preenchendo o array com numeros aleatorios de 0-99
		printf("%i\n", array[i]);//imprimindo o array para depois poder ser feita uma verificacao de funcionamento da funcao
	}
	
	printf("Media dos valores: %d", media(array, size));//chamada e impressao da funcao media
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int *primo(int num, int *size)//funcao teste
{
	int *primos;
	bool teste;
	int qnt = 0;
	int i, j;
	
	primos = (int*)malloc(num*sizeof(int));//alocando o espaco exato do array
	
	for(i = 2; i <= num; i++)
	{
		teste = true;//considera-se o numero primo ate que o teste prove o contrario
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				teste = false;
			}
		}//os dois lacos foram usasdos para varrer todos os numeros de 2 ate o numero digitado
		if(teste == true)
		{
			primos[qnt] = i;//numero primo adicionado ao array
			qnt++;//quantidade de numeros primos, o tamanho do array final
		}
	}
	
	*size = qnt;//devolvendo o valor do tamanho da lista para o main
	primos = (int*)realloc(primos, qnt*sizeof(int));//realocando a memoria para utilizar somente o necessario
		
	return primos;//retorno do array com o tamanho especifico
}

int main()
{
	int *arr;
	int num;
	int size;
	
	printf("Digite qualquer numero inteiro maior que 0: ");
	scanf("%i", &num);
	
	if(num <= 0)//se o numero for igual ou menor que 1 ele e automaticamente rejeitado, ja que 1 nao e primo
	{
		printf("\nNumero invalido!");
	}
	else
	{	
		arr = primo(num, &size);//uma array copia o resultado da funcao para facilitar a impressao
		
		printf("Lista: \n\n");//impressao da lista
		for(int i = 0; i < size; i++)
		{
			printf("%i\n", arr[i]);
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	int *ptr;
	
	ptr = (int *)calloc(10, sizeof(int));//alocando 10 espacos igualados a 0 na memoria
	
	for(int i = 0; i < 11; i++, ptr++) //Selecionei o numero 11 para demonstrar como somente os 10 espacos de memorias estao vazios
	{
		printf("%d\n", *ptr);
	}
	
	return 0;
}
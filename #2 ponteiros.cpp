#include <stdio.h>

int main()
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *ptr = arr;
	int i;
	
	for(i = 0; i < 5; i++, ptr++)
	{
		printf("Valor armazenado no elemento %d: %d\n", i, *ptr);
	}
	
	return 0;
}
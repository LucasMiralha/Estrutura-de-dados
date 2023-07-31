#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct cliente
{
	int codigo;
	int data;
	float valor;
	string nome;
	string produto;
};

int shellSort(cliente arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            cliente temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap].codigo > temp.codigo; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

int partition(cliente arr[], int low, int high)
{
    // Choosing the pivot
    cliente pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j].valor > pivot.valor) {
 
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(cliente arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printCliente(cliente cltns[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Cliente: " << cltns[i].nome << endl;
		cout << "Codigo : " << cltns[i].codigo << endl;
		cout << "Produto: " << cltns[i].produto << endl;
		cout << "Valor  : " << cltns[i].valor << endl;
		cout << "Data   : " << cltns[i].data << endl;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n = 100;
	cliente cltns[n];
	
	int esc, cont, list;
	
	while(esc != 2)
	{
		if(cont == n)
		{
			cout << "Numero maximo de clientes atingido." << endl;
			break;
		}
		cout << "Digite as informacoes do cliente:" << endl;
		
		cout << "Cliente - ";
		cin >> cltns[cont].nome;
		cout << "Codigo - ";
		cin >> cltns[cont].codigo;
		cout << "Produto - ";
		cin >> cltns[cont].produto;
		cout << "Valor - ";
		cin >> cltns[cont].valor;
		cout << "Data - ";
		cin >> cltns[cont].data;
		
		cout << "Deseja inserir outro cliente?" << endl;
		cout << "1 - sim\t2 - nao" << endl;
		cin >> esc;
		cont++;
	}
	
	cout << endl;
	
	esc = 0;
	while(esc != 1)
	{
		cout << "Iniciando processos de ordenacao" << endl;
		cout << "Qual lista voce deseja conferir?" << endl;
		cout << "1 - codigo\t2 - valor" << endl;
		cin >> list;
		if(list < 1 || list > 2)
		{
			esc = 0;
		}
		else
		{
			esc = 1;
		}
	}
	
	if(list == 1)
	{
		cout << "Ordenando o codigo de forma crescente:" << endl;
		shellSort(cltns, cont);
		printCliente(cltns, cont);
	}
	
	if(list == 2)
	{
		cout << "Ordenando o valor de forma decrescente:" << endl;
		quickSort(cltns, 0, cont-1);
		printCliente(cltns, cont);
	}
	
	return 0;
}
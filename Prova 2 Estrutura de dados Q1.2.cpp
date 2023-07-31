#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct produto
{
	int codigo;
	string nome;
	float custo;
	float venda;
	float lucro;
};

void insertionSort(produto arr[], int n)
{
    int i, j;
    produto key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].lucro > key.lucro)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(produto *xp, produto *yp)
{
	produto temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(produto arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
		if (arr[j].codigo > arr[min_idx].codigo)
			min_idx = j;
		}
		if (min_idx!=i)
			swap(&arr[min_idx], &arr[i]);
	}
}

void printProduto(produto prdts[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Nome   : " << prdts[i].nome << endl;
		cout << "Codigo : " << prdts[i].codigo << endl;
		cout << "Custo  : " << prdts[i].custo << endl;
		cout << "Venda  : " << prdts[i].venda << endl;
		cout << "Lucro  : " << prdts[i].lucro << endl;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n = 100;
	produto prdts[n];
	
	int esc, cont;
	
	while(esc != 2)
	{
		if(cont == n)
		{
			cout << "Numero maximo de produtos atingido." << endl;
			break;
		}
		cout << "Digite as informacoes do produto:" << endl;
		cout << "Nome - ";
		cin >> prdts[cont].nome;
		cout << "Codigo - ";
		cin >> prdts[cont].codigo;
		cout << "Valor de venda - ";
		cin >> prdts[cont].venda;
		cout << "Valor de compra - ";
		cin >> prdts[cont].custo;
		
		prdts[cont].lucro = prdts[cont].venda - prdts[cont].custo;
		
		cout << "Deseja inserir outro produto?" << endl;
		cout << "1 - sim\t2 - nao" << endl;
		cin >> esc;
		cont++;
	}
	
	cout << endl;
	
	cout << "Iniciando processos de ordenacao" << endl;
	cout << "Ordenando o lucro de forma crescente:" << endl;
	insertionSort(prdts, cont);
	printProduto(prdts, cont);
	cout << "Ordenando o codigo de forma decrescente:" << endl;
	selectionSort(prdts, cont);
	printProduto(prdts, cont);
	
	return 0;
}
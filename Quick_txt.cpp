#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int partition(float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
	{
        if (arr[j] < pivot)
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(float arr[], int low, int high)
{
    if (low < high)
	{
        float pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(float arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<float> dados;
	ifstream nums;
	nums.open("numeros.txt", ios::in);
	
	float x;
	while (1) 
	{         
        nums >> x;              
        if(nums.eof())  
		{        
            break;                                
	    }
	    dados.push_back(x);
	}
	
	int n = dados.size();
	float arr[n];
    for (int i = 0; i < n; i++) 
	{
        arr[i] = dados[i];
    }
	quickSort(arr, 0, n-1);
	cout << "Sorted array: " << endl;
	cout << endl;
	printArray(arr, n);
	cout << endl;
	return 0;    
}
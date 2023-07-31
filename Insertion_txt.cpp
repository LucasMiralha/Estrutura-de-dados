#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void insertionSort(float arr[], int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
	nums.open("numeros2.txt", ios::in);
	
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
	insertionSort(arr, n);
	cout << "Sorted array: " << endl;
	cout << endl;
	printArray(arr, n);
	cout << endl;
	return 0;    
}


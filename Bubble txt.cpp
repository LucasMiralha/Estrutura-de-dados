#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void bubbleSort(float arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
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
	nums.open("numeros3.txt", ios::in);
	
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
	bubbleSort(arr, n);
	cout << "Sorted array: " << endl;
	cout << endl;
	printArray(arr, n);
	cout << endl;
	return 0;    
}

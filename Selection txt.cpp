#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


void swap(float *xp, float *yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(float arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
		if (arr[j] < arr[min_idx])
			min_idx = j;
		}
		if (min_idx!=i)
			swap(&arr[min_idx], &arr[i]);
	}
}

void printArray(float arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
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
	selectionSort(arr, n);
	cout << "Sorted array: " << endl;
	cout << endl;
	printArray(arr, n);
	cout << endl;
	return 0; 
}
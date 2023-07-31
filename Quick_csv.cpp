#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
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

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
	{
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
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
	vector<int> dados;
	ifstream nums;
	nums.open("numeros2.csv", ios::in);
	
	string line, val;                  	
	
    while (getline(nums, line)) 
	{        								
        stringstream s (line);         
        while (getline(s, val, ','))       
        dados.push_back (stoi(val));  
    }
    int n = dados.size();
	int arr[n];
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
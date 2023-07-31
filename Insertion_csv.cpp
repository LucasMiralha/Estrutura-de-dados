#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
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
	insertionSort(arr, n);
	cout << "Sorted array: " << endl;
	cout << endl;
	printArray(arr, n);
	cout << endl;
	return 0;    
}


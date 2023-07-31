#include <bits/stdc++.h>

using namespace std;

int main()
{
	int index;
	
	while(1)
	{
		system("cls");
		while(!(cin >> index) || index > 2 || index < 1)
		{
			cout << "Comando invalido, tente de novo: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
		system("pause");
	}

}
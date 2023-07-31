#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//estrutura de dados principal do projeto
struct produto
{
	string nome;
	string desc;
	float preco;
	int quantidade;
};	

int main() {

	vector<produto> prdts;
	produto temppp;
    string line, preco, quantidade;
    int counter = 0;
    ifstream file;

    file.open("Isaacmarket.csv");

    if( !file.is_open()) 
	{
        cout << "File not found." << endl;
        exit(-1);
    }
	for (produto temppp;
      std::getline(file, temppp.nome, ';')
      && std::getline(file, temppp.desc, ';')
      && std::getline(file, preco, ';')
      && std::getline(file, quantidade); )
	{
		temppp.preco = stof(preco);
		temppp.quantidade = stoi(quantidade);
    	prdts.push_back(temppp);
	}
	
	int i;
    for (i = 0; i < prdts.size(); i++)
	{
		cout << i + 1;
		cout << "-----------" << endl;
		cout << "Preco     : " << prdts[i].preco << endl;
		cout << "Nome      : " << prdts[i].nome << endl;
		cout << "Descricao : " << prdts[i].desc << endl;
		cout << "Quantidade: " << prdts[i].quantidade << endl;
		cout << endl;
	}

    file.close();
}
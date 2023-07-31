#include <iostream>
#include <ctime>

using namespace std;

struct Aluno
{
	int nome;
	int nota1[4];
	int nota2[4];
	int nota3[4];
	int nota4[4];
	int media;
};

int main()
{
	Aluno alunos[5];
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < 5; i++)
	{
		alunos[i].nome = i + 1;
		alunos[i].media = 0;
		for(j = 0; j < 4; j++)
		{
			alunos[i].nota1[j] = (rand()%10) + 1;
			alunos[i].nota2[j] = (rand()%10) + 1;
			alunos[i].nota3[j] = (rand()%10) + 1;
			alunos[i].nota4[j] = (rand()%10) + 1;
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
		{
			cout << alunos[i].nota1[j] << " ";
			cout << alunos[i].nota2[j] << " ";
			cout << alunos[i].nota3[j] << " ";
			cout << alunos[i].nota4[j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
		{
			alunos[i].media += ((alunos[i].nota1[j] + alunos[i].nota2[j] + alunos[i].nota3[j] + alunos[i].nota4[j])/4);
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		if(alunos[i].media >= 28)
		{
			cout << "Aluno " << alunos[i].nome << " Aprovado!" << endl;
		}
		else
		{
			cout << "Aluno " << alunos[i].nome << " Reprovado!" << endl;
		}
	}
	
	return 0;
}
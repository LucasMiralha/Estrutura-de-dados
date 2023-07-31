#include <iostream>
#include <ctime>

using namespace std;

struct Aluno
{
	int nota1;
	int nota2;
	int nota3;
	int nota4;
	int nome;
	bool aprovado;	
};

int main()
{
	Aluno alunos[5];
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < 5; i++)
	{
		alunos[i].nome = i + 1;
		alunos[i].nota1 = (rand()%10) + 1;
		alunos[i].nota2 = (rand()%10) + 1;
		alunos[i].nota3 = (rand()%10) + 1;
		alunos[i].nota4 = (rand()%10) + 1;
	}
	
	for(i = 0; i < 5; i++)
	{
		cout << alunos[i].nota1 << " " << alunos[i].nota2 << " " << alunos[i].nota3 << " " << alunos[i].nota4 << endl;
	}
	
	cout << endl;
	
	for(i = 0; i < 5; i++)
	{
		if(((alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3 + alunos[i].nota4)/4) >= 7)
		{
			alunos[i].aprovado = true;
		}
		else
		{
			alunos[i].aprovado = false;
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		if(alunos[i].aprovado == true)
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
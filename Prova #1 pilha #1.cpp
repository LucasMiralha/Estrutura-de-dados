#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;           // índice do topo da pilha
    int data[MAX_SIZE];// elementos da pilha
} Stack;

// função para criar uma nova pilha
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// função para verificar se a pilha está cheia
int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// função para inserir um elemento na pilha
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Pilha lotada\n");
    } else {
        stack->data[++stack->top] = element;
    }
}

// função para remover um elemento da pilha
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha cheia\n");
        return -1;
    } else {
        return stack->data[stack->top--];
    }
}

// função para obter o elemento do topo da pilha
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

bool pilha_crescente(Stack* pilha)//Questao de pilha 2, sobre pilha crescente
{
	int cont, i;
	
	for(i = 0; i < pilha->top; i++)
	{
		if(pilha->data[pilha->top - i] > pilha->data[(pilha->top - i) - 1])
		{
			cont++;
		}
	}
	if(cont == i)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    
    if(pilha_crescente(stack) == true)
    {
    	printf("True\n");
	}
	else 
	{
		printf("False\n");
	}

    return 0;
}
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

Stack* inverseStack(Stack *stack)//funcao que retorna o inverso de uma pilha que ela recebe como parametro
{
	Stack *inverse = createStack();//cria uma pilha para a inversao

	if (isEmpty(stack))
	{
		stack->top = -1;
    	return stack;	
	}
	else
	{
		int tam = stack->top;
		inverse->top = stack->top;
		for(int i = 0; i <= tam; i++)
		{
			inverse->data[i] = stack->data[tam-i];//o ultimo elemento da pilha parametro vira o primeiro da pilha invertida
		}
		return inverse;
	}
}

int main() {
    Stack* stack = createStack();
	Stack* inverso;
	Stack* pilha = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

	inverso = inverseStack(stack);//pode-se igualar outra pilha como inversa de outra

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", peek(stack));
	
	printf("\n");
	
	printf("%d\n", pop(inverso));
    printf("%d\n", pop(inverso));
    printf("%d\n", pop(inverso));
    printf("%d\n", pop(inverso));
    printf("%d\n", peek(inverso));
    
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    
    pilha = inverseStack(pilha);//pode-se inverter a pilha sem necessidade de outra pilha
    
    printf("\n");
	
	printf("%d\n", pop(pilha));
    printf("%d\n", pop(pilha));
    printf("%d\n", pop(pilha));
    printf("%d\n", pop(pilha));
    printf("%d\n", peek(pilha));
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;          // índice da frente da fila
    int rear;           // índice do final da fila
    int data[MAX_SIZE]; // elementos da fila
} Queue;

// função para criar uma nova fila
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// função para verificar se a fila está cheia
int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// função para inserir um elemento na fila
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->data[queue->rear] = element;
    }
}

// função para remover um elemento da fila
int dequeue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    } else {
        element = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
    return element;
}

// função para obter o elemento da frente da fila
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->data[queue->front];
    }
}

void printQueue(Queue* queue)
{
	int tam = queue->rear;
	for(int i = 0; i <= tam; i++)
	{
		printf("%d\n", queue->data[i]);
	}
}

Queue* fila_intercalada(Queue* fila1, Queue* fila2)
{
	Queue* intercalada = createQueue();
	
	int tam = fila1->rear;
	 
	for(int i = 0; i <= tam; i++)
	{
		enqueue(intercalada, fila1->data[i]);
		enqueue(intercalada, fila2->data[i]);
	}
	
	return intercalada;
}

int main() {
    Queue* fila1 = createQueue();
	Queue* fila2 = createQueue();
	Queue* fila3;

    enqueue(fila1, 1);
    enqueue(fila2, 2);
    enqueue(fila1, 3);
	enqueue(fila2, 4);
	enqueue(fila1, 5);
	enqueue(fila2, 6);
	enqueue(fila1, 7);
	enqueue(fila2, 8);
	enqueue(fila1, 9);
	enqueue(fila2, 10);
	
	printQueue(fila1);
	printf("\n");
	printQueue(fila2);
	printf("\n");
	
	fila3 = fila_intercalada(fila1, fila2);
	
	printQueue(fila_intercalada(fila1, fila2));
	printf("\n");
	printQueue(fila3);
	printf("\n");
	
    return 0;
	}
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

Queue* imparQueue(Queue* queue)
{
	Queue* impar = createQueue();
	if (isEmpty(queue)) {
        printf("Queue is empty\n");
        queue->front = -1;
        queue->rear = -1;
        return queue;
    } 
	else 
	{
		int tam = queue->rear;
		for(int i = 0; i <= tam; i++)
		{
			if(queue->data[i]%2 == 1)
			{
				enqueue(impar, queue->data[i]);		
			}
		}
        return impar;
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

int main() {
    Queue* queue = createQueue();
	Queue* impar;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	enqueue(queue, 8);
	enqueue(queue, 9);
	enqueue(queue, 10);
	
	printQueue(queue);

	impar = imparQueue(queue);
	
	printf("\n");
	
	printQueue(impar);
	
    return 0;
	}
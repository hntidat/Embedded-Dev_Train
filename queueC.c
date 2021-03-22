#include <stdio.h>
#include <stdlib.h>

unsigned int N;

typedef struct linkedNode {
    int value;
    struct linkedNode* nextNode;
} linkedNode;

typedef struct queue {
    int count;
    linkedNode* front;
    linkedNode* rear;

} queue;

void init(queue* Queue) {
    Queue->count = 0;
    Queue->rear = NULL;
    Queue->front = NULL;
}

void swap(linkedNode* node1, linkedNode* node2) {
    int tempNode = node1->value;
    node1->value = node2->value;
    node2->value = tempNode;
}

int peek(queue const* Queue) { return Queue->front->value; }

int isFull(queue const* Queue) { return (Queue->count >= N); }

int isEmpty(queue const* Queue) { return (Queue->count <= 0); }

void enQueue(queue* Queue, int value) {
    if (isFull(Queue)) {
        printf("Queue is already full.\n");
    } else {
        linkedNode* tempNode = malloc(sizeof(linkedNode));
        tempNode->value = value;
        tempNode->nextNode = NULL;

        if (isEmpty(Queue)) {
            Queue->rear = Queue->front = tempNode;
        } else {
            Queue->rear->nextNode = tempNode;
            Queue->rear = tempNode;
        }
        Queue->count++;
    }
}

int deQueue(queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is empty.\n");
        return -32768;
    }

    int tempInt = Queue->front->value;
    Queue->count--;
    linkedNode* tempNode = Queue->front;
    Queue->front = Queue->front->nextNode;
    free(tempNode);
    return tempInt;
}

void sort(queue* Queue) {
    if (isEmpty(Queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = 1;
        while (i != 0) {
            i = 0;
            for (linkedNode* tempNode = Queue->front; tempNode->nextNode != NULL;
                 tempNode = tempNode->nextNode) {
                if (tempNode->value > tempNode->nextNode->value) {
                    swap(tempNode, tempNode->nextNode);
                    i++;
                }
            }
        }
    }
}

int main() {
    scanf("%u", &N);
    queue *Queue = malloc(sizeof(queue));
    init(Queue);
    for (int i = 0; i < N; i++) {
        enQueue(Queue, rand() % 10 + 1);
    }
    return 0;
}

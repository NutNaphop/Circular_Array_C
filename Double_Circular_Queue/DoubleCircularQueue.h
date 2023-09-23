#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 5 

int items[SIZE]; 
int front = -1, rear = -1;

int enQueueFront(int data); 
int enQueueRear(int data); 
int deQueueFront();
int deQueueRear();  
int showItem();
int isFull();
int isEmpty();
int isInt(char *str);
void clear();
void wait();

int enQueueFront(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue at the front.\n");
        return 0; 
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        front = (front - 1 + SIZE) % SIZE;
    }
    items[front] = data;
    printf("Enqueued %d at the front. Enqueue Front Complete.\n", items[front]);
}

int enQueueRear(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue at the rear.\n");
        return 0; 
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }
    items[rear] = data;
    printf("Enqueued %d at the rear. Enqueue Complete.\n", items[rear]);
}

int deQueueFront() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue from the front.\n");
        return 0; 
    }
    printf("Dequeued item: %d. Dequeue Complete!\n", items[front]);
    if (front == rear) {
        front = -1;
        rear = -1;    
    }
    else {
        front = (front + 1) % SIZE;
    }
}

int deQueueRear() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue from the rear.\n");
        return 0; 
    }
    printf("Dequeued item: %d. Dequeue Complete!\n", items[rear]);
    if (front == rear) {
        front = -1;
        rear = -1;    
    }
    else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

int showItem() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to display.\n");
        return 0; 
    }
    printf("Front -> %d\n", front);
    for (int i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", items[i]);
    }
    printf("%d\nRear -> %d\n", items[rear], rear);
    return 0; 
}

int isFull() {
    if ((rear + 1) % SIZE == front) {
        return 1; 
    }
    return 0; 
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1; 
    }
    return 0; 
}

int isInt(char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0; 
        }
        str++;
    }
    return 1; 
}

void clear() {
    system("cls");
}

void wait() {
    system("pause");
}

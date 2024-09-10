#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    struct Queue *Q;
}*q;

void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x){
    if(q->rear=q->size-1){
        printf("this is overflowing\n");
    }else{
        q->rear ++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x =-1;

    if(q->front == q->rear){
        printf("queue is emty\n");
    }else{
        q->front ++;
        x = q->Q[q->front];
    }
    return x;
}


int main(){

    create(&q, 5);

    return 0;
}
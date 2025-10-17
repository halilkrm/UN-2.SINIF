#include <stdio.h>
#include <stdlib.h>

typedef struct q
{
    int data;
    int priority;
    struct q* next;
}QUEUE;

QUEUE* front = NULL, * last = NULL;

int enqueue(int item, int value) {

    QUEUE* p;

    p = (QUEUE*)malloc(sizeof(QUEUE));


    if (p == NULL) {
        printf("Memory error");
        return -1;
    }

    p->data = item;
    p->priority = value;

    if (front == NULL) {
        front = p;
        last = p;
        p->next = NULL;
            
    }
    else {
        QUEUE* current = front, * previous = NULL;

        while (current->priority <= p->priority)
        {
            previous = current;
            current = current->next;
        }

        

        if (current == NULL) {
            last = p;
        }
        else if (previous == NULL) {
            p->next = front;
            front = p;
        }
        else {
            previous->next = p;
            p->next = current;
        }
            
    }
    return 1;
}

int dequeue() {
    QUEUE* p;
    int data;

    if (front == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    p = front;
    front = front->next;
    if (front == NULL)
        last = NULL;

    data = p->data;
    free(p);
    return data;
}

void reset() {
    QUEUE* p;
    p = front;
    while (front !=NULL)
    {
        p = front;
        front = front->next;
        free(p);
    }
}

int main() {

    enqueue(5, 4);
    enqueue(7, 0);
    enqueue(15, 0);
    enqueue(1, 1);

    while (front) {
        printf(" %d ->", dequeue());
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data;       // Elemandaki veri
    int priority;   // Elemanın öncelik değeri
} Element;

typedef struct {
    Element elements[MAX];  // Element tipinde 100 elemanlık dizi
    int size;              // Kuyruktaki eleman sayısı
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->size = 0;  // Kuyruğu başlatır, boyutu sıfırlar
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;  // Kuyruk boşsa 1, değilse 0 döndürür
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX;  // Kuyruk doluysa 1, değilse 0 döndürür
}

void enqueue(PriorityQueue *pq, int data, int priority) {
    // Kuyruk dolu mu kontrolü
    if (isFull(pq)) {
        printf("Queue is full!\n");
        return;
    }
    
    // Yeni element oluştur
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;
    
    // Uygun pozisyonu bul
    int i = pq->size - 1;
    // Yeni elemanın önceliğinden düşük öncelikli elemanları kaydır
    while (i >= 0 && pq->elements[i].priority < priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }
    // Yeni elemanı yerleştir
    pq->elements[i + 1] = newElement;
    pq->size++; // Boyutu artır
}

Element dequeue(PriorityQueue *pq) {
    // Kuyruk boş mu kontrolü
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    
    // En yüksek öncelikli eleman (baştaki) alınır
    Element highestPriority = pq->elements[0];
    
    // Diğer elemanları öne kaydır
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    
    pq->size--; // Boyutu azalt
    return highestPriority; // En yüksek öncelikli elemanı döndür
}


void printQueue(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

int main(void) {
    PriorityQueue pq;
    initQueue(&pq);
    
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    enqueue(&pq, 40, 3);
    
    printf("Queue after enqueuing elements:\n");
    printQueue(&pq);
    
    printf("\nDequeuing elements:\n");
    while (!isEmpty(&pq)) {
        Element e = dequeue(&pq);
        printf("Dequeued -> Data: %d, Priority: %d\n", e.data, e.priority);
    }
    
    return 0;
}

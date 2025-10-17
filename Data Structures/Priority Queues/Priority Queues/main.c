#include <stdio.h>
#include <stdlib.h>

typedef struct PriorityQueue {
    int *arr;          // Min heap dizisi
    int size;          // Mevcut öğe sayısı
    int capacity;      // Heap'in kapasitesi
} PriorityQueue;

// Heapify işlemi: Min heap yapısını korumak için düğümün aşağıya doğru yer değiştirmesini sağlar.
void heapify(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->arr[left] < pq->arr[smallest]) {
        smallest = left;
    }
    
    if (right < pq->size && pq->arr[right] < pq->arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        // Swap the values
        int temp = pq->arr[index];
        pq->arr[index] = pq->arr[smallest];
        pq->arr[smallest] = temp;

        // Recursively heapify the affected subtree
        heapify(pq, smallest);
    }
}

// Kuyruğun boyutunu artıran fonksiyon
void resize(PriorityQueue *pq) {
    pq->capacity *= 2;
    pq->arr = realloc(pq->arr, pq->capacity * sizeof(int));
}

// Enqueue (Insert) işlemi: Yeni öğeyi heap'e ekler
void enqueue(PriorityQueue *pq, int item) {
    if (pq->size == pq->capacity) {
        resize(pq); // Heap tam dolmuşsa, kapasiteyi iki katına çıkar
    }

    // Yeni öğe heap'in sonuna eklenir
    pq->arr[pq->size] = item;
    pq->size++;

    // Yeni öğenin doğru yerini bulmak için heapify işlemi yapılır
    int index = pq->size - 1;
    while (index != 0 && pq->arr[(index - 1) / 2] > pq->arr[index]) {
        // Ebeveyn ile öğeyi takasla yer değiştir
        int temp = pq->arr[index];
        pq->arr[index] = pq->arr[(index - 1) / 2];
        pq->arr[(index - 1) / 2] = temp;

        // Yeni öğenin ebeveyni ile tekrar heapify yapılır
        index = (index - 1) / 2;
    }
}

// Dequeue (Remove) işlemi: Kök öğeyi çıkarır
int dequeue(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Kök öğe çıkarılır ve en son öğe köke yerleştirilir
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;

    // Kök öğesinin doğru yerini bulmak için heapify yapılır
    heapify(pq, 0);

    return root;
}

// Kuyruğun en küçük öğesini gösterir (peek)
int peek(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pq->arr[0];
}

// Kuyruğun boş olup olmadığını kontrol etme
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Kuyruğu sıfırlama (bütün öğeleri serbest bırakma)
void reset(PriorityQueue *pq) {
    pq->size = 0;
}

// Kuyruğu yazdırma (test için)
void printQueue(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

// Min-Heap ile Priority Queue'yu başlatma
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->arr = (int *)malloc(pq->capacity * sizeof(int));
    return pq;
}

int main(void) {
    // Priority Queue oluşturma
    PriorityQueue *pq = createPriorityQueue(10);

    enqueue(pq, 10);
    enqueue(pq, 5);
    enqueue(pq, 15);
    enqueue(pq, 20);
    enqueue(pq, 2);

    printf("Priority Queue (Min Heap):\n");
    printQueue(pq);

    printf("\nPeek: %d\n", peek(pq)); // En küçük öğeyi gösterir
    printf("\nDequeue: %d\n", dequeue(pq)); // En küçük öğeyi çıkarır

    printf("\nPriority Queue after dequeue:\n");
    printQueue(pq);

    // Kuyruğu sıfırlama
    reset(pq);
    printf("\nPriority Queue after reset:\n");
    printQueue(pq); // Kuyruk boş olmalı

    // Belleği serbest bırakma
    free(pq->arr);
    free(pq);

    return 0;
}


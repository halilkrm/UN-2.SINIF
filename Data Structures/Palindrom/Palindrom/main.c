
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

// Global değişkenler
char stack[MAX];  // Yığın (Stack) için dizi
int top = -1;     // Stack'in tepe elemanını gösterir

char queue[MAX];  // Kuyruk (Queue) için dizi
int front = 0;    // Kuyruğun başını tutar
int rear = -1;    // Kuyruğun sonunu tutar

// Stack İşlevleri
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) { // yığının boş olup olmadığı kontrol edilir
        return stack[top--];
    }
    return '\0'; // yığın boşsa bu yapılır
}

// Queue İşlevleri
void enqueue(char c) {
    if (rear < MAX - 1) {
        queue[++rear] = c; // ekliyoruz sonu arttırdık
    }
}

char dequeue() {
    if (front <= rear) {
        return queue[front++]; // çıkaracaz baştakini cıkardık
    }
    return '\0';
}

// Palindrome kontrol fonksiyonu
bool isPalindrome(char *str) {
    int len = strlen(str);

    // Kuyruk ve yığınları temizle
    top = -1;       // Stack boş
    front = 0;      // Queue başlangıcı
    rear = -1;      // Queue sonu

    // Adım 1: Karakterleri yığına ve kuyruğa ekle
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) { // Sadece harf ve rakamları kontrol et
            char c = tolower(str[i]); // Küçük harfe çevir
            enqueue(c);
            push(c);
        }
    }

    // Adım 2: Kuyruk ve yığından karşılaştırma yap
    bool charactersAreEqual = true;
    while (front <= rear && charactersAreEqual) {
        if (dequeue() != pop()) {
            charactersAreEqual = false; // Eşleşmeyen karakter bulundu
        }
    }

    return charactersAreEqual;
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin); // Kullanıcıdan string al
    str[strcspn(str, "\n")] = '\0'; // Yeni satır karakterini kaldır

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

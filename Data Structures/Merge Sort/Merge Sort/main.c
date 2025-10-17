#include <stdio.h>

void mergesort(int D[], int left, int right);
void merge(int D[], int left, int k, int right);

int main(void) {
    int arr[10] = {12, 32, 4, 354, 64, 543, 523, 569, 608, 779};
    int n = 10;

    // Orijinal diziyi yazdırma
    printf("Orijinal dizi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // mergesort fonksiyonunu çağırarak diziyi sıralama
    mergesort(arr, 0, n - 1);

    // Sıralı diziyi yazdırma
    printf("Sıralı dizi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void mergesort(int D[], int left, int right){
    int k;
    if(left<right){
        k = (left+right)/2;
        mergesort(D, left, k);
        mergesort(D,k+1,right);
        merge(D,left,k,right);
    }
}

void merge(int D[], int left, int k, int right) {
    int i, j, l = 0;
    int M[10];

    for (i = left, j = k + 1; (i <= k) && (j <= right);) {
        if (D[i] < D[j]) {
            M[l] = D[i];
            i++;
            l++;
        } else {
            M[l] = D[j];
            j++;
            l++;
        }
    }

    while (i <= k) {
        M[l] = D[i];
        i++;
        l++;
    }
    while (j <= right) {
        M[l] = D[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++) {
        D[i] = M[l];
    }
}


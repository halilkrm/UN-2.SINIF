#include <stdio.h>

void bubbleSort(int D[],int n ){
    
    int move,k,temp;
    
    for(move=0; move<n-1;move++){
        for(k=0; k< (n-1-move);k++){
            
            if(D[k]>D[k+1]){
                temp = D[k];
                D[k]= D[k+1];
                D[k+1] = temp;
            }
        }
    }
}



int main(void) {
    int dizi[10] = {34, 7, 23, 32, 5, 62, 14, 17, 9, 3};
    int i, j, temp;

    // Bubble Sort algoritması
    for (i = 0; i < 10 - 1; i++) { // eleman sayısının bir eksiği
        for (j = 0; j < 10 - i - 1; j++) { // üsttekinin aynısı bide i'yi cıkarıyoruz
            if (dizi[j] > dizi[j + 1]) {
                // Elemanları yer değiştir
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }

    // Sıralı diziyi ekrana yazdır
    printf("Sıralı dizi: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    return 0;
}


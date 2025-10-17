// Index of the left child of node i
#include <stdio.h>
int left(int i){
   return(2*i+1);
}

// Index of the right child of node i

int right(int i){
   return(2*i+2);
}


int heap_size;   // index of the last element

void heapify(int D[], int i){
    int left_child, right_child, max, temp;
    left_child = left(i);
    right_child = right(i);
    // find the max of nodes left, right, and i
    if ((left_child <= heap_size) &&
        (D[left_child] > D[i]))
        max = left_child;
    else
        max = i;
    
    if ((right_child <= heap_size) &&
           (D[right_child] > D[max]))
             max = right_child;

    // if max is not the i th node, exchange

       if (max != i){
          temp = D[max];
          D[max]= D[i];
          D[i] = temp;
          heapify(D, max);
       }
    }
void build_heap(int D[], int n){
int i;
heap_size = n-1;

for (i = (n-1)/2; i >= 0; i--)
   heapify(D,i);
}

void heapsort(int D[], int n){
   int i, temp;
   build_heap(D,n);
   for (i = n-1; i >= 1; i--){
   // exchange the root with the ith element
      temp = D[i];
      D[i] = D[0];
      D[0] = temp;
      heap_size--;
      heapify(D,0);
   }
}
int main() {
    int D[] = {4, 10, 3, 5, 1};
    int n = sizeof(D) / sizeof(D[0]);

    printf("Orijinal dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", D[i]);
    }

    heapsort(D, n);

    printf("\nSıralı dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}

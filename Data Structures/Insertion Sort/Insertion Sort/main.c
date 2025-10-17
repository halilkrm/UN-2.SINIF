#include <stdio.h>
/*void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
         Move elements of arr[0..i-1],
           that are greater than key,
           to one position ahead of
           their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
*/

void insertionSort(int D[], int n){
    
    int i,k,key;
    
    for(i=1; i<n;i++){
        key = D[i];
        for(k=i-1; k>=0 && key <=D[k];k--)
            D[k+1] = D[k];
            D[k+1]=key;
        
    }
    
}

// best case O(n)
// worst case O(n'2)
int main() {
    
    int d[5]={32,543,6,86,75};
    int n =  (sizeof(d)/sizeof(d[0]));
    
    insertionSort(d, n);
    
    printf("Sıralı Dizi\n");
    for(int i = 0; i<n; i++){
        printf("%d ",d[i]);
    }
    
    return 0;
}


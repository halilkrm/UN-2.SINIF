#include <stdio.h>

int main() {
    
    int array[10] = {11,10,12,14,16,20,24,28,30,40};
    int sayi = 0;
    
    printf("Enter the num: ");
    scanf("%d",&sayi);
    int i;
    for( i = 0; i<10; i++){
        printf("%d\n",array[i]);
    }
    for( i = 0; i<10; i++){
        if(sayi == array[i]){
            sayi = 1;
            break;
        }
    }
    if(sayi == 1){
        printf("Found the num. index %d",i);
    }
    else
        printf(" did not find");
    
    return 0;
}

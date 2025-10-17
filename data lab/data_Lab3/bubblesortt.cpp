//  implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, n);
	bubbleSort(arr, n);
	printf("\n\nSorted array: \n");
	printArray(arr, n);
	return 0;
}

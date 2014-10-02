#include <stdio.h>
#include <stdlib.h>

// sort with bubble sort
void bubbleSort(int *a, int size) {
	
	int i = 0;
	int j = 0;
	int tmp = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size -1; j++) {
			if (a[j] < a[j-1]){
				tmp = a[j];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

// insertion sort
void insertionSort(int *a, int size) {

	int i = 0;
	int d = 0;
	int tmp = 0;

	for (i = 1; i < size; i++) {
		d = i;
		while (d > 0 && a[d] < a[d-1]) {
			tmp = a[d-1];
			a[d-1] = a[d];
			a[d] = tmp;
			d--;
		}
	}
}

// shell sort
void shellSort(int *a, int size) {

	int gap, i, j, tmp;

	for (gap = size/2; gap > 0; gap /= 2) {
		for (i = gap; i < size; i++) {
			for (j = i-gap; j >= 0 && a[j] > a[j+gap]; j-=gap) {
				tmp	= a[j];
				a[j] = a[j+gap];
				a[j+gap] = tmp;
			}
		}
	}
}

// binary search
int binarySearch(int *a, int size,  int target) {

	int low = 0;
	int high = size;
	int mid = 0;

	while (low <= high) {
		mid = (high + low) / 2;
		if (a[mid] < target) 
			low = low + 1;
		else if (a[mid] > target)
			high = high -1;
		else return 1;
	}

	return 0;
}

int main(void) {

	int a[] = {3,1,4,5,10,7,8};
	int size = sizeof(a)/sizeof(int);
	//bubbleSort(a, size);
	//insertionSort(a, size);
	shellSort(a, size);
	
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d\n", a[i]);

	//printf("Results of Binary Search %d\n", binarySearch(a, size, 8));

	return 0;
}

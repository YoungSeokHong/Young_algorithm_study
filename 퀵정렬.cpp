#include <stdio.h>

void Swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int Parttion(int array[], int left, int right)
{
	int pivot = array[left];
	int low = left+1;
	int high = right;
	
	while(low<=high){
		while(low<=right && array[low] > pivot){
			low++;
		}
		while(high>=(left+1) && array[high] < pivot){
			high--;
		}
		if(low <= high){
			Swap(array, low, high);
		}
	}
	Swap(array, left, high);
	
	return high;
}

void QuickSort(int array[], int left, int right)
{
	if(left<right){
		int pivot = Parttion(array, left, right);
		QuickSort(array, left, pivot-1);
		QuickSort(array, pivot+1, right);
	}
}

int main(void)
{
	int array[10] = {2, 10, 3, 1, 5, 7, 9, 8, 6, 4};
	QuickSort(array, 0, 9);
	
	for(int i=0; i<10; i++){
		printf("%d ", array[i]);
	}
}



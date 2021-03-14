#include <stdio.h>

void swap(int array[], int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int partition(int array[], int left, int right)
{
	int pivot = array[left];
	int low = right;
	int high = left+1;
	
	while(low>=high){
		while(low>=left && array[low] > pivot){
			low--;
		}
		while(high<=right && array[high] < pivot){
			high++;
		}
		if(low>=high){
			swap(array, low, high);
		}
	}
	swap(array, left, high-1);
	
	return high-1;
}

void quickSort(int array[], int left, int right)
{
	if(left<right){
		int pivot = partition(array, left, right);
		quickSort(array, left, pivot-1);
		quickSort(array, pivot+1, right);
	}
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	
	int array[n];
	for(i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}
	quickSort(array, 0, n-1);
	
	for(i=0; i<n; i++){
		printf("%d\n", array[i]);
	}
	
	return 0;
}

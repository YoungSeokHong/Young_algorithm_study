#include <stdio.h>

int n = 8;
int sorted[8];

void merge(int data[], int m, int mid, int n)
{
	int i = m;
	int j = mid + 1;
	int k = m;
	
	while(i <= mid && j  <= n){
		if(data[i] <= data[j]){
			sorted[k] = data[i];
			i++;
		} else{
			sorted[k] = data[j];
			j++;
		}
		k++;
	}
	
	if(i>mid){
		while(j<=n){
			sorted[k] = data[j];
			j++; k++;
		}
	} else{
		while(i<=n){
			sorted[k] = data[i];
			i++; k++;
		}
	}
	
	for(int t=m; t<=n; t++){
		data[t] = sorted[t];
	}
}

void mergeSort(int data[], int i, int j)
{
	if(i<j){
		int mid = (i+j)/2;
		mergeSort(data, i, mid);
		mergeSort(data, mid+1, j);
		merge(data, i, mid, j);
	}
	for(i=0; i<n; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");
}

int main(void)
{
	int i;
	int data[n] = {8, 2, 5, 1, 3, 4, 7, 6};
	
	mergeSort(data, 0, 8);
	
	for(i=0; i<n; i++){
		printf("%d ", sorted[i]);
	}
	
}

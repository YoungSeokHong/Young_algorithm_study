#include <stdio.h>

int main(void)
{
	int n, i, j, min, index, temp;
	
	scanf("%d", &n);
	int array[n];
	for(i=0; i<n; i++){
		scanf("%d", &array[i]);
	}
	
	for(i=0; i<n; i++){
		min =10001;
		for(j=i; j<n; j++){
			if(array[j]<min){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	
	for(i=0; i<n; i++){
		printf("%d\n", array[i]);
	}
}

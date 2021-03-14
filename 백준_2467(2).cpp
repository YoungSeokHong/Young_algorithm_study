#include <iostream>
#include <stdlib.h>
#define MAX 2000000000

int arr[100000];

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int beg, end, x, a, b;
	
	beg = 0;
	end = n - 1;
	
	while(beg < end)
	{
		x = arr[beg] + arr[end];
		
		if(abs(min) > abs(x)){
			min = x;
			a = arr[beg];
			b = arr[end];
		}	
		if(x > 0){
			end--;
		}else{
			beg++;
		}
	}
	

	printf("%d %d\n", a, b);
	
	return 0;
}

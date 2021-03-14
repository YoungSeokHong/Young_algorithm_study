#include <iostream>
#include <stdlib.h>
#define MAX 1000000001

int main(void)
{
	int n, i, x, beg, end, mid;
	int arr[100000];
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int a, b;
	int min = MAX;
	
	for(i=0; i<n; i++)
	{
		beg = i + 1;
		end = n - 1;

		while(beg <= end)
		{
			mid = (beg + end) / 2;
			x = arr[i] + arr[mid];
			if(abs(min) > abs(x)){
				min = x;
				a = arr[i];
				b = arr[mid];
			}		
			if(!x){
				a = arr[i];
				b = arr[mid];
				break;
			}else if(x > 0){
				if(mid > 0)end = mid - 1;
			}else{
				if(mid < n) beg = mid + 1;
			}
		}
	}
	
	printf("%d %d", a, b);
	
	return 0;
}

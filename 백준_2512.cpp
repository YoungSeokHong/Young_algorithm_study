#include <iostream>
#include <algorithm>

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int n, i, sum, avg;
	int cnt = 0, max = 0;
	int arr[10000];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &sum);
	avg = sum / 4;
	
	for(i=0; i<n; i++)
	{
		if(max < arr[i]) max = arr[i];
		if(arr[i] <= avg) sum -= arr[i];
		else cnt++;
	}
	
	
	if(!cnt || cnt == n) printf("%d", max);
	else {
		printf("%d", sum / cnt);
	}
	
	return 0;
}

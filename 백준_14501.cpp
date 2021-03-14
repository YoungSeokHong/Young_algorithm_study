#include <iostream>

int arr[2][15];
int temp[15];

int dp(int n)
{
	int i, j, max;
	
	for(i=n-1; i>=0; i--)
	{
		if(i + arr[0][i] > n) continue;

		for(j=i + arr[0][i]; j<=n; j++)
		{
			max = arr[1][i] + temp[j];
			if(max > temp[i]) temp[i] = max;
		}
	}
	
	max = 0;
	for(i=0; i<n; i++)
	{
		if(temp[i] > max) max = temp[i];
	}
	return max;
}

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	
	printf("%d", dp(n));
	
	return 0;
}

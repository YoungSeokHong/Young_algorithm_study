#include <iostream>

int arr[501] = {0,};
int dp[501] = {0,};

int main(void)
{
	int n, i, j;
	
	scanf("%d", &n);
	int m = 0;
	for(i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a] = b;
		if(a > m) m = a;
	}
	
	int result = 0;
	for(i=1; i<=m; i++)
	{
		if(!arr[i]) continue;
		int max = 0;
		for(j=1; j<=i; j++)
		{
			if(arr[j] < arr[i] && dp[j] > max) max = dp[j];
		}
		dp[i] = max + 1;
		
		if(dp[i] > result) result = dp[i];
	}
	printf("%d", n - result);
	
	return 0;
}

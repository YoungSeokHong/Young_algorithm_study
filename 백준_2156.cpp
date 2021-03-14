#include <iostream>

int main(void)
{
	int n, i;
	int dp[10000][3];
	int arr[10000];
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	
	dp[0][0] = 0;
	dp[0][1] = arr[0];
	dp[0][2] = 0;
	
	for(i=1; i<n; i++)
	{
		if(dp[i - 1][0] > dp[i - 1][1]) dp[i][0] = dp[i - 1][0];
		else dp[i][0] = dp[i - 1][1];
		if(dp[i - 1][2] > dp[i][0]) dp[i][0] = dp[i - 1][2];
		
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	
	int max = 0;
	if(dp[n - 1][0] > dp[n - 1][1]) max = dp[n - 1][0];
	else max = dp[n - 1][1];
	if(dp[n - 1][2] > max) max = dp[n - 1][2];
	
	printf("%d", max);
	
	return 0;
} 

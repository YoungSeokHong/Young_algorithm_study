#include <iostream>

int coin[100] = {0,};

int dp(int n, int k)
{
	int dp[10000] = {0,};
	dp[0] = 1;
	for(int i=0; i<n; i++)
	{
		
		for(int j=coin[i]; j<=k; j++){
			if(coin[i] >= j) continue;
			dp[j] += dp[j-coin[i]];
		}
	}
	return dp[k];
}

int main(void)
{
	int n, k, i;       
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++)
	{
		scanf("%d", &coin[i]);
	}
	
	printf("%d", dp(n, k));
	return 0;
}

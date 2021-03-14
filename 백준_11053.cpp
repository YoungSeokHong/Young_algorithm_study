#include <iostream>
using namespace std;

int main(void)
{
	int n, i, j;
	int result = 0;
	int a[1000];
	int dp[1000];
	
	scanf("%d", &n);
	dp[0] = 1; 
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		
		int max = 0;
		for(j=0; j<=i; j++)
		{
			if(a[j] < a[i] && dp[j] > max) max = dp[j];
		}
		dp[i] = max + 1;
				
		if(dp[i] > result) result = dp[i];
	}
	
	printf("%d", result);
	
	return 0;
}

#include <iostream>

#define MOD 9901

int main(void)
{
	int n, i;
	int arr[100000][3];
	
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[0][2] = 1;
	
	scanf("%d", &n);
	for(i=1; i<n; i++)
	{
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % MOD;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % MOD;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % MOD;
	}
	
	printf("%d", (arr[n - 1][0] + arr[n - 1][1] + arr[n - 1][2])%MOD);
	
	return 0;
}


